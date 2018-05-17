/**
 * \brief This code listens to raven messages. 
 *
 * \author Andy Lewis
 * \date 4/15/2018
 */

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "raven_2/raven_state.h"

int frequency 		= 1; //Hz sampling frequency



/** RAVEN data callback function that prints something out frequently
 *
 */
void ravenstateCallback(const raven_2::raven_state& msg)
{
	static int msg_count;
	int period = 1000 / frequency;

	//set logical bounds on period
	if (period < 1) period = 1;
	if (period > 1000) period = 1000;

	//increment count for another message received
	msg_count++;

	if (msg_count % period == 0){
		ROS_INFO("I heard raven_data %i", msg_count);
		msg_count = 0;
	}



}


int main(int argc, char **argv)
{

  ros::init(argc, argv, "ravenListener");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("ravenstate", 1000, ravenstateCallback);

  ros::spin();

  return 0;
}
