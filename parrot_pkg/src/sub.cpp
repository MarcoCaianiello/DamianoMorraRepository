#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>


class ROS_SUB{
	public:
		ROS_SUB();
		void topic_cb(std_msgs::String::ConstPtr msg);
	private:
		ros::NodeHandle _nh;
		ros::Subscriber _topic_sub;
	};


ROS_SUB::ROS_SUB(){
	_topic_sub = _nh.subscribe( "pacchetto", 9999,&ROS_SUB::topic_cb, this);
}

void ROS_SUB::topic_cb( std_msgs::String::ConstPtr msg){
	ROS_INFO("Ricevuto: %s", msg->data.c_str());
};


int main(int argc, char **argv){
	
	ros::init(argc,argv,"parrot_sub_node");
	ROS_SUB rs;

	ros::spin();  //aspetta solo le callback
}
