#include <ros/ros.h>
#include <std_msgs/String.h>
#include <iostream>

int x;

void lav_batteriCallback(const std_msgs::String::ConstPtr& msg)

{
    std::cout << "I heard:" << msg->data.c_str() << std::endl;

    

}



void sendbatteribesked(const std_msgs::String::ConstPtr& msg)

{
    if (x == 1){

        //kør array tilbage til ladestation


    }

    else {
        //kør array normalt
    }

    

}

int main(int argc, char **argv)
{

    ros::init(argc,argv,"subba");

    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("lav_batteri", 1, lav_batteriCallback);

    ros::spin();

    return 0;

}
