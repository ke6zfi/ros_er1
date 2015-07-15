#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Float64.h"
#include "er1_motor_driver/Motors.h"

#include <sstream>

int main(int argc, char *argv[]) 
{
	ros::init(argc, argv, "send_cmd");

	// NodeHandle is the main access point to communications with the ROS system.
	// First NodeHandle constructed will fully initialize this node, and the last
	// NodeHandle destructed will close down the node.
	ros::NodeHandle n;

	ros::Publisher send_pub = n.advertise<er1_motor_driver::Motors>("motor_out", 1000);

	ros::Rate loop_rate(10);

	int count = 0;
	while ( ros::ok() ) {
		er1_motor_driver::Motors msg;

		msg.x_vel = 1.0;
		msg.a_vel = 0.0;

		ROS_INFO("Sending (%d): %.3f %.3f",count, msg.x_vel, msg.a_vel );

		send_pub.publish(msg);

		ros::spinOnce();

		loop_rate.sleep();
		++count;
	}
	return 0;
}