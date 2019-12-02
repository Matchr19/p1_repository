#include <iostream>
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>

int tal = 5;

int main(int argc, char **argv)
{

ros::init(argc, argv, "pubba");

ros::NodeHandle n;

ros::Publisher lav_batteri_pub = n.advertise<std_msgs::String>("lav_batteri",1);

ros::Rate loop_rate(1);

int count = 0;


if(tal > 3)
{

while (ros::ok())
 {
    std_msgs::String msg;

    std::stringstream ss;
    ss << "Har brug for stroem " << count;
    msg.data = ss.str();
   
    std::cout << msg.data.c_str() << std::endl;

    lav_batteri_pub.publish(msg); 

    ros::spinOnce();

    loop_rate.sleep();

    ++count;
 }
}
return 0;


 }
