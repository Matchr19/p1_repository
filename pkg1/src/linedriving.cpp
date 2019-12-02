#include <iostream>
#include <ros/ros.h>
#include <kobuki_msgs/ButtonEvent.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/String.h>
#include <kobuki_msgs/CliffEvent.h>


geometry_msgs::Twist msg;
ros::Publisher cmd_vel_pub;
void sendPub(double ligeud, double drej)
{
    msg.linear.x = ligeud;
    msg.angular.z = drej;
 
    cmd_vel_pub.publish(msg);
    ros::spinOnce();
}


 void drive(const kobuki_msgs::CliffEvent&msg)
  {
    
    
    //intialize of the sensor state, defining the name of the sensors
    
    int rightsensor = 0;

    int centersensor = 0;

    int leftsensor = 0; 

    //defining the sensorstate to be a messagetype
    
    leftsensor=msg.LEFT;

    centersensor=msg.CENTER;

    rightsensor=msg.RIGHT;

    //intialization of the x and y' cordinates to the drive function

    double x {};
    
    double y {};

    double z {};
    
    //these functions apply the robot to drive right,left or center whether the input sensors is activated, by different ways. 

//drive left
    if(leftsensor==1&&centersensor==1){

        x = 0.2;  
        y = -0.5;
    
    }
 
//drive center
    if(centersensor==1){

        x = 0.0;  
        y = -0.5;
    
  }

//drive right

    if(rightsensor==1&&centersensor==1){

        x = 0.2;  
        y = -0.5;
      
  }

    sendPub(x, y); 

  
  }

 int main(int argc, char **argv)
  {
  
    ros::init(argc, argv, "linedriving");
 
  
    ros::NodeHandle n;
 
    ros::Subscriber drive_sub = n.subscribe("/mobile_base/events/cliff", 5, drive);

    kobuki_msgs::CliffEvent msg;

    ros::Rate loop_rate(10);

    while(ros::ok()){
      loop_rate.sleep();
  ros::spinOnce(); 
    }
    

     return 0;
  }
  