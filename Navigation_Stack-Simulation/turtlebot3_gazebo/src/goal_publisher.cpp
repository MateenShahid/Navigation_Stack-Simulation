#include <ros/ros.h>
#include <iostream>
#include <std_msgs/Int8.h>
//#include <geometry_msgs/PoseStamped.h>
#include <move_base_msgs/MoveBaseActionGoal.h>
using namespace std;

ros::Publisher goal_pub;
ros::Publisher pub;
ros::Subscriber goal_sub; 

void goalLocationCallback(const std_msgs::Int8::ConstPtr& msg)

{
  int goal_location = msg->data;

  // Check the received number and publish the corresponding goal location
  if (goal_location == 1)
  {
    move_base_msgs::MoveBaseActionGoal goal;
    // Set the goal coordinates for location 1
    goal.goal.target_pose.header.frame_id = "map";
    goal.goal.target_pose.header.stamp = ros::Time::now();
    goal.goal.target_pose.pose.position.x = 0.67;   // x-coordinate of Location 1.
    goal.goal.target_pose.pose.position.y = 1.5;   // y-coordinate of Location 1.
    goal.goal.target_pose.pose.orientation.w = 1.0; // Orientation at Location 1.
    goal_pub.publish(goal);
    std::cout<<"\n GOING TO LOCATION 1."<<std::endl;
  }
  else if (goal_location == 2)
  {
    move_base_msgs::MoveBaseActionGoal goal;
    // Set the goal coordinates for location 2
    goal.goal.target_pose.header.frame_id = "map";
    goal.goal.target_pose.header.stamp = ros::Time::now();
    goal.goal.target_pose.pose.position.x = -6.5;   // x-coordinate of Location 2.
    goal.goal.target_pose.pose.position.y = -1.2;   // y-coordinate of Location 2.
    goal.goal.target_pose.pose.orientation.w = 0.7; // Orientation at Location 2.
    goal_pub.publish(goal);
    std::cout<<"\n GOING TO LOCATION 2."<<std::endl;
  }
  else if (goal_location == 3)
  {
    move_base_msgs::MoveBaseActionGoal goal;
    // Set the goal coordinates for location 3
    goal.goal.target_pose.header.frame_id = "map";
    goal.goal.target_pose.header.stamp = ros::Time::now();
    goal.goal.target_pose.pose.position.x = 6.05;   // x-coordinate of Location 3.
    goal.goal.target_pose.pose.position.y = -0.78;   // y-coordinate of Location 3.
    goal.goal.target_pose.pose.orientation.w = -0.5;  // Orientation at Location 3.
    goal_pub.publish(goal);
    cout<<"\n GOING TO LOCATION 3."<<endl;
  }
  else
  {
    cout<<"\n UNDECLARED GOAL LOCATION, DOING NOTHING !!!!!!"<<endl;
  }

  // Terminate the program
  //ros::shutdown();
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "goal_publisher_node");
  ros::NodeHandle nh;

  //int goal_input;

  // Create a publisher to publish goal locations
  goal_pub = nh.advertise<move_base_msgs::MoveBaseActionGoal>("/move_base/goal", 1);

  // Create a subscriber to receive goal location commands
  goal_sub = nh.subscribe("/goal_location", 1, goalLocationCallback);

  // Create a publisher for the "/goal_location" topic
  pub = nh.advertise<std_msgs::Int8>("/goal_location", 10);

  ros::spin();

  return 0;
}
