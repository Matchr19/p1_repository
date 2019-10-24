#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "Turtleroundweeee");

    ros::NodeHandle n;
    ros::Publisher cmd_vel_pub = n.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop", 1);

    geometry_msgs::Twist cmd_vel_message;
    cmd_vel_message.angular.z = 0.2;
    cmd_vel_message.linear.x = 0.5; 

    ros::Rate loop_rate(10);
    while(ros::ok())
    {
        cmd_vel_pub.publish(cmd_vel_message);
        loop_rate.sleep();
        cmd_vel_message.angular.z = cmd_vel_message.angular.z;
        cmd_vel_message.linear.x = cmd_vel_message.linear.x;
    }
    return 0;
} 