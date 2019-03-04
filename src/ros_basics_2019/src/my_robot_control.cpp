#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("Waypoint received: [%s]", msg->data.c_str());
	printf("hi");
}

int main(int argc, char **argv)
{
	//initialization of ros
	ros::init(argc, argv, "robot_control");
	//access to communication with ROS
	ros::NodeHandle n;

	//subscribe to goal_pos to get the waypoints
	ros::Subscriber sub = n.subscribe("goal_pos", 1000, chatterCallback);
	//subrscribe to odom to get the position and orientation of the robot
	//ros::Subscriber sub2 = n.subscribe("odom", 1000, chatterCallback);

ros::spin();
  
return 0;
}
