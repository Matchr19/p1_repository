#include <iostream>
#include <ros/ros.h>
#include <kobuki_msgs/SensorState.h>
#include <std_msgs/String.h>


 void batteryCallback(const kobuki_msgs::SensorState& msg)
  {
    float bat = msg.battery/10.00;        //batteriets spænding i V
    int ska = 100.0/3.3;                  //skalar for %-udregningen
    float ver = bat-13.0;                 //værdi for batteriets kapacitet hvis 13v er 0%
    float res = ska*ver;                  //resultatet for udregningen
    //std::cout << "Batteri: " << bat << " volt" << std::endl;
    std::cout << std::endl;
    std::cout << "Batteri: " << res << "%" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;

    if (res < 30)                         //hvis batteriprocenten er under 30%
    {
      std::cout << "STIK MIG EN ØL" << std::endl;
    }
  }
 
 int main(int argc, char **argv)
  {
  
    ros::init(argc, argv, "battery");
 
  
    ros::NodeHandle n;
 
   
    ros::Subscriber sub = n.subscribe("/mobile_base/sensors/core", 1000, batteryCallback);

  
    ros::spin();

     return 0;
  }

