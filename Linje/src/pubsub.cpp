#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <kobuki_msgs/BumperEvent.h>
#include <iostream>
#include <string>

void bump(const kobuki_msgs::BumperEvent &msg_sub)
{
    if (msg_sub.state == 1)
    {
        int bumpo = msg_sub.bumper;
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

        std::cout << "JEG ER KØRT IND I NOGET med:" << bumpertekst << std::endl;
    }
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "pubsub");
    srand(time(NULL));
    ros::NodeHandle n;
    ros::Rate loop_rate(0.4);

    ros::Publisher cmd_vel_pub = n.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop", 1);
    ros::Subscriber bumper_sub = n.subscribe("/mobile_base/events/bumper", 10, bump);
    geometry_msgs::Twist msg;
    while (ros::ok())
    {
        

        int drivenumb = rand() % 3;
        if (drivenumb == 0)
        {
            msg.linear.x = 0;
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
        cmd_vel_pub.publish(msg);

        std::cout << "Linear: " << msg.linear.x << " "
                  << "Angular: " << msg.angular.z << std::endl;
        loop_rate.sleep();
        ros::spin();
    }
    return 0;
}