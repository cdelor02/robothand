/* ROS SUBSCRIBER NODE FOR ROBOT HAND
 * Directed Study, Spring 2020
 * Charles DeLorey
 * Department of Computer Science, Tufts University

10/06/16 version 0.1: Original version
This example demonstrates how to use the HCPCA9685 library together with the PCA9685
to control up to 16 servos. The sketch will initialise the library putting it into 
'servo mode' and then will continuously sweep one servo connected to PWM output 0 
back and forth. The example has been written particularly for the 16 Channel 12-bit 
PWM Servo Motor Driver Module (HCMODU0097) available from hobbycomponents.com 

To use the module connect it to your Arduino as follows:
PCA9685...........Uno/Nano
GND...............GND
OE................N/A
SCL...............A5
SDA...............A4
VCC...............5V

External 5V Power for the servo(s) can be supplied by the V+ and GND input of the 
screw terminal block.

PLEASE NOTE: Depending on your servo it is possible for this sketch to attempt 
drive the servo beyond its end stops. If your servo is hitting its end stops then
you should adjust the the min and max values in this sketch.

You may copy, alter and reuse this code in any way you like, but please leave
reference to HobbyComponents.com in your comments if you redistribute this code.
This software may not be used directly for the purpose of selling products that
directly compete with Hobby Components Ltd's own range of products.

THIS SOFTWARE IS PROVIDED "AS IS". HOBBY COMPONENTS MAKES NO WARRANTIES, WHETHER
EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, ACCURACY OR LACK OF NEGLIGENCE.
HOBBY COMPONENTS SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR ANY DAMAGES,
INCLUDING, BUT NOT LIMITED TO, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY
REASON WHATSOEVER.
*/


/* Include the HCPCA9685 library */
#include "HCPCA9685.h"

/* I2C slave address for the device/module. For the HCMODU0097 the default I2C address
   is 0x40 */
#define  I2CAdd 0x40


/* Create an instance of the library */
HCPCA9685 HCPCA9685(I2CAdd);

/* declarations for ROS component*/
#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif
#include <ros.h>
#include <rosserial_arduino/Adc.h>

ros::NodeHandle nh;


// Function servo_cb: uses joint message to set the joint angles of the 5 fingers
// Parameters: command message of type Adc, 5 uint16's
// Returns: None

// NOTE: The Adc message is being used, as the custom message was not working. 
//       As such, there is an additional uint16 (adc5), which is to be ignored.

void servo_cb(const rosserial_arduino::Adc& cmd_msg) {
  int pos0 = 0, pos1 = 0, pos2 = 0, pos3 = 0, pos4 = 0, pos5 = 0;

  pos0 = map(cmd_msg.adc0, 0, 180, 10, 450);
  pos1 = map(cmd_msg.adc1, 0, 180, 10, 450);
  pos2 = map(cmd_msg.adc2, 0, 180, 10, 450);
  pos3 = map(cmd_msg.adc3, 0, 180, 10, 450);
  pos4 = map(cmd_msg.adc4, 0, 180, 10, 450);
  pos5 = cmd_msg.adc5; // disregarding this value, as there are only 5 fingers

  HCPCA9685.Servo(0, pos0); // .Servo takes 2 params: the servo to control (int), and the servo position (int)
  HCPCA9685.Servo(1, pos1);
  HCPCA9685.Servo(2, pos2);
  HCPCA9685.Servo(3, pos3);
  HCPCA9685.Servo(4, pos4);
  delay(500);

  pubjointangles(pos1, pos2, pos3, pos4, pos5);
}

void pubjointangles(int p0, int p1, int p2, int p3, int p4) {
  rosserial_arduino::Adc joints;
  joint_msg.adc0 = p0;  
  joint_msg.adc1 = p1;
  joint_msg.adc2 = p2;
  joint_msg.adc3 = p3;
  joint_msg.adc4 = p4;
  joint_msg.adc5 = 0; //dummy value, not necessary
  nh.publish( &joints );
}


// Create subscriber to the Adc message on the /servo topic
ros::Subscriber<rosserial_arduino::Adc> sub("servo", servo_cb);

// Create publisher to publish the current joint state of the hand
ros::Publisher<rosserial_arduino::Adc> pub("currjoints", &joint_msg);

void setup() 
{
  /* Initialise the library and set it to 'servo mode' */ 
  HCPCA9685.Init(SERVO_MODE);

  /* Wake the device up */
  HCPCA9685.Sleep(false);
  Serial.begin(9600);

  nh.initNode();
  nh.subscribe(sub);

  //set bit transmission rate to match that of the rosserial_python node (serial_node.py)
  nh.getHardware()->setBaud(9600);
  nh.initNode();


  nh.advertise(pub);
}


void loop() {
  nh.spinOnce();
  
}

// Function set_all: sends the same joint angle to all servos of the hand
// Parameters: desired positon (int), number of servos in the system (int)
// Returns: None
void set_all(int pos, int num_servos) {
  int i = 0;
    for(i = 0; i < num_servos; i++) {
      HCPCA9685.Servo(i, pos);
    }
}

// NOTES FROM HCPCA9685 EXAMPLE FILE
/* Sweep the servo back and forth from its minimum to maximum position.
   If your servo is hitting its end stops then you  should adjust the 
   values so that the servo can sweep though its full range without hitting
   the end stops. You can adjust the min & max positions by altering 
   the trim values in the libraries HCPCA9685.h file
 */
