#include <iostream>
#include <ros/ros.h>
#include <kobuki_msgs/SensorState.h>
#include <std_msgs/String.h>
#include <kobuki_msgs/PowerSystemEvent.h>
#include <battery_check/Msgtutorial.h>

kobuki_msgs::SensorState msg;
battery_check::Msgtutorial bat_msg;
ros::Publisher msg_pub;
  
int chargestateCallback(const kobuki_msgs::SensorState &chg)
{
  int chargingState = 0;
  chargingState = chg.charger;

  return chargingState;
}

void batteryCallback(const kobuki_msgs::SensorState &msg)
{

  double batt = msg.battery * 1;
  //std::cout << "\nBatteri: " << batt << std::endl;
  //std::cout << "-----------------------------------------------" << std::endl;

  if (chargestateCallback(msg) == 6)
  {

    //start kør mod ladestation

    while (chargestateCallback(msg) != 2)
    {
      //lad op indtil 100%
      bat_msg.data = 2;
      msg_pub.publish(bat_msg);
    }
    bat_msg.data = 1;
    msg_pub.publish(bat_msg);
    //kør ud af ladestation
  }
  bat_msg.data = 5;
  msg_pub.publish(bat_msg);
}
int main(int argc, char **argv)
{
  ros::init(argc, argv, "battery");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("/mobile_base/sensors/core", 10, batteryCallback);

  msg_pub = n.advertise<battery_check::Msgtutorial>("/batteri/info", 100);


  ros::Rate loop_rate(10);

  while (ros::ok())
  {
    loop_rate.sleep();
    ros::spinOnce();
  }

  return 0;
}
