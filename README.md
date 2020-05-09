# Directed Study: Department of Computer Science, Tufts University
Repo for my directed study project, 2019-2020 academic year

## Resources for using rosserial and rosserial_arduino:
- Publishing a Uint16 servo position to an Arduino 
[(from this ROS wiki tutorial)](http://wiki.ros.org/rosserial_arduino/Tutorials/Servo%20Controller "ROS Rosserial tutorial")
- [rosserial_python page](http://wiki.ros.org/rosserial_python)
- [Creating custom messages and services in ROS tutorial page](http://wiki.ros.org/ROS/Tutorials/CreatingMsgAndSrv)

## Necessary materials:
- Arduino ([Uno](https://store.arduino.cc/usa/arduino-uno-rev3), [Mega](https://store.arduino.cc/usa/mega-2560-r3), or other comparable Arduino-based microcontroller)
- [Arduino IDE](https://www.arduino.cc/en/Main/Software) 
- USB to mini-USB cable 
- PCA9685 PWM servo driver [(Adafruit product link)](https://www.adafruit.com/product/815)
- 5 micro servos, 180 degree rotation (continous rotation servos will not work) [(Adafruit product link)](https://www.adafruit.com/product/169)
- AC/DC 5v power adapter [(Adafruit product link)](https://www.adafruit.com/product/276)
- Jumper wires
- Female DC Power adapter (2.1mm jack to screw terminal block) [(Adafruit product link)](https://www.adafruit.com/product/368)
- 3D printer (to print the CAD parts of the hand)
- Hardware for assembly: at least 15 M2 16mm long bolts and nuts, string (roughly 2mm thick)


*Note for Ubuntu users* : Before doing any of this work, you must run `sudo chmod a+rw /dev/ttyACM0`, which gives read/write access to the serial port to which the Arduino is connected. If there are issues, consult [this Arduino forum](https://forum.arduino.cc/index.php?topic=495039.0).

### Printing the CAD parts:
The pointer, middle, ring, and pinky fingers are all constructed with one print each of fingertip.stl, fingermiddle.stl, and fingerbase.stl. The thumb is composed of just two segments, fingertip.stl and fingerbase.stl. The palm is made from one piece, palm.stl. 
If the fingers have difficulty printing in large batches, try printing at most 3 segments at once on the print bed. 


### Installation and running the test publisher with the hand subscriber:
1. Clone or download this repo into your ROS workspace
2. Run `catkin_make` in your workspace, and properly source it
3. Once that finishes, run `roscore`
4. Open the Arduino file `servocontrol.ino` in the Arduino IDE
5. Select your board under Tools > Board > your_board_here, and ensure it says "Arduino as ISP" under Tools > Programmer
5. Connect the Arduino to the computer with a USB to mini-USB cable, and click "Upload" to compile and upload the code to the board
6. While still in the catkin workspace directory, in a new terminal window run `rosrun rosserial_python serial_node.py _baud:=<your_baud_rate> _port:=/dev/ttyACM0`
7. Open `joint_publish_test.py` and ensure that the values the fingers are being set to are your desired values, being sure to save them.
8. When ready, ensure the Arduino is connected to the computer via USB, as well as to the servo driver ([as shown here](https://learn.adafruit.com/16-channel-pwm-servo-driver/hooking-it-up)), and the driver is receiving power and is connected to all the servos. 
9. In a new terminal window, run `python /path/to/this/package/seniorthesis/jointpublish/scripts/joint_publish_test.py`, and watch the hand move to your configuration! If the script does not run, it is possible it needs executable permissions, so type `chmod +x joint_publish_test.py` into the terminal and try again.
**NOTE: it is possible to send angles to the hand that your particular servos are not able to reach. Configure the code to match the limits of your servos.

**OTHER NOTE: the `rosserial_python` node must be run with Python2.X (it will not work with Python3)

# Other resources used: 
[Library for controlling multiple servos (with servo driver board)](https://www.brainy-bits.com/control-multiple-servos-with-joystick/)

[Installing the Arduino IDE on Ubuntu](https://ubuntu.com/tutorials/install-the-arduino-ide#1-overview):

[Wiring for the PC9685 servo driver board for Arduino](https://learn.adafruit.com/16-channel-pwm-servo-driver/hooking-it-up)
