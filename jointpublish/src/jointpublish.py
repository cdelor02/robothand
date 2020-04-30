#!/usr/bin/env python
# license removed for brevity
import rospy
import serial
from itertools import cycle, chain
# from std_msgs.msg import String
from std_msgs.msg import UInt16MultiArray #was UInt16

#port = "dev/ttyACM0"
#baud = 9600

#this is what it'll look like to use a custom message:
#from std_msgs.msg import String
#msg = String()

def talker():
    pub = rospy.Publisher('servo', UInt16MultiArray, queue_size=10)
    rospy.init_node('talker', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    #ang = 0#[0, 0, 0, 0] #would want this to be a uint16array
    while not rospy.is_shutdown():
        for ang in cycle(chain(range(0, 180, 1), range(180, 0, -1))):
            pub.publish([ang, ang, ang, ang])

        rate.sleep()


if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
