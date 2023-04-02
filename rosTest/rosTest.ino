#include <ArduinoHardware.h>
#include <ros.h>
#include <std_msgs/Int32.h>

ros::NodeHandle nh; // Create a ROS node with the name "alex_arduino"

int ledPin = LED_BUILTIN; // Set the LED pin to the built-in LED pin
bool ledState = false; // Initialize the LED state to off

void toggleLed(int value) {
  if (value > 50) {
    ledState = true;
  } else {
    ledState = false;
  }
  digitalWrite(ledPin, ledState); // Set the LED state based on the received value
}

void testDataCallback(const std_msgs::Int32& msg) {
  toggleLed(msg.data); // Call the toggleLed function with the received value
}

ros::Subscriber<std_msgs::Int32> testDataSub("testData", &testDataCallback); // Create a subscriber object for the testData topic

void setup() {
  pinMode(ledPin, OUTPUT); // Set the LED pin as an output
  nh.initNode(); // Initialize the ROS node
  nh.subscribe(testDataSub); // Subscribe to the testData topic
}

void loop() {
  nh.spinOnce(); // Handle any incoming ROS messages
  delay(10);
}


// #include <ros.h>
// #include <std_msgs/String.h>

// ros::NodeHandle nh;
// std_msgs::String str_msg;
// ros::Publisher chatter("chatter", &str_msg);

// char hello[13] = "hello world!";

// void setup() {
//   nh.initNode();
//   nh.advertise(chatter);
// }

// void loop() {
//   str_msg.data = hello;
//   chatter.publish(&str_msg);
//   nh.spinOnce();
//   delay(1000);
// }

