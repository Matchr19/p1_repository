/** MIT License
Copyright (c) 2017 Sudarshan Raghunathan
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*
*
*@copyright Copyright 2017 Sudarshan Raghunathan
*@file linedetect.cpp
*@author Sudarshan Raghunathan
*@brief  Class linedetect's function definitions
*/
#include "linedetect.hpp"
#include <cv_bridge/cv_bridge.h>
#include <cstdlib>
#include <string>
#include <opencv2/highgui/highgui.hpp>
#include "ros/ros.h"
#include "opencv2/opencv.hpp"
#include "ros/console.h"
#include "Linefollower/pos.h"

void LineDetect::imageCallback(const sensor_msgs::ImageConstPtr& msg) {
  cv_bridge::CvImagePtr cv_ptr;
  try {
    cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    img = cv_ptr->image;
    cv::waitKey(30);
  }
  catch (cv_bridge::Exception& e) {
    ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
  }
}

cv::Mat LineDetect::Gauss(cv::Mat input) {
  cv::Mat output;
// Applying Gaussian Filter
  cv::GaussianBlur(input, output, cv::Size(3, 3), 0.1, 0.1);
  return output;
}

int LineDetect::colorthresh(cv::Mat input) {//typen cv::Mat, er en måde for OpenCV at lagre store vektorer såsom billeder
  // Initializaing variables
  /*
  Laver en variabel s, med typen cv::Size, som lagrer højde og bredde på en vektor.
  Størrelsen defineres som size() af input, som er vores filtrerede billede
  */
  cv::Size s = input.size(); 
/*
laver en vektor v, som er konstrueret af en vektor, som er af type cv::point. cv::point er punkter med x og y koordinater.
Så vi laver en vektor bygget op af punkter.
*/  
std::vector<std::vector<cv::Point> > v; 
/*
Vi laver nu 3 variabler w, h og c_x. w definerer vi som s.width, som er en værdi i sv::Size s; Det samme med h 
som er s.height.
c_x definerer vi som 0.0
*/
  auto w = s.width;
  auto h = s.height;
  auto c_x = 0.0;
  // Detect all objects within the HSV range

  /*
  cv::cvtColor(InputArray src, OutputArray dst, int code) konverterer et billede fra et colorspace til et andet
  Her giver vi 3 variabler:
  src – input image: 8-bit unsigned, 16-bit unsigned ( CV_16UC... ), or single-precision floating-point.
  dst – output image of the same size and depth as src.
  code – color space conversion code.
  Vi giver vores billede som input, output er LineDetect::img_hsv. Som er defineret i linedetect.hpp og med type cv::Mat
  vi konverterer til HSV, og bruger derfor CV_BGR2HSV, da vi konverterer fra BGR til HSV. Mere information her: 
  https://docs.opencv.org/2.4/modules/imgproc/doc/miscellaneous_transformations.html
  */
  cv::cvtColor(input, LineDetect::img_hsv, CV_BGR2HSV);

/*
Vi angiver nu to vektorer, med 3 værdier i hver. Både LowerYellow og UpperYellow er i linedetect.hpp defineret som
cv::Scalar variabel-typer. cv::Scalar er variabler som kan holde op til 4 værdier.
Vi bruger disse til at definere, hvilket rum indenfor HSV farverummet, vi vil beholde. 
Dette gør vi for at isolere vores gule linje.
*/
  LineDetect::LowerYellow = {20, 100, 100};
  LineDetect::UpperYellow = {30, 255, 255};

  /*
  cv::inRange tjekker om værdier i en vektor eller et array ligge indenfor to andre værdier.
  void cv::inRange(InputArray src, InputArray lowerb, InputArray upperb, OutputArray dst)
  Vi ligger vores img_hsv billede ind, som er vores billede i HSV faverummet. Vi bruger som lowerb og upperb
  vores LowerYellow og UpperYellow værdier. Vi outputter billedet i LineDetect::img_mask, som ligesom de andre billeder er 
  en cv::Mat type, og som er defineret i Linedetect.hpp.
  */
  cv::inRange(LineDetect::img_hsv, LowerYellow, UpperYellow, LineDetect::img_mask);
  
  //img_mask(cv::Rect(0, 0, w, 0.8*h)) = 0;
  // Find contours for better visualization

  /*
 
 void cv::findContours(InputOutputArray image, OutputArrayOfArrays contours, OutputArray hierarchy,
 int mode, int method, Point offset = Point())	

  Vi bruger denne funktion til at finde linjer som argrænser vores gule linje. Vi bruger vores img_mask som input
Punkterne til linjerne som bliver fundet, skal lagres i en vektor defineret som std::vector<std::vector<cv::Point> >
Derfor vi har lavet vektoren v, og denne gemmer vi disse værdier i. 
Vi bruger RETR_LIST til at få punkterne og CHAIN_APPROX_NONE for at lagre værdierne

Læs mere om disse værdier her: https://docs.opencv.org/3.4/d3/dc0/group__imgproc__shape.html#ga17ed9f5d79ae97bd4c7cf18403e1689a

  */
  cv::findContours(LineDetect::img_mask, v, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
  // If contours exist add a bounding
  // Choosing contours with maximum area
/*
Vi siger nu, at hvis der er contours, altså at der er elementer i vores vektor v, så kører vi det næste
*/

  if (v.size() != 0) {
    //Vi initialiserer 3 værdier, area, idx & count
  auto area = 0;
  auto idx = 0;
  auto count = 0;
/*
Så længe vores count værdi er mindre end størrelsen af vektoren v. Tester vi om area er mindre end størrelsen 
på count værdien i v i bytes. Hvis den er det, så bliver idx sat til count, og area til størrelsen af count værdien i v.
Derefter plusses count med 1.
*/
  while (count < v.size()) {
    if (area < v[count].size()) {
       idx = count;
       area = v[count].size();
    }
    count++;
  }
/*
Vi bruger nu funktionen boundingRect() til at udregne et rektangel ud fra punkterne i vores vektor v. 
Vi bruger kune punkterne 

*/

  cv::Rect rect = boundingRect(v[idx]);
  cv::Point pt1, pt2, pt3;
  pt1.x = rect.x;
  pt1.y = rect.y;
  pt2.x = rect.x + rect.width;
  pt2.y = rect.y + rect.height;
  pt3.x = pt1.x+5;
  pt3.y = pt1.y-5;
  // Drawing the rectangle using points obtained
  rectangle(input, pt1, pt2, CV_RGB(255, 0, 0), 2);
  // Inserting text box
  cv::putText(input, "Line Detected", pt3,
    CV_FONT_HERSHEY_COMPLEX, 1, CV_RGB(255, 0, 0));
  }
  // Mask image to limit the future turns affecting the output
  img_mask(cv::Rect(0.7*w, 0, 0.3*w, h)) = 0;
  img_mask(cv::Rect(0, 0, 0.3*w, h)) = 0;
  // Perform centroid detection of line
  cv::Moments M = cv::moments(LineDetect::img_mask);
  if (M.m00 > 0) {
    cv::Point p1(M.m10/M.m00, M.m01/M.m00);
    cv::circle(LineDetect::img_mask, p1, 5, cv::Scalar(155, 200, 0), -1);
  }
  c_x = M.m10/M.m00;
  // Tolerance to chooise directions
  auto tol = 15;
  auto count = cv::countNonZero(img_mask);
  // Turn left if centroid is to the left of the image center minus tolerance
  // Turn right if centroid is to the right of the image center plus tolerance
  // Go straight if centroid is near image center
  if (c_x < w/2-tol) {
    LineDetect::dir = 0;
  } else if (c_x > w/2+tol) {
    LineDetect::dir = 2;
  } else {
    LineDetect::dir = 1;
  }
  // Search if no line detected
  if (count == 0) {
    LineDetect::dir = 3;
  }
  // Output images viewed by the turtlebot
  cv::namedWindow("Turtlebot View");
  imshow("Turtlebot View", input);
  return LineDetect::dir;
}
