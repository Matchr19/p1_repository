#include <iostream>
#include <ros/ros.h>
#include <kobuki_msgs/ButtonEvent.h>
#include <std_msgs/String.h>


 void recallCallback(const kobuki_msgs::ButtonEvent &msg)
  {
    int buttonstate=0;
    
    buttonstate= msg.Button1;

    //This funktion opens busroute, in addition to recall the robot to the basis point from the picked point

    if (buttonstate==1){

        std::cout << "The button is on"<< std::endl;


        system("rosrun rooms room1");

    }

  }
 
 int main(int argc, char **argv)
  {
  
    ros::init(argc, argv, "recall_1point");
 
  
    ros::NodeHandle n;
 
    ros::Subscriber recall_sub = n.subscribe("/mobile_base/events/button", 5, recallCallback);

    kobuki_msgs::ButtonEvent msg;

    ros::Rate loop_rate(10);

    while(ros::ok()){
      loop_rate.sleep();
  ros::spinOnce(); 
    }
    

     return 0;
  }

