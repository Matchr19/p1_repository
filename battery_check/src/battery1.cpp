#include <iostream>
#include <ros/ros.h>
#include <kobuki_msgs/SensorState.h>
#include <std_msgs/String.h>
#include <kobuki_msgs/PowerSystemEvent.h>
#include <geometry_msgs/Twist.h>
#include <math.h> 
#include <sstream>

int hiLo = 0;

kobuki_msgs::SensorState msg;

int chargestateCallback(const kobuki_msgs::SensorState & chg)
{
    int chargingState=0;                        //prøv og fjern
    chargingState = chg.charger;

    return chargingState;
}

int batteryCallback(const kobuki_msgs::SensorState & msg)
{
    
    double batt = msg.battery*1;

    //if (chargestateCallback(msg) == 6)
    //{
        if(chargestateCallback(msg) == 2)
        {
            ros::Time start_turn = ros::Time::now();
            ros::Rate rate(10);
            while(ros::Time::now() - start_turn < ros::Duration(2))
            {
                geometry_msgs::Twist move;
                move.linear.x = -0.2; 
                ros::spinOnce();                //prøv og fjern
                rate.sleep();
            }
        }
    //}


    else if (chargestateCallback(msg) == 0)
    {
        if(batt < 135)
        {
            //publish besked "1" (eller true) som læses af navigation.cpp
            //oversættes til KØR TIL DOCKING STATION i navigation.cpp
            
            hiLo = +1;

            //std::cout << "Lav spænding" << std::endl;
        }

        else if(batt >= 135)
        {
            //publish besked "2" (eller false) som læses af navigation.cpp
            //oversættes til ALT ER FINT i navigation.cpp

            hiLo = +2;

            //std::cout << "Høj spænding" << std::endl;
        }
    }

    return hiLo;
}
 
 int main(int argc, char **argv)
    {
    ros::init(argc, argv, "battery");
 
    ros::NodeHandle n;
 
    ros::Subscriber sub = n.subscribe("/mobile_base/sensors/core", 10, batteryCallback);

    ros::Publisher battery_pub = n.advertise<std_msgs::String>("lav_batteri",1);

    kobuki_msgs::PowerSystemEvent msg;

    ros::Rate loop_rate(10);



    while (ros::ok())
    {
    std_msgs::String msg;

    std::stringstream ss;
    ss << hiLo;
    msg.data = ss.str();
   
    std::cout << msg.data.c_str() << std::endl;

    battery_pub.publish(msg); 

    //ros::spinOnce();

    //loop_rate.sleep();
    }


    while(ros::ok()){
    loop_rate.sleep();
    ros::spinOnce(); 
    }

    std::cout << "hiLo = " << hiLo << std::endl;
    return 0;
  }

  
