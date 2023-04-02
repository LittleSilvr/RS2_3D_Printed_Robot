#!/usr/bin/env python3

import rospy
from std_msgs.msg import Int32

rospy.init_node('test_data_publisher')
pub = rospy.Publisher('testData', Int32, queue_size=10)

rate = rospy.Rate(10)  # publish at 10 Hz
count = 0

while not rospy.is_shutdown():
    pub.publish(count)

    if count == 100:
        count = 0
    else:
        count += 2

    rate.sleep()
