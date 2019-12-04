#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <kobuki_msgs/BumperEvent.h>
#include <iostream>
#include <string>
#include <ros/ros.h>
#include <std_msgs/String.h>


void lav_batteriCallback(const std_msgs::String::ConstPtr& msg)

{
    std::cout << "I heard:" << msg->data.c_str() << std::endl;

}



int main(int argc, char **argv)
{

    ros::init(argc,argv,"lige");

    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("lav_batteri", 1, lav_batteriCallback);

    ros::spin();

    return 0;

}