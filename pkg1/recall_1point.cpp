#include <iostream>
#include <ros/ros.h>
#include <kobuki_msgs/ButtonEvent.h>
#include <std_msgs/String.h>


 void recallCallback(const kobuki_msgs:: ButtonEvent &msg)
  {
    int buttonstate=0;
    
    buttonstate= msg.Button1;

    //This funktion opens busroute, in addition to recall the robot to the basis point from the picked point

    if (buttonstate==1){

        std::cout << "The button is on"<< std::endl;


        system("");

    }

  }
 
 int main(int argc, char **argv)
  {
  
    ros::init(argc, argv, "recall_1point");
 
  
    ros::NodeHandle n;
 
    ros::Publisher cmd_vel_pub = n.advertise<kobuki_msgs::ButtonEvent>("/mobile_base_nodelet_manager", 100);

    kobuki_msgs::ButtonEvent msg;

    ros::Rate loop_rate(10);

     return 0;
  }

