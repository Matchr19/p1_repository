#include <iostream>
#include <ros/ros.h>
#include <stdlib.h>



int main(void) 
{
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
// RÆKKEFØLGEN HER ER VIGTIG                                                 /////////////////////////////////////////////////
// 1. Lav en char der siger: åben ny gnome-terminal og kør minimal.launch    /////////////////////////////////////////////////
// 2. Få terminalen til at køre hvad char siger                              /////////////////////////////////////////////////
// 3. Få første terminal til at køre activate.launch                         /////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
    const char *cmd = "gnome-terminal -x sh -c \"roslaunch kobuki_auto_docking minimal.launch --screen\"";

    system(cmd);

    system("roslaunch kobuki_auto_docking activate.launch --screen");
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    

    return 0;
}

