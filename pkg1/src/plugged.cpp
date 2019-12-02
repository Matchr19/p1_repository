#include <iostream>
#include <ros/ros.h>
#include <kobuki_msgs/PowerSystemEvent.h>
#include <std_msgs/String.h>


 void plugged(const kobuki_msgs::PowerSystemEvent &msg)
  {
    int plug=0;
    
    plug= msg.PLUGGED_TO_DOCKBASE;

// this function determine whether the turtlebot is plugged in to the docking station or not. If it is, it turns out some text,
// and signalize with the led's

    if (plug==1){

        std::cout << "The turtlebot is plugged in dockingstation"<< std::endl;



    }

  }
 
 int main(int argc, char **argv)
  {
  
    ros::init(argc, argv, "plugged");
 
  
    ros::NodeHandle n;
 
    ros::Subscriber recall_sub = n.subscribe("/mobile_base_nodelet_manager", 5, plugged);

    kobuki_msgs::PowerSystemEvent msg;

    ros::Rate loop_rate(10);

    while(ros::ok()){
      loop_rate.sleep();
  ros::spinOnce(); 
    }
    

     return 0;
  }