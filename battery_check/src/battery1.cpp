#include <iostream>
#include <ros/ros.h>
#include <kobuki_msgs/SensorState.h>
#include <std_msgs/String.h>
#include <kobuki_msgs/PowerSystemEvent.h>




kobuki_msgs::SensorState msg;

int chargestateCallback(const kobuki_msgs::SensorState & chg)
{
    int chargingState=0;
    chargingState = chg.charger;

    return chargingState;
}

 void batteryCallback(const kobuki_msgs::SensorState & msg)
  {
    
    double batt = msg.battery*1;
    //std::cout << "\nBatteri: " << batt << std::endl;
    //std::cout << "-----------------------------------------------" << std::endl;

    if (chargestateCallback(msg) == 6)
    {
        if(chargestateCallback(msg) == 2)
        {
            //back out of the docking base
            //back;
        }
    }

    else if (chargestateCallback(msg) == 0)
    {
        if(batt < 132)
        {
            //publish besked "1" (eller true) som læses af navigation.cpp
            //oversættes til KØR TIL DOCKING STATION i navigation.cpp
        }

        else if(batt >= 132)
        {
            //publish besked "0" (eller false) som læses af navigation.cpp
            //oversættes til ALT ER FINT i navigation.cpp
        }
    }

  }
 
 int main(int argc, char **argv)
  {
    ros::init(argc, argv, "battery");
 
    ros::NodeHandle n;
 
    ros::Subscriber sub = n.subscribe("/mobile_base/sensors/core", 10, batteryCallback);

    kobuki_msgs::PowerSystemEvent msg;

    ros::Rate loop_rate(10);

    while(ros::ok()){
    loop_rate.sleep();
    ros::spinOnce(); 
    }


    return 0;
  }

  

