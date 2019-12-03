//når der bruges rosnode kill kan man ikke bruge respawn i en roslaunch

#include <iostream>
#include <ros/ros.h>
#include <kobuki_msgs/SensorState.h>
#include <std_msgs/String.h>
#include <battery_check/Msgtutorial.h>

  ros::Publisher batteribesked;

  void sendbatteribesked()
  {
    battery_check::Msgtutorial msg;
    msg.data = 1;
    batteribesked.publish(msg);
    ros::spinOnce();
  }

 void batteryCallback(const kobuki_msgs::SensorState& msg)
  {
    float bat = msg.battery/10.0;          //batteriets spænding i V
    float ska = 100.0/3.3;                 //skalar for %-udregningen
    float ver = bat-13.0;                  //værdi for batteriets kapacitet hvis 13v er 0%
    float res = ska*ver;                   //resultatet for udregningen
    std::cout << "\nBatteri: " << res << "%" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;

    if (res < 30)                          //hvis batteriprocenten er under 70% så:
    {
      ver == 0;


      float bat = msg.battery/10.0;          
      float ska = 100.0/3.3;                 
      float der = bat-13.0;                  
      float des = ska*der;                  
      std::cout << "\nBatteri: " << des << "%" << std::endl;
      std::cout << "-----------------------------------------------" << std::endl;

      if (des == 100)

      {
        //kør ud af ladestationen
      }

      battery_check::Msgtutorial msg;
      msg.data == 2;



    
      ros::shutdown(msg.battery)

       
      
      sendbatteribesked;
      

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

    
    }  
  }
 
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