#include <ArduinoHardware.h>
#include <ros.h>
#include <std_msgs/Int32.h>

ros::NodeHandle nh; // Create a ROS node with the name "alex_arduino"

int ledPin = LED_BUILTIN; // Set the LED pin to the built-in LED pin
bool ledState = false; // Initialize the LED state to off

void toggleLed(int value) {
  if (value > 128) {
    ledState = true;
  } else {
    ledState = false;
  }
  digitalWrite(ledPin, ledState); // Set the LED state based on the received value
}

void testDataCallback(const std_msgs::Int32& msg) {
  toggleLed(msg.data); // Call the toggleLed function with the received value
  Serial.println(msg.data); // Print the value of testData to the serial monitor
}

ros::Subscriber<std_msgs::Int32> testDataSub("testData", &testDataCallback); // Create a subscriber object for the testData topic

void setup() {
  pinMode(ledPin, OUTPUT); // Set the LED pin as an output
  Serial.begin(9600); // Initialize the serial communication
  nh.initNode(); // Initialize the ROS node
  nh.subscribe(testDataSub); // Subscribe to the testData topic
}

void loop() {
  nh.spinOnce(); // Handle any incoming ROS messages
}
