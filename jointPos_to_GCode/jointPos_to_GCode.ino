#include <ros.h>
#include <sensor_msgs/JointState.h>

// Define the ROS node handle and JointState message objects
ros::NodeHandle nh;
sensor_msgs::JointState joint_state_msg;

// Define an array to store the joint positions
float joint_positions[6];

// Define the JointState message callback function
void jointStateCallback(const sensor_msgs::JointState& msg)
{
  // Copy the joint positions from the message into the array
  for (int i = 0; i < 6; i++) {
    joint_positions[i] = msg.position[i];
  }
}

// Define a function to convert joint positions to G-code
void convertToGcode(float joint_positions[], char* gcode)
{
  sprintf(gcode, "G0 X%.4f Y%.4f Z%.4f A%.4f B%.4f C%.4f",
          joint_positions[0], joint_positions[1], joint_positions[2],
          joint_positions[3], joint_positions[4], joint_positions[5]);
}

void setup()
{
  // Initialize the ROS node
  nh.initNode();
  
  // Subscribe to the JointState topic
  nh.subscribe("/joint_states", &jointStateCallback);
}

void loop()
{
  // Handle ROS events
  nh.spinOnce();
  
  // Print the joint positions in a single line
  for (int i = 0; i < 6; i++) {
    Serial.print(joint_positions[i], 4); // Use 4 decimal places for precision
    Serial.print(" ");
  }
  
  // Convert the joint positions to G-code
  char gcode[128];
  convertToGcode(joint_positions, gcode);
  
  // Print the G-code to the serial monitor
  Serial.println();
  Serial.println(gcode);
  
  // Wait for a short time before repeating
  delay(100);
}
