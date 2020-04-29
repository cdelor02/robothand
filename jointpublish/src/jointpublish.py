#!/usr/bin/env python
# license removed for brevity
import rospy
import serial
import numpy as np #unsure if this will do what I want
# from std_msgs.msg import String
from std_msgs.msg import UInt16#UInt16MultiArray #was UInt16

#port = "dev/ttyACM0"
#baud = 9600

def talker():
    pub = rospy.Publisher('servo', UInt16, queue_size=10)
    rospy.init_node('talker', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    ang = 0#[0, 0, 0, 0] #would want this to be a uint16array
    while not rospy.is_shutdown():
        # angle = ang % rospy.get_time()
        # rospy.loginfo(hello_str)
        pub.publish(ang)
        ang += 1
        if ang == 180:
			ang = 0
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
