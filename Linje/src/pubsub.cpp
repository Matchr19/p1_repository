#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <kobuki_msgs/BumperEvent.h>
#include <iostream>
#include <string>

geometry_msgs::Twist msg;
kobuki_msgs::BumperEvent bumpMsg;
ros::Publisher cmd_vel_pub;

void drive()
{
    int drivenumb = rand() % 3;
    if (drivenumb == 0)
    {
        msg.linear.x = 0.2;
        msg.angular.z = 0;
    }
    else if (drivenumb == 1)
    {
        msg.linear.x = 0;
        msg.angular.z = 0.5;
    }
    else if (drivenumb == 2)
    {
        msg.linear.x = 0;
        msg.angular.z = -0.5;
    }

    std::cout << "Linear: " << msg.linear.x << " "
              << "Angular: " << msg.angular.z << std::endl;
      cmd_vel_pub.publish(msg);      

}

void bump(const kobuki_msgs::BumperEvent &bumpMsg)
{

    if (bumpMsg.state == 1)
    {
        int bumpo = bumpMsg.bumper;
        std::string bumpertekst("");
        if (bumpo == 0)
        {
            bumpertekst = " Left  bumper";
        }
        else if (bumpo == 1)
        {
            bumpertekst = " Center bumper";
        }
        else if (bumpo == 2)
        {
            bumpertekst = " Right bumper";
        }
        msg.linear.x = 0;
        msg.angular.z = 10;
        cmd_vel_pub.publish(msg);





        std::cout << "JEG ER KØRT IND I NOGET med:" << bumpertekst << std::endl;
        
    }
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "pubsub");
    srand(time(NULL));
    ros::NodeHandle n;
    ros::Rate loop_rate(0.4);
    ros::Publisher cmd_vel_pub = n.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop", 5);
    ros::Subscriber bumperSub = n.subscribe("/mobile_base/events/bumper", 1, bump);
    
    
    return 0;
}