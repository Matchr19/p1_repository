#include &lt;ros/ros.h&gt;
#include &lt;tf/tf.h&gt;
#include &lt;geometry_msgs/Twist.h&gt;
#include &lt;geometry_msgs/Pose2D.h&gt;
#include &lt;nav_msgs/Odometry.h&gt;
#include &lt;math.h&gt;
 
geometry_msgs::Pose2D current_pose;
ros::Publisher pub_pose2d;
 
void odomCallback(const nav_msgs::OdometryConstPtr&amp; msg)
{
    // linear position
    current_pose.x = msg-&gt;pose.pose.position.x;
    current_pose.y = msg-&gt;pose.pose.position.y;
    
    // quaternion to RPY conversion
    tf::Quaternion q(
        msg-&gt;pose.pose.orientation.x,
        msg-&gt;pose.pose.orientation.y,
        msg-&gt;pose.pose.orientation.z,
        msg-&gt;pose.pose.orientation.w);
    tf::Matrix3x3 m(q);
    double roll, pitch, yaw;
    m.getRPY(roll, pitch, yaw);
    
    // angular position
    current_pose.theta = yaw;
    pub_pose2d.publish(current_pose);
}
 
int main(int argc, char **argv)
{
    const double PI = 3.14159265358979323846;
    
    ROS_INFO("start");
    
    ros::init(argc, argv, "move_pub");
    ros::NodeHandle n;
    ros::Subscriber sub_odometry = n.subscribe("odom", 1, odomCallback);
    ros::Publisher movement_pub = n.advertise("cmd_vel",1); //for sensors the value after , should be higher to get a more accurate result (queued)
    pub_pose2d = n.advertise("turtlebot_pose2d", 1);
    ros::Rate rate(10); //the larger the value, the "smoother" , try value of 1 to see "jerk" movement
    
    //move forward
    ROS_INFO("move forward");
    ros::Time start = ros::Time::now();
    while(ros::ok() &amp;&amp; current_pose.x &lt; 1.5) { geometry_msgs::Twist move; //velocity controls move.linear.x = 0.2; //speed value m/s move.angular.z = 0; movement_pub.publish(move); ros::spinOnce(); rate.sleep(); } //turn right ROS_INFO("turn right"); ros::Time start_turn = ros::Time::now(); while(ros::ok() &amp;&amp; current_pose.theta &gt; -PI/2)
    {
        geometry_msgs::Twist move;
        //velocity controls
        move.linear.x = ; //speed value m/s
        move.angular.z = -0.3;
        movement_pub.publish(move);
    
        ros::spinOnce();
        rate.sleep();
    }
    //move forward again
    ROS_INFO("move forward");
    ros::Time start2 = ros::Time::now();
    while(ros::ok() &amp;&amp; current_pose.y &gt; -1.5)
    {
        geometry_msgs::Twist move;
        //velocity controls
        move.linear.x = 0.2; //speed value m/s
        move.angular.z = ;
        movement_pub.publish(move);
    
        ros::spinOnce();
        rate.sleep();
    }
    
    // just stop
    while(ros::ok()) {
        geometry_msgs::Twist move;
        move.linear.x = ;
        move.angular.z = ;
        movement_pub.publish(move);
    
        ros::spinOnce();
        rate.sleep();
    }
    
    return ;
}