#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <math.h>

int main(int argc, char **argv)
{
const double PI = 3.14159265358979323846;

ros::init(argc, argv, "room3");
ros::NodeHandle n;
ros::Publisher movement_pub = n.advertise<geometry_msgs::Twist>("mobile_base/commands/velocity",1); //for sensors the value after , should be higher to get a more accurate result (queued)
ros::Rate rate(10); //the larger the value, the "smoother" , try value of 1 to see "jerk" movement

std::cout << "Kører til rum 3" << std::endl;

//turn right
ros::Time start_turn = ros::Time::now();
while(ros::Time::now() - start_turn < ros::Duration(20.0))
{
    geometry_msgs::Twist move;
    //velocity controls
    move.linear.x = 0; //speed value m/s
    move.angular.z = -7;
    movement_pub.publish(move);

    ros::spinOnce();
    rate.sleep();
}


return 0;
}