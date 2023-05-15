import rospy
from sensor_msgs.msg import JointState

# Define the JointState message callback function
def joint_state_callback(msg):
    # Append the joint positions from the message to the array
    joint_positions.extend(msg.position[:6])

# Define a function to convert joint positions to G-code
def convert_to_gcode(joint_positions):
    gcode = "G0 X{:.4f} Y{:.4f} Z{:.4f} A{:.4f} B{:.4f} C{:.4f}".format(*joint_positions)
    return gcode

# Initialize the ROS node
rospy.init_node('jointPos_to_gcode')

# Define the joint positions array
joint_positions = []

# Subscribe to the JointState topic
rospy.Subscriber('/joint_states', JointState, joint_state_callback)

# Main loop
while not rospy.is_shutdown():
    # Log the joint positions in a single line
    joint_positions_str = ' '.join("{:.4f}".format(position) for position in joint_positions)
    rospy.loginfo("Joint Positions: %s", joint_positions_str)

    # Convert the joint positions to G-code
    gcode = convert_to_gcode(joint_positions)

    # Log the G-code
    rospy.loginfo("G-code: %s", gcode)

    # Wait for a short time before repeating
    rospy.sleep(0.1)
