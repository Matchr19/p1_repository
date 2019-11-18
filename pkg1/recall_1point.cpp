#include <iostream>
#include <ros/ros.h>
#include <kobuki_msgs/Buttonevent>
#include <std_msgs/String.h>


 void recallCallback(const kobuki_msgs:: msg)
  {
    buttonstate= msg.button1;

    if (buttonstate==1){

        system("roslaunch turtlebot_gmapping.launch")

    }

  }
 
 int main(int argc, char **argv)
  {
  
    ros::init(argc, argv, "recall_1point");
 
  
    ros::NodeHandle n;
 
   
    ros::Publisher Pub = n.advertise("/mobile_base_nodelet_manager", 1000, recallCallback);

  
    ros::spin();

     return 0;
  }

