################ This python file calculates the distance between turtle 1 and turtle 2. This file should be run seperately to see the distance between them. #################### 

#!/usr/bin/env python
import rospy
from turtlesim.msg import Pose
import math


############# Pose of Turtle 1 ###############
def turtle1_pose(msg):
    calculate_distance(msg.x, msg.y, turtle2_pose.x, turtle2_pose.y)

############# Pose of Turtle 2 ###############
def turtle2_pose(msg):
    global turtle2_pose
    turtle2_pose = msg

###### Calculating Euclidean Distance #######
def calculate_distance(x1, y1, x2, y2):
    distance = math.sqrt((x2 - x1)**2 + (y2 - y1)**2)
    print("Distance:", distance)

############# Main Function #################
if __name__ == '__main__':
    rospy.init_node('pose_printer')

    turtle1_pose = Pose()
    turtle2_pose = Pose()

    rospy.Subscriber('turtle1/pose', Pose, turtle1_pose)
    rospy.Subscriber('turtle2/pose', Pose, turtle2_pose)

    rospy.spin()
