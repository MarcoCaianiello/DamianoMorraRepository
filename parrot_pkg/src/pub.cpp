#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "std_msgs/String.h"
#include <iostream>


int main(int argc, char **argv){
	ros::init(argc, argv, "parrot_pub_node"); 
	ros::NodeHandle nh;  
	ros::Publisher topic_pub = nh.advertise <std_msgs::String> ("pacchetto",9999); 
	ros::Rate rate(10); //10Hz

	while(ros::ok()){

		std::string str;
		std_msgs::String msg_str;

		ROS_INFO("Inserire dati");
		std::getline(std::cin, str);
		msg_str.data=str;
		ROS_INFO ("Inviato: %s", msg_str.data.c_str());

		topic_pub.publish(msg_str);

		rate.sleep();
	}	
}
