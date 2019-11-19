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
    std::string Retning {""};
    std::cout << "\n\n\n\n\n\n\n\nWhere should i go?" << std::endl;
    std::cout << "You have the following options: " << std::endl;
    std::cout << "Left" << std::endl << "Straight" << std::endl << "Right\n\n\n\n\n" << std::endl << "Input: ";
    std::cin >> Retning;
    
    std::cout << "Going " << Retning << std::endl;


    double x {};
    double y {};
    if (Retning == "Straight")
    {
        x = 0.2;
        y = 0.;
    }
    else if (Retning == "Left")
    {
        x = 0.1;
        y = 0.5;
    }
    else if (Retning == "Right")
    {
        x = 0.1;  
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
        if (bumpo == 0)
        {
            bumpertekst = " Left  bumper";
        }
        else if (bumpo == 1)
        {
            bumpertekst = " Center bumper";
        }
        else if (bumpo == 2)
        {
            bumpertekst = " Right bumper";
        }
        
        sendPub(0, 5);
        ros::spinOnce();
        





        std::cout << "\n\n\n\n\n\nWOOOOOPS you drove me into something with: " << bumpertekst << std::endl
        << "Turning around\n\n";
        
    } 
    else
    {
        drive();
        ros::spinOnce();
    }
}


int main(int argc, char *argv[])
{
    ros::init(argc, argv, "pubsub");
    srand(time(NULL));
    ros::NodeHandle n;
    ros::Rate loop_rate(0.4);
    cmd_vel_pub = n.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop", 1);
    ros::Subscriber bumperSub = n.subscribe("/mobile_base/events/bumper", 1, bump);
    while(ros::ok())
    {
    bump(bumpMsg);
    ros::spinOnce();
    loop_rate.sleep();
    }
    return 0;
}