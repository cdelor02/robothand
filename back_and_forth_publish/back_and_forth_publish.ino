/*
 * For the full tutorial write up, visit
 * www.ros.org/wiki/rosserial_arduino_demos
 *
 * For more information on the Arduino Servo Library
 * Checkout :
 * http://www.arduino.cc/en/Reference/Servo
 */

//THIS IS ALSO FOR MY THESIS!!!!!

#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#include <Servo.h> 
#include <ros.h>
#include <std_msgs/UInt16.h>
#include <std_msgs/UInt16.MultiArray.h>
#include <sensor_msgs/JointState.h>
//the next step is to publish a joint state message, with (dummy) values

ros::NodeHandle nh;

Servo servo;

void servo_cb(const std_msgs::UInt16& cmd_msg){
  servo.write(cmd_msg.data); //set servo angle, should be from 0-180  
  digitalWrite(13, HIGH-digitalRead(13));  //toggle led  
}


ros::Subscriber<std_msgs::UInt16> sub("servo", servo_cb);

void setup(){
  pinMode(13, OUTPUT);

  nh.initNode();
  nh.subscribe(sub);
  
  servo.attach(9); //attach it to pin 9

  Serial.begin(9600);
  nh.getHardware()->setBaud(9600);
  nh.initNode();
}

void loop(){
  nh.spinOnce();
  //delay(1);
}
