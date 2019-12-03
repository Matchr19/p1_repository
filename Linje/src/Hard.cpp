#include <ros/ros.h>
#include <vector>
#include <geometry_msgs/Twist.h>
#include <iostream>

void drive1(int rutenummer);
int rute[] {1, 1, 2, 1, 3, 1, 2, 1, 2, 1, 1};
ros::Publisher drive_pub;
geometry_msgs::Twist msg;

void drive1(int rutenummer)
{
    ros::Rate loop_rate(0.4);
    for (int i{0}; i < sizeof(rute); i++)
    {
        switch(rute[i])
        {

        case 1:
        {
            msg.linear.x = 2;
            msg.angular.z = 0;
        }
        case 2:
        {

            msg.linear.x = 0;
            msg.angular.z = 2;
        }
        case 3:
        {
            msg.linear.x = 0;
            msg.angular.z = -2; 
        }
        }
    drive_pub.publish(msg);
    loop_rate.sleep();
    
    std::cout << "Publishing " << msg.linear.x << " & " << msg.angular.z << std::endl;    
    }
}

int main(int argc, char *argv[])
{

    ros::init(argc, argv, "Hard");
    ros::NodeHandle n;
    drive_pub = n.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop", 1);
    drive1(1);

    return 0;
}