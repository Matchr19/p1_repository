//når der bruges rosnode kill kan man ikke bruge respawn i en roslaunch

#include <iostream>
#include <ros/ros.h>
#include <kobuki_msgs/SensorState.h>
#include <std_msgs/String.h>



 void batteryCallback(const kobuki_msgs::SensorState& msg)
  {
    float bat = msg.battery/10.0;          //batteriets spænding i V
    int ska = 100.0/3.3;                   //skalar for %-udregningen
    float ver = bat-13.0;                  //værdi for batteriets kapacitet hvis 13v er 0%
    float res = ska*ver;                   //resultatet for udregningen
    std::string rum = "lige";              //funktionen der skal subscribe på hvor den skal hen
    std::cout << std::endl;
    std::cout << "Batteri: " << res << "%" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;

    if (res < 85)                          //hvis batteriprocenten er under 70% så:
    {
      system("rosnode kill room1");        //stopper cpp'en "room1"
      system("rosrun rrooms rroom1");      //starter cpp'en "rroom1"
    }
  }
 
 int main(int argc, char **argv)
  {
  
    ros::init(argc, argv, "battery");
 
  
    ros::NodeHandle n;
 
   
    ros::Subscriber sub = n.subscribe("/mobile_base/sensors/core", 10, batteryCallback);

  
    ros::spin();

    return 0;
  }

