#!/usr/bin/env python
# license removed for brevity

# Directed Study, Spring 2020
# Charles DeLorey
# Department of Computer Science, Tufts University

# Example publisher for Arduino-based robotic hand
# Sends Adc message (6 uint16's), ignoring last, to hand to set joint angle

import sys
import rospy
import serial
from itertools import cycle, chain
from std_msgs.msg import UInt16
from rosserial_arduino.msg import Adc

#port = "dev/ttyACM0"
#baud = 9600

joint_msg = Adc() #using predefined message, as custom message is not working
joint_msg.adc0 = finger1
joint_msg.adc1 = finger2
joint_msg.adc2 = finger3
joint_msg.adc3 = finger4
joint_msg.adc4 = finger5
joint_msg.adc5 = 0 #no 6th finger, so this part of the message is not used


def talker():
    pub = rospy.Publisher('servo', Adc, queue_size=10)
    rospy.init_node('talker', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        pub.publish(joint_msg)

        rate.sleep()


if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
