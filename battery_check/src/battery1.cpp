#include <iostream>
#include <ros/ros.h>
#include <kobuki_msgs/SensorState.h>
#include <std_msgs/String.h>



 void batteryCallback(const kobuki_msgs::SensorState& msg)
  {
    
    double batt = msg.battery*1;
    std::cout << "\nBatteri: " << batt << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;

    //if (res < 30)                          //hvis batteriprocenten er under 70% så:
    //{
      
    //}  
  }
 
 int main(int argc, char **argv)
  {
    ros::init(argc, argv, "battery");
 
    ros::NodeHandle n;
 
    ros::Subscriber sub = n.subscribe("/mobile_base/sensors/core", 10, batteryCallback);
  
    //ros::Publisher lav_batteri_pub = n.advertise<std_msgs::String>("lav_batteri",1);

    //ros::Rate loop_rate(1);

    //int count = 0;

    ros::spin();

    return 0;
  }

