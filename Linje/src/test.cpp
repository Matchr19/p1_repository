#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <kobuki_msgs/BumperEvent.h>
#include <iostream>
#include <string>
#include <time.h>
void bump(const kobuki_msgs::BumperEvent &msg)
{

    if (msg.state == 1)
    {
        int bumpo = msg.bumper;
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
    ros::init(argc, argv, "test");


    ros::NodeHandle n;
    ros::Subscriber bumper_sub = n.subscribe("/mobile_base/events/bumper", 10, bump);

    ROS_INFO("JEG ER HER");
    ros::spin();

    return 0;
}