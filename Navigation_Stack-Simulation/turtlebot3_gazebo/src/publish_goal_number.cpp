#include <ros/ros.h>
#include <std_msgs/Int8.h>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
  // Initialize the ROS node
  ros::init(argc, argv, "publisher_node");
  ros::NodeHandle nh;

  // Create a publisher for the "/goal_location" topic
  ros::Publisher pub = nh.advertise<std_msgs::Int8>("/goal_location", 10);

  // Main loop
  while (ros::ok()) {
    // Prompt the user to enter an integer
    cout << "Enter goal location (1,2, or 3):";
    int input;
    cin >> input;

    // Create an std_msgs/Int8 message and set the value
    std_msgs::Int8 msg;
    msg.data = input;

    // Publish the message
    pub.publish(msg);

    // Spin once to let the message be published
    ros::spinOnce();
  }

  return 0;
}
