#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <kobuki_msgs/BumperEvent.h>
#include <iostream>
#include <string>

geometry_msgs::Twist msg;
kobuki_msgs::BumperEvent bumpMsg;
ros::Publisher cmd_vel_pub;
void sendPub(double ligeud, double drej)
{
    msg.linear.x = ligeud;
    msg.angular.z = drej;
    std::cout << "Linear: " 
    << msg.linear.x << " "
    << "Angular: " << msg.angular.z << std::endl;
    cmd_vel_pub.publish(msg);
}

void drive()
{

    double x {};
    double y {};
    int drivenumb = rand() % 3;
    if (drivenumb == 0)
    {
        x = 0.5;
        y = 0;
    }
    else if (drivenumb == 1)
    {
        x = 0.2;
        y = 0.5;
    }
    else if (drivenumb == 2)
    {
        x = 0.2;  
        y = -0.5;
    }
    
    sendPub(x, y);   
        

}

void bump(const kobuki_msgs::BumperEvent &bumpMsg)
{
    if (bumpMsg.state == 1)
    {
        int bumpo = bumpMsg.bumper;
        std::string bumpertekst("");
       
        
        sendPub(0, 10);
        std::cout << "JEG ER KØRT IND I NOGET med:" << std::endl;
        
    } 
    else
    {
        drive();
        
    }
}


int main(int argc, char *argv[])
{ 
    ros::init(argc, argv, "pubsub");
    srand(time(NULL));
    ros::NodeHandle n;
    ros::Rate loop_rate(0.4);
    cmd_vel_pub = n.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop", 1);
    ros::Subscriber bumperSub = n.subscribe("/mobile_base/events/bumper", 5, bump);
    while(ros::ok())
    {
    std::cout << "Jeg er kommet ind i loopet" << std::endl;
    bump(bumpMsg);
    loop_rate.sleep();
    }
    return 0;
}
