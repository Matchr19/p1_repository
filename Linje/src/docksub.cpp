#include "ros/ros.h"
#include "linefollowertest/docking.h"

bool dockingCalled {false};
void dockcallback(const linefollowertest::docking &msg)
{
    if(msg.docking == 1)
    {
        dockingCalled = true;
    }
}


int main(int argc, char **argv)
{
    
    // Initializing node and object
    ros::init(argc, argv, "Dockdetector");
    ros::NodeHandle n;
    ros::Subscriber docksub = n.subscribe("/docking/event", 1, dockcallback);
    ros::Rate rate(1); 
    while(ros::ok())
    {
        if(dockingCalled == true)
        {
            system("rosrun docking dock");
            ros::shutdown();
            
        }
        rate.sleep();
        ros::spinOnce();


    }


    return 0;
}