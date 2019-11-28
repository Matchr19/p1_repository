#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Color.h>
#include <turtlesim/SetPen.h>
#include <kobuki_msgs/BumperEvent.h>

ros::Publisher cmd_vel_pub;

bool first_color_saved = false;
kobuki_msgs::BumperEvent bumpEvent;

// Callback function to handle incomming messages on the color_sensor topic.
// First the default color is saved, then the following messages are compared to
// that color. If the color is different, the robot turns.


void cbColor(kobuki_msgs::BumperEvent bumpEvent)
{
  if(!first_color_saved)
  {
    first_color_saved = true;
  }

  if( bumpEvent.state == 1)
  {
    geometry_msgs::Twist msg;
    msg.linear.x = 0.0;
    msg.angular.z = 2.0;
    cmd_vel_pub.publish(msg);
    ros::Duration(1.0).sleep();
  }
  return;
}

int main(int argc, char *argv[]) {
  ros::init(argc, argv, "move_circle");

  // Get the node handle to interact with the ROS network
  ros::NodeHandle node_handle;

  // Turn off the pen. Otherwise, the turtle will sense the color it just
  // painted.
  





    ros::Subscriber bumper_sub =
    node_handle.subscribe("/mobile_base/events/bumper", 1, cbColor);

  // Advertise to the ROS network that this node wil have velocity commands for
  // the turtle
  cmd_vel_pub =
    node_handle.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop", 10);

  // Initially the turtle is commanded to move straight.
  geometry_msgs::Twist msg;
  msg.linear.x = 0.1;
  msg.angular.z = 0.0;

  // This is where it happens. We continously send the command to the turtle and
  // sleep for 200 ms. So the commands are send to the turtle at 5 Hz. This is
  // fast enough for the "emergency brake" not to activate.
  // We allso spin the ROS event loop. This is to read any incomming messages on
  // the subscriptions. This is where the color_callback will be called if there
  // is a message for it.
  while(ros::ok())
  {
    cmd_vel_pub.publish(msg);
    ros::Duration(0.2).sleep();
    ros::spinOnce();
  }

  return 0;
}