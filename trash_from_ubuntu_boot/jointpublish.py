#!/usr/bin/env python2.7
# license removed for brevity
import rospy
import serial
from itertools import cycle, chain
# from std_msgs.msg import String
from std_msgs.msg import UInt16MultiArray #was UInt16
from jointpublish.msg import *

#port = "dev/ttyACM0"
#baud = 9600

#this is what it'll look like to use a custom message:
#from std_msgs.msg import String
joint_msg = Hand()
joint_msg.finger0 = 30
joint_msg.finger1 = 30
joint_msg.finger2 = 30
joint_msg.finger3 = 30


def talker():
    pub = rospy.Publisher('servo', Hand, queue_size=10)
    rospy.init_node('talker', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    #ang = 0#[0, 0, 0, 0] #would want this to be a uint16array
    while not rospy.is_shutdown():
        for ang in cycle(chain(range(0, 180, 1), range(180, 0, -1))):
            pub.publish(joint_msg)

        rate.sleep()


if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
