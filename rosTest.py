#!/usr/bin/env python

import rospy
from std_msgs.msg import String

def subscriber_callback(msg):
    # Your code to process the received message goes here
    pass

def main():
    rospy.init_node('node_name', anonymous=True)
    
    # Create a subscriber to listen to a topic
    rospy.Subscriber('topic_name', String, subscriber_callback)
    
    # Create a publisher to send messages to a topic
    pub = rospy.Publisher('topic_name', String, queue_size=10)
    
    # Set the publishing rate (in Hz)
    rate = rospy.Rate(10)
    
    while not rospy.is_shutdown():
        # Your code to generate a message goes here
        msg = String()
        msg.data = 'Hello, world!'
        
        # Publish the message
        pub.publish(msg)
        
        # Sleep to maintain the publishing rate
        rate.sleep()

if __name__ == '__main__':
    main()
