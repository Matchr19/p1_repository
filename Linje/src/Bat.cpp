#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <kobuki_msgs/SensorState.h>
#include <iostream>
#include <string>
#include <time.h>
void bump(const kobuki_msgs::SensorState &msg)
{

    if (msg.charger == 0)
    {
        std::cout << "Oplader ikke" << std::endl;
        
    }
    else if (msg.charger == 6)
    {
        std::cout << "Oplader fra base" << std::endl;
        
    }
    else if (msg.charger == 2)
    {
        std::cout << "Fuldt opladt" << std::endl;
        
    }
    else if (msg.charger == 4)
    {
        std::cout << "Lavt batteri" << std::endl;
        
    }
    else if (msg.charger == 5)
    {
        std::cout << "Kritisk lavt batteri" << std::endl;
        
    }

}



int main(int argc, char *argv[])
{
    ros::init(argc, argv, "bat");


    ros::NodeHandle n;
    ros::Subscriber bumper_sub = n.subscribe("/mobile_base/events/SensorState", 10, bump);

    ros::spin();

    return 0;
}