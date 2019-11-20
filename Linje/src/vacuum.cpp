#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <kobuki_msgs/BumperEvent.h>
#include <iostream>
#include <string>

kobuki_msgs::BumperEvent bumpMsg;
ros::Publisher cmd_vel_pub;
void sendPub(double ligeud, double drej)
{
}

void drive()
{
    geometry_msgs::Twist msg;
    double x{};
    double y{};
    int drivenumb = rand() % 3;
    if (drivenumb == 0)
    {
        x = 0.15;
        y = 0;
    }
    else if (drivenumb == 1)
    {
        x = 0.1;
        y = 0.3;
    }
    else if (drivenumb == 2)
    {
        x = 0.1;
        y = -0.3;
    }
    msg.linear.x = x;
    msg.angular.z = y;
    std::cout << "Linear: "
              << msg.linear.x << " "
              << "Angular: " << msg.angular.z << std::endl;
    cmd_vel_pub.publish(msg);
}

void bump(const kobuki_msgs::BumperEvent &bumpMsg)
{
    if (bumpMsg.state == 1)
    {
        geometry_msgs::Twist msg;
        int bumpo = bumpMsg.bumper;
        std::string bumpertekst("");
        std::cout << "JEG ER KØRT IND I NOGET med:" << std::endl;
        msg.linear.x = 0.0;
        msg.angular.z = 10.0;
        std::cout << "Linear: "
                  << msg.linear.x << " "
                  << "Angular: " << msg.angular.z << std::endl;
        cmd_vel_pub.publish(msg);
        ros::Duration(1.0).sleep();
    }
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "pubsub");
    srand(time(NULL));
    ros::NodeHandle n;
    cmd_vel_pub = n.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop", 1);
    ros::Subscriber bumperSub = n.subscribe("/mobile_base/events/bumper", 1, bump);
    while (ros::ok())
    {
        drive();
        ros::Duration(0.5).sleep();
        ros::spinOnce();
    }
    return 0;
}
