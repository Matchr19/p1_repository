#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <math.h>

int main(int argc, char **argv)
{

ros::init(argc, argv, "room2");
ros::NodeHandle n;
ros::Publisher movement_pub = n.advertise<geometry_msgs::Twist>("mobile_base/commands/velocity",1); //for sensors the value after , should be higher to get a more accurate result (queued)
ros::Rate rate(10); 
ros::Time start= ros::Time::now();

std::cout << "Kører ud af ladestationen" << std::endl;


while(ros::Time::now() - start < ros::Duration(3))
{
    geometry_msgs::Twist move;
    //velocity controls
    move.linear.x = 0.2; //speed value m/s
    move.angular.z = 0.0;
    movement_pub.publish(move);

    ros::spinOnce();
    rate.sleep();
}


return 0;
}
