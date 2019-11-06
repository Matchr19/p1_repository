#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <kobuki_msgs/BumperEvent.h>



void bump(const kobuki_msgs::BumperEvent& msg)
{
    if(msg.state == 1)
    {
        ROS_INFO("JEG ER KØRT IND I NOGET");
    }
    ROS_INFO("JEG KØRER");
}


int main(int argc, char *argv[])
{
    ros::init(argc, argv, "test");

    ros::NodeHandle n;
    ros::Subscriber bumper_sub = n.subscribe("/mobilebase/event/bumper", 10, bump);

    ROS_INFO("JEG ER HER"); 
    ros::spin();
    
    return 0;
} 