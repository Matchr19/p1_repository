#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <kobuki_msgs/BumperEvent.h>
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "rundt");
    ros::NodeHandle n;
    ros::Publisher cmd_vel_pub = n.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop", 5);
    geometry_msgs::Twist msg;

    msg.linear.x = 0;
    msg.angular.z = -2;
    cmd_vel_pub.publish(msg);
    return 0;
}