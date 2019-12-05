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
*@file turtlebot.cpp
*@author Sudarshan Raghunathan
*@brief  Functions definitions for turtlebot class
*/

#include <geometry_msgs/Twist.h>
#include <vector>
#include "ros/ros.h"
#include "ros/console.h"
#include "turtlebot.hpp"
#include "Linefollower/pos.h"

void turtlebot::dir_sub(Linefollower::pos msg) {
    turtlebot::dir = msg.direction; //Funktion som tager msg.direction, som bliver published af linedetect.cpp og ligger i 
                                    //turtlebot::dir
}

void turtlebot::vel_cmd(geometry_msgs::Twist &velocity,
 ros::Publisher &pub, ros::Rate &rate) {
    // If direction is left
    if (turtlebot::dir == 0) { //Hvis linedetect.cpp ser at linjen kører til venstre, bliver turtlebot::dir = 0
        velocity.linear.x = 0.1; //Fortæller at variabel velocity.linear.x skal være lig 0.1
        velocity.angular.z = 0.15; //Fortæller at variabel velocity.angular.z skal være lig 0.15
        pub.publish(velocity); //Publisher beskeden velocity til pub, som er publisheren til turtlebotten
        rate.sleep(); //Pauser programmet til næste cyklus
        ROS_INFO_STREAM("Turning Left"); //Printer i terminalen at robotten kører mod venstre
    }
    // If direction is straight
    if (turtlebot::dir == 1) {//Hvis linedetect.cpp ser at linjen kører ligeud, bliver turtlebot::dir = 1
        velocity.linear.x = 0.15;//Fortæller at variabel velocity.linear.x skal være lig 0.15
        velocity.angular.z = 0; //Fortæller at variabel velocity.angular.z skal være lig 0
        pub.publish(velocity);//Publisher beskeden velocity til pub, som er publisheren til turtlebotten
        rate.sleep();//Pauser programmet til næste cyklus
        ROS_INFO_STREAM("Straight");//Printer i terminalen at robotten kører ligeud
    }
    // If direction is right
    if (turtlebot::dir == 2) {//Hvis linedetect.cpp ser at linjen kører til højre, bliver turtlebot::dir = 2
        velocity.linear.x = 0.1;//Fortæller at variabel velocity.linear.x skal være lig 0.1
        velocity.angular.z = -0.15;//Fortæller at variabel velocity.angular.z skal være lig -0.15
        pub.publish(velocity);//Publisher beskeden velocity til pub, som er publisheren til turtlebotten
        rate.sleep();//Pauser programmet til næste cyklus
        ROS_INFO_STREAM("Turning Right");//Printer i terminalen at robotten kører mod højre
    }
    // If robot has to search
    if (turtlebot::dir == 3) {//Hvis linedetect.cpp ikke kan finde en linje, bliver turtlebot.dir = 3
        velocity.linear.x = 0;//Fortæller at variabel velocity.linear.x skal være lig 0
        velocity.angular.z = 0.25;//Fortæller at variabel velocity.angular.z skal være lig 0.25
        pub.publish(velocity);//Publisher beskeden velocity til pub, som er publisheren til turtlebotten
        rate.sleep();//Pauser programmet til næste cyklus
        ROS_INFO_STREAM("Searching");//Printer i terminalen at robotten kører mod højre
    }
}
