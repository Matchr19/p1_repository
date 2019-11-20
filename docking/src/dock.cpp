#include <iostream>
#include <ros/ros.h>

//Subscribe på rroom1, rroom2 og rroom3. Når DONE-besked kommer kør:

int main()
{
    system("roslaunch kobuki_auto_docking minimal.launch --screen");
    system("roslaunch kobuki_auto_docking activate.launch --screen");

    return 0;
}
