#include <ros/ros.h>
#include <std_msgs/String.h>
#include <iostream>

void lav_batteriCallback(const std_msgs::String::ConstPtr& msg)

{
    std::cout << "I heard:" << msg->data.c_str() << std::endl;

    

}

int main(int argc, char **argv)
{

    ros::init(argc,argv,"subba");

    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("lav_batteri", 1, lav_batteriCallback);

    ros::spin();

    return 0;

}
