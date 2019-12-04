#include <iostream>
#include <ros/ros.h>
#include <kobuki_msgs/SensorState.h>
#include <std_msgs/String.h>
#include <battery_check/Msgtutorial.h>
using namespace std;

  ros::Publisher batteribesked;

  kobuki_msgs::SensorState msg;

  int x;

  void sendbatteribesked()
  {
    battery_check::Msgtutorial msg;
    msg.data = 1;
    batteribesked.publish(msg);
    ros::spinOnce();
  }

 void batteryCallback(const kobuki_msgs::SensorState& msg)
  {
    
    double batt = msg.battery*1;
    std::cout << "\nBatteri: " << batt << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;

    if (batt < 131)                  //hvis batterispænding er under  så:
    {
       
       
         battery_check::Msgtutorial msg;
         msg.data=2; //skal bruge strøm
         batteribesked.publish(msg);
       }
       else
       {
          

    else if (batt >= 160)
    {
        //h
    }

    else if (132 <= batt)
    {
        //h
    }

  }


      //system("rosnode kill Transport");
      //system("rosrun lav_batteri);

      //have loop der tjekker procenten i lav_batteri, når den når 100%, skal de stoppe med at oplade
      //og starte system("rosrun Transport")
      
      // starte vej mod ducking station
      // ikke brug for sendbatteribesked, den skal bare starte en node, der får turtlebotten
      // til at køre mod ladestationen
      // ellers kan vi have 2 værdier for sendbatteribesked, en i funktion og en inde i if statementen
      // så en værdi der kører når den er over 30 % og en der kører når den når under 30 procent

      // sendbatteribesked, publisher i stedet for subscriber function?

    
     
  
 
 int main(int argc, char **argv)
  {
    ros::init(argc, argv, "battery");
 
    ros::NodeHandle n;
 
    ros::Subscriber sub = n.subscribe("/mobile_base/sensors/core", 10, batteryCallback);

    batteribesked = n.advertise<battery_check::Msgtutorial>("lav_batteri",1);

    ros::Rate loop_rate(1);

    int count = 0;

    ros::spin();

    return 0;
  }