# seniorthesis
Repo for senior thesis project, 2019-2020



## Publishing a Uint16 servo position to an Arduino 
[(from this ROS wiki tutorial)](http://wiki.ros.org/rosserial_arduino/Tutorials/Servo%20Controller "ROS Rosserial tutorial")

Before doing any of this work, you must run `sudo chmod atrw /dev/ttyACM0`, which gives read/write access to the serial port to which the Arduino is connected.

Next:
1. Change directory into your workspace and run `catkin_make`
2. Once that finishes, run `roscore`
3. Connect the Arduino with a USB cable
4. While still in the catkin workspace directory, in a new terminal window run `rosrun rosserial_python serial_node.py /dev/ttyACM0`
5. In a new terminal window, publish a uint16 to the servo topic by writing `rostopic pub servo std_msgs/UInt16  <angle>`, where `<angle>` is a value between 0-180
