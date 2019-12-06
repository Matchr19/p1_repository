#include <iostream>
#include <ros/ros.h>
#include <kobuki_msgs/SensorState.h>
#include <std_msgs/String.h>
#include <kobuki_msgs/PowerSystemEvent.h>
#include <geometry_msgs/Twist.h>
#include <math.h> 
#include <sstream>

int hiLo = 0;                               //hiLo er tallet vi publisher til sidst

kobuki_msgs::SensorState msg;

int chargestateCallback(const kobuki_msgs::SensorState & chg)
{                  
    
    int chargingState=0;
    chargingState = chg.charger;

    return chargingState;
}

void batteryCallback(const kobuki_msgs::SensorState & msg)
{
    float batt = msg.battery;                           //batt er batteriets spænding i dV
    
    if(chargestateCallback(msg) == 2)                   //2 betyder fuldopladt
    {
        hiLo = 0;                           //0 betyder vent
        //KØR 5 CM BAGUD (Christian laver en kort kode til dette)
        
    }

    else if (chargestateCallback(msg) == 0)             //0 betyder den ikke lader
    {
        
        if(batt < 145)                      //når spændingen er under 135 dV
        {
            
            hiLo = 1;                       //1 betyder kør til dock

        }

        else if(batt >= 145)                //når spændingen er over eller lige med 135 dV
        {

            hiLo = 2;                       //2 betyder alt er okay
            
        }
        
    }

    else                                    //hvis den ikke er 0 eller 2/hvis den ikke er fuldopladt eller ikke er uden for laderen
    {
        hiLo = 0;
        //for at den ikke bliver ved med at have docking kørende når den forlader
        //kør følgende én gang:
        //system (rosnode kill kobuki_auto_docking activate.launch)
        //system (rosnode kill kobuki_auto_docking minimal.launch)
    }

}
 
int main(int argc, char **argv)
{
    ros::init(argc, argv, "battery");
 
    ros::NodeHandle n;
 
    ros::Subscriber sub = n.subscribe("/mobile_base/sensors/core", 10, batteryCallback);

    ros::Publisher battery_pub = n.advertise<std_msgs::String>("lav_batteri",1);

    kobuki_msgs::PowerSystemEvent msg;

    ros::Rate loop_rate(1);

/////// KODE FOR AT KØRE 5 CM BAGUD ///////////////////////////////////////////////
    
///////////////////////////////////////////////////////////////////////////////////

    while (ros::ok())
    {
    std_msgs::String msg;

    std::stringstream ss;
    ss << hiLo;                                   //vi publisher hvad hiLo er (0, 1 eller 2)
    msg.data = ss.str();
   
    std::cout << msg.data.c_str() << std::endl;

    battery_pub.publish(msg); 

    ros::spinOnce();

    loop_rate.sleep();
    }

/*
    while(ros::ok()){
    loop_rate.sleep();
    ros::spinOnce(); 
    }
*/

    return 0;
}

  
