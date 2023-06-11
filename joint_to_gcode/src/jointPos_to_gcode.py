#!/usr/bin/env python3

import rospy
import subprocess
import math
from sensor_msgs.msg import JointState

# Define the JointState message callback function
def joint_state_callback(msg):
    # Append the joint positions from the message to the array
    joint_positions.extend(msg.position[:6])

# Define a function to convert joint positions to G-code
def convert_to_gcode(joint_positions):
    if len(joint_positions) == 6:
        # echo "G0 X10 Y10 Z10 A10 B10" > /dev/ttyS0
        joint_positions_degrees = [math.degrees(position) for position in joint_positions]
        gcode = 'echo "G0 X{:.4f} Y{:.4f} Z{:.4f} A{:.4f} B{:.4f} C{:.4f}" > /dev/AMC0'.format(*joint_positions_degrees)
        return gcode
    else:
        return ""

# Initialize the ROS node
rospy.init_node('jointPos_to_gcode')

# Define the joint positions array and count
joint_positions = []
joint_count = 0

# Subscribe to the JointState topic
rospy.Subscriber('/joint_states', JointState, joint_state_callback)

# Main loop
while not rospy.is_shutdown():
    if len(joint_positions) >= 6:
        # Log the joint positions in a single line
        joint_positions_str = ' '.join("{:.4f}".format(position) for position in joint_positions[:6])
        rospy.loginfo("Joint Positions: %s", joint_positions_str)

        # Convert the joint positions to G-code
        gcode = convert_to_gcode(joint_positions[:6])

        if gcode:
            # Log the G-code
            rospy.loginfo("G-code: %s", gcode)

            # Execute the G-code command
            subprocess.run(gcode, shell=True)

        # Remove the processed joint positions
        joint_positions = joint_positions[6:]

        # Start a new line after printing all 6 joint positions and G-code
        print()

    # Wait for a short time before repeating
    rospy.sleep(0.1)
