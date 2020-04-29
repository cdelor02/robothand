/* TEST CASE OF THIS LIBRARY WITH ROS CONNECTION FOR MY SENIOR PROJECT Spring 2020
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
#include <std_msgs/UInt16.h>
#include <std_msgs/UInt16MultiArray.h>
#include <sensor_msgs/JointState.h>

ros::NodeHandle nh;

void servo_cb(const std_msgs::UInt16MultiArray& cmd_msg) {
  int pos0 = 0, pos1 = 0, pos2 = 0, pos3 = 0;
  pos0 = map(cmd_msg.data[0], 0, 180, 10, 450);
  pos1 = map(cmd_msg.data[1], 0, 180, 10, 450);
  pos2 = map(cmd_msg.data[2], 0, 180, 10, 450);
  pos3 = map(cmd_msg.data[3], 0, 180, 10, 450);

  HCPCA9685.Servo(0, pos0);
  HCPCA9685.Servo(1, pos1);
  HCPCA9685.Servo(2, pos2);
  HCPCA9685.Servo(3, pos3);

}

ros::Subscriber<std_msgs::UInt16MultiArray> sub("servo", servo_cb);

void setup() 
{
  /* Initialise the library and set it to 'servo mode' */ 
  HCPCA9685.Init(SERVO_MODE);

  /* Wake the device up */
  HCPCA9685.Sleep(false);
  Serial.begin(9600);

  nh.initNode();
  nh.subscribe(sub);

  nh.getHardware()->setBaud(9600);
  nh.initNode();
}


void loop() {
  //unsigned int Pos;

  // range for servos looks like its 10-450, with this library
  // to allow users to give an angle, want a mapping of ang |--> pos vals (of this library)

    
  nh.spinOnce();



  //set_all(450, 4);

  /* Sweep the servo back and forth from its minimum to maximum position.
     If your servo is hitting its end stops then you  should adjust the 
     values so that the servo can sweep though its full range without hitting
     the end stops. You can adjust the min & max positions by altering 
     the trim values in the libraries HCPCA9685.h file*/
    /* This function sets the servos position. It takes two parameters, 
     * the first is the servo to control, and the second is the servo 
     * position. */ 

   /*
   for(Pos = 10; Pos < 450; Pos++)
  {
    
    //Serial.print("Pos: ");
    //Serial.println(Pos);
    HCPCA9685.Servo(0, Pos);
    HCPCA9685.Servo(1, Pos);
    HCPCA9685.Servo(2, Pos);  
    HCPCA9685.Servo(3, Pos);      
    delay(10);
  }
  
  for(Pos = 450; Pos >= 10; Pos--)
  {
    //Serial.print("Pos: ");
    //Serial.println(Pos);
    HCPCA9685.Servo(0, Pos);
    HCPCA9685.Servo(1, Pos);
    HCPCA9685.Servo(2, Pos);  
    HCPCA9685.Servo(3, Pos); 
    delay(10);
  }
  */
  
}

void set_all(int pos, int num_servos) {
  int i = 0;
    for(i = 0; i < num_servos; i++) {
      HCPCA9685.Servo(i, pos);
    }
}
