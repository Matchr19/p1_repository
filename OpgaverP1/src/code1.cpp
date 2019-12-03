// *** Author: Group B264C ***
// *** Project: Miniproject ***
// *** Node: Approach node ***
// *** Created: 31-12-2015 ***

#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"
#include <sstream>

using namespace std;

// Creating Publisher and subscriber objects
ros::Publisher velocity_publisher;   //responsible for publishing the velocity data to the turtle1
ros::Subscriber customer_subscriber; //subscribes to the Pose message of the 'person' turtle
ros::Subscriber pose_subscriber;     //subscribes to the Pose message of the 'robot' turtle
turtlesim::Pose turtlesim_pose;
turtlesim::Pose customer_pose;

double cordy;
double cordx;

void poseCallback(const turtlesim::Pose::ConstPtr &pose_message); // callback for own Pose
void custCallback(const turtlesim::Pose::ConstPtr &cust_message); // callback for customer Pose
void moveGoal(double m1, double m2, double distance_tolerance);   // Make turtle move towards given goal
double getDistance(double x1, double y1, double x2, double y2);   // Get distance using pythagoras theorem

int main(int argc, char **argv)
{
    ros::init(argc, argv, "customer_approacher");
    ros::NodeHandle n;

    velocity_publisher = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
    pose_subscriber = n.subscribe("/turtle1/pose", 10, poseCallback);
    customer_subscriber = n.subscribe("Miniproject/Customer", 10, custCallback);
    ros::Publisher pub = n.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);

    // Seeding the random number generator with starting value using time at given second
    srand(time(0));

    ros::Rate rate(100);

    if (ros::ok())
    {
        do
        {

            geometry_msgs::Twist msg;
            msg.linear.x = 2;
            msg.angular.z = 5 * double(rand()) / double(RAND_MAX) - 2; //sets a random angular velocity

            if (turtlesim_pose.x > 10 || turtlesim_pose.x < 1 || turtlesim_pose.y > 10 || turtlesim_pose.y < 1)
            {
                //boundaries of the cage the turtle can randomly walk in
                msg.linear.x = 4;
                msg.angular.z = 10;
            }
            while (ros::ok())
                ;
        }
    }
    for (int sth = 23; ros::ok(); sth++)
    {
        geometry_msgs::Twist msg;
        msg.linear.x = 2;
        msg.angular.z = 5 * double(rand()) / double(RAND_MAX) - 2; //sets a random angular velocity
        if (turtlesim_pose.x > 10 || turtlesim_pose.x < 1 || turtlesim_pose.y > 10 || turtlesim_pose.y < 1)
        { //boundaries
            of the cage the turtle can randomly walk in
                msg.linear.x = 4;
            msg.angular.z = 10;
        }
        while (ros::ok())
        {
            geometry_msgs::Twist msg;


            msg.linear.x = 2;
            msg.angular.z = 5 * double(rand()) / double(RAND_MAX) - 2; //sets a random angular velocity


            if (turtlesim_pose.x > 10 || turtlesim_pose.x < 1 || turtlesim_pose.y > 10 || turtlesim_pose.y < 1)
            { //boundaries
                of the cage the turtle can randomly walk in
                    msg.linear.x = 4;
                msg.angular.z = 10;
            }
            pub.publish(msg);
            rate.sleep();
            ros::spinOnce();
        }
        return 0;
    }


    void poseCallback(const turtlesim::Pose::ConstPtr &pose_message)
    {
        turtlesim_pose.x = pose_message->x;
        turtlesim_pose.y = pose_message->y;
        turtlesim_pose.theta = pose_message->theta;
    } //storing the pose values for later use.


    void moveGoal(double m1, double m2, double distance_tolerance)
    {
        geometry_msgs::Twist vel_msg;
        ros::Rate loop_rate(10);
        do
        {
            // The linear velocity gets gradually smaller and smaller as the distance decreases
            vel_msg.linear.x = getDistance(turtlesim_pose.x, turtlesim_pose.y, m1, m2);
            // We use a tan^-1 linear velocity using the difference of the new and old y and x coordinates to steer the
            turtle to goal position
                vel_msg.angular.z = 4 * (atan2(m2 - turtlesim_pose.y, m1 - turtlesim_pose.x) - turtlesim_pose.theta);
            velocity_publisher.publish(vel_msg);
            ros::spinOnce();
            loop_rate.sleep();
            // while the distance is greater then the distance we want the turtle to stop (distance_tolerance), the
            turtle is going to move towards its position
        } while (getDistance(turtlesim_pose.x, turtlesim_pose.y, m1, m2) > distance_tolerance);

        vel_msg.linear.x = 0;
        vel_msg.angular.z = 0;
        velocity_publisher.publish(vel_msg);
    }
    // Making a distance function using pythagoras theorem


    double getDistance(double x1, double y1, double x2, double y2)
    {
        return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    }
    // Callback function to get the Pose of the turtle


    void custCallback(const turtlesim::Pose::ConstPtr &cust_message)
    {
        cordx = cust_message->x;
        cordy = cust_message->y;
        ros::Rate loop_rate(0.5);
        moveGoal(cordx, cordy, 1.49);
        loop_rate.sleep();
        ros::spin();
    }