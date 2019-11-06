#include <iostream>
#include <actionlib>

using namespace std;

// Create the client
  actionlib::SimpleActionClient<kobuki_msgs::AutoDockingAction> docking_ac("dock_drive_action", true);
  docking_ac.waitForServer();

  // Create goal object
  kobuki_msgs::AutoDockingGoal goal;

  // Assign initial state
  actionlib::SimpleClientGoalState dock_state = actionlib::SimpleClientGoalState::LOST;

  // Send the goal
  docking_ac.sendGoal(goal);

  ros::Time time = ros::Time::now();

  // Monitor progress
  while (!docking_ac.waitForResult(ros::Duration(3))) {

    dock_state = docking_ac.getState();
    ROS_INFO("Docking status: %s",dock_state.toString().c_str());

    if (ros::Time::now() > (time+ros::Duration(10))) {
      ROS_INFO("Docking took more than 10 seconds, canceling.");
      docking_ac.cancelGoal();
      break;
    }// end if
  }// end while