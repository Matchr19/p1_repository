#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <iostream>

geometry_msgs::Twist drive(geometry_msgs::Twist &msg)
{
        msg.angular.z = 1;
    
    
    std::cout << "Jeg drejer rundt med: " << msg.angular.z << " km/t" << std::endl;
    std::cout << "Undskyld, men hvor er rum 1 henne?" << std::endl;
    return msg;
}



int main(int argc, char *argv[])
{
    ros::init(argc, argv, "room1");
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