#include <iostream>
#include <ros/ros.h>
#include <stdlib.h>



int main(void) 
{
///////////////////////////////////////////////////////////////////////////////////
//// HVAD SKER DER:                                                            ////
//// 1. Lav en char der siger: åben ny gnome-terminal og kør minimal.launch    ////
//// 2. Få system til at køre hvad char siger                                  ////
//// 3. Lav en char der siger: åben ny gnome-terminal og kør active.launch     ////
//// 4. Få system til at køre hvad char siger                                  ////
///////////////////////////////////////////////////////////////////////////////////   
    const char *cmd = "gnome-terminal -x sh -c \"roslaunch kobuki_auto_docking minimal.launch --screen\"";
    system(cmd);

    const char *cmde = "gnome-terminal -x sh -c \"roslaunch kobuki_auto_docking activate.launch --screen\"";
    system(cmde);

///////////////////////////////////////////////////////////////////////////////////
//// NÅR VI BLIVER FÆRDIGE MED KODNING                                         ////
//// 1. minimal.launch skal køre i den store launchfil vi laver                ////
//// 2. Kør kun activ.launch, da denne selv lukker efter docking               ////
///////////////////////////////////////////////////////////////////////////////////    

    return 0;
}

