#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <math.h>

int main(int argc, char **argv)
{

ros::init(argc, argv, "room2");
ros::NodeHandle n;
ros::Publisher movement_pub = n.advertise<geometry_msgs::Twist>("mobile_base/commands/velocity",1); //for sensors the value after , should be higher to get a more accurate result (queued)
std::cout << "Kører ud af ladestationen" << std::endl;

    ros::Time instantly(0);
    ros::Duration three_seconds(3.0);

    geometry_msgs::Twist move;
    move.linear.x = -0.2; //speed value m/s
    move.angular.z = 0.0;
    movement_pub.publish(move);

    ros::spinOnce();

return 0;
}
