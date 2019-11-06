#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <kobuki_msgs/BumperEvent.h>
#include <iostream>
#include <string>

void stop(geometry_msgs::Twist &msg)
{

}

void bump(const kobuki_msgs::BumperEvent &msg_sub)
{

    
}



geometry_msgs::Twist drive(geometry_msgs::Twist &msg)
{
    
    int drivenumb = rand() % 3;
    if (drivenumb == 0)
    {
        msg.linear.x = 2;
        msg.angular.z = 0;
    }
    else if (drivenumb == 1)
    {
        msg.linear.x = 0;
        msg.angular.z = 2;
    }
    else if (drivenumb == 2)
    {
        msg.linear.x = 0;
        msg.angular.z = -2;
    }
    
    std::cout << "Linear: " << msg.linear.x << " " << "Angular: " << msg.angular.z << std::endl;
    return msg;
}



int main(int argc, char *argv[])
{
    ros::init(argc, argv, "pubsub");
    srand(time(NULL));
    ros::NodeHandle n;
    ros::Rate loop_rate(0.4);
    
    
    ros::Publisher cmd_vel_pub = n.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop", 1, drive);
    ros::Subscriber bumper_sub = n.subscribe("/mobile_base/events/bumper", 10, bump);
    geometry_msgs::Twist msg;
    while(ros::ok())
    {
    
    cmd_vel_pub.publish(drive(msg));
    loop_rate.sleep();
    

    }
 
    
    
    return 0;
}