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
 *@file   detect.cpp
 *@author Sudarshan Raghunathan
 *@brief  Ros Nod to subscribe to turtlebot images and perform image processing to detect line
 */
#include <cv_bridge/cv_bridge.h>
#include <cstdlib>
#include <string>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/opencv.hpp"
#include "ros/ros.h"
#include "ros/console.h"
#include "linedetect.hpp"
#include "Linefollower/pos.h"

/**
 *@brief Main function that reads image from the turtlebot and provides direction to move using image processing
 *@param argc is the number of arguments of the main function
 *@param argv is the array of arugments
 *@return 0
*/

int main(int argc, char **argv) {
    // Initializing node and object
    ros::init(argc, argv, "detection"); //Initialser en ros node med navn "detection"
    ros::NodeHandle n; //start nodehandle n
    LineDetect det; //laver et komponent i call LineDetect med navn "det"
    // Creating Publisher and subscriber
    ros::Subscriber sub = n.subscribe("/camera/rgb/image_raw",
        1, &LineDetect::imageCallback, &det); //Starter en publisher på image_raw, med en kø på 1, og med callback funktion 
        //imageCallback, som ligger i linedetect.cpp, med besked det. 
    ros::Publisher dirPub = n.advertise<Linefollower::pos>("direction", 1); //Starter en publisher på custom besked pos til topic "direction"
        Linefollower::pos msg; //Laver en mesked til type pos, som hedder msg.

    while (ros::ok()) {
        if (!det.img.empty()) {//hvis der er et billede i variabel det.img, kør følgende
            // Perform image processing
            /*
            Kør følgende funktion og lig det i variablen det.img_filt. 
            Prototypen til gauss() er i linedetect.hpp. Funktionen køres i linedetect.cpp
            Her ligges et gaussisk filter på billedet, som laver kontrasten om
            */
            det.img_filt = det.Gauss(det.img);
            /*
            Vi tager nu det filtrede billede, og kører den gennem colorthresh(). Igen er prototypen i linedetect.hpp,
            og funktionen i linedetect.cpp. 
            */
            msg.direction = det.colorthresh(det.img_filt);
            // Publish direction message
            dirPub.publish(msg);
            }
        ros::spinOnce();
    }
    // Closing image viewer
    cv::destroyWindow("Turtlebot View");
}
