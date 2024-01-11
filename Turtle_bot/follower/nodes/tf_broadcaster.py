#!/usr/bin/env python  
import roslib
roslib.load_manifest('follower')
import rospy
import tf
import turtlesim.msg
import geometry_msgs.msg
import turtlesim.srv
import  math

################### Transformation ########################
def handle_turtle_pose(msg, turtlename):
    br = tf.TransformBroadcaster()
    br.sendTransform((msg.x, msg.y, 0),
                     tf.transformations.quaternion_from_euler(0, 0, msg.theta),
                     rospy.Time.now(),
                     turtlename,
                     "world")

################### Main Function ###########################
if __name__ == '__main__':
    rospy.init_node('tf_broadcaster')
    turtlename = rospy.get_param('~turtle')
    rospy.Subscriber('/%s/pose' % turtlename,
                     turtlesim.msg.Pose,
                     handle_turtle_pose,
                     turtlename)
                    
    br = tf.TransformBroadcaster()
    rate = rospy.Rate(10.0)
    while not rospy.is_shutdown():
        br.sendTransform((-0.8, 0.0, 0.0),
                         (0.0, 0.0, 0.0, 1.0),
                         rospy.Time.now(),
                         "ref_frame",
                         "turtle1")
        rate.sleep()
    	
    rospy.spin()

