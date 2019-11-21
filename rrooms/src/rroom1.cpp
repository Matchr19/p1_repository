#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <math.h>
#include <sstream>
#include "std_msgs/String.h"

/*
int pub(int argc, char **argv)
{
    ros::init(argc, argv, "rroom1_pub");
    ros::NodeHandle n;
    ros::Publisher roomchat_pub = n.advertise<std_msgs::String>("roomchat", 10);
    ros::Rate loop_rate(10);
    int count = 0;
    while (ros::ok())
    {
        std_msgs::String msg;
        std::stringstream ss;
        ss << "Jeg er i nærheden af laderstationen " << count;
        msg.data = ss.str();
  
        ROS_INFO("%s", msg.data.c_str());
        roomchat_pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
        ++count;
    }

    return 0;
    
}
*/

int main(int argc, char **argv)
{
const double PI = 3.14159265358979323846;

ros::init(argc, argv, "rroom1");
ros::NodeHandle n;
ros::Publisher movement_pub = n.advertise<geometry_msgs::Twist>("mobile_base/commands/velocity",1); //for sensors the value after , should be higher to get a more accurate result (queued)
ros::Rate rate(10); 

std::cout << "Kører hjem fra rum 1" << std::endl;

//turn left
ros::Time start_turn = ros::Time::now();
while(ros::Time::now() - start_turn < ros::Duration(20.0))
    {
    geometry_msgs::Twist move;
    //velocity controls
    move.angular.z = 1;             //speed value m/s
    movement_pub.publish(move);

    ros::spinOnce();
    rate.sleep();
    }

    std::cout << "Jeg er i nærheden af laderstationen" << std::endl;

    system ("rosrun docking dock");

    return 0;
}


