#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <kobuki_msgs/BumperEvent.h>
#include <iostream>
#include <string>


geometry_msgs::Twist drive(geometry_msgs::Twist &msg)
{
        msg.angular.z = -4;
    
    
    std::cout << "JEG VIL HJEM!!!" << std::endl;
    return msg;
}


int main(int argc, char *argv[])
{
    ros::init(argc, argv, "ny");
    srand(time(NULL));
    ros::NodeHandle n;
    ros::Rate loop_rate(1000);
    
    
    ros::Publisher cmd_vel_pub = n.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop", 1, drive);
    geometry_msgs::Twist msg;
    while(ros::ok())
    {
    
    cmd_vel_pub.publish(drive(msg));
    loop_rate.sleep();
    

    }
 
    
    
    return 0;
}