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
*@file motion_node.cpp
*@author Sudarshan Raghunathan
*@brief  Ros node to read direction to move in and publish velocity to turtlebot
*/
#include <cv_bridge/cv_bridge.h>
#include <cstdlib>
#include <string>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/opencv.hpp"
#include "ros/ros.h"
#include "ros/console.h"
#include "turtlebot.hpp"
#include "Linefollower/pos.h"


/**
*@brief Main function that reads direction from the detect node and publishes velocity to the turtlebot at a given rate
*@param argc is the number of arguments of the main function
*@param argv is the array of arugments
*@return 0
*/
int main(int argc, char **argv) {
    // Initializing node and object
    ros::init(argc, argv, "Velocity"); // Starter en ROS node med navn "velocity"
    ros::NodeHandle n;
    turtlebot bot; //Laver et class objekt med navn bot. Denne class er oprettet i turtlebot.hpp
    geometry_msgs::Twist velocity; //Opretter en variabel med type geometry_msgs::Twist med navn velocity

    ros::Subscriber sub = n.subscribe("/direction", 1, &turtlebot::dir_sub, &bot); //Opretter en subscriber på topic /direction
    ros::Publisher pub = n.advertise<geometry_msgs::Twist>
        ("/cmd_vel_mux/input/teleop", 10); //Opretter en publisher som publisher til /cmd_vel_mux/input/teleop
    ros::Rate rate(10); //sætter opdateringshastighed til 10hz
    while (ros::ok()) {
        ros::spinOnce(); //Kalder callback funktionerne, her turtlebot::dir_sub, som ligger i turtlebot.cpp
      
/*
I include filen turtlebot.hpp er følgende funktion deklereret void vel_cmd(geometry_msgs::Twist &velocity, 
ros::Publisher &pub, ros::Rate &rate); 
Vi skal altså sende en besked med type geometry:msgs::Twist, en publisher og en ros::rate. 
Funktionen er i turtlebot.cpp
*/
        bot.vel_cmd(velocity, pub, rate);
        rate.sleep();//pauser programmet indtil næste cyklus
    }
    return 0;
}
