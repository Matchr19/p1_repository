#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <math.h>

int main(int argc, char **argv)
{
//const double PI = 3.14159265358979323846;


ros::init(argc, argv, "battery1");
ros::NodeHandle n;
ros::Publisher movement_pub = n.advertise<geometry_msgs::Twist>("mobile_base/commands/velocity",1); //for sensors the value after , should be higher to get a more accurate result (queued)
ros::Rate rate(10); 

//turn right
ros::Time start = ros::Time::now();
while(ros::Time::now() - start < ros::Duration(1.0))
{
    geometry_msgs::Twist move;
    //velocity controls
    move.linear.x = -0.1; //speed value m/s
    movement_pub.publish(move);

    ros::spinOnce();
    rate.sleep();
}

return 0;
}