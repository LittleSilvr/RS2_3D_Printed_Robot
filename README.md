# 3D Printed Robotic Arm - RS2

## Features:

The 3D Printed Robotic Arm - RS2 is a compact and affordable robotic arm that offers the following features:

- Reach: With a reach of 0.5m, the RS2 can access objects in its immediate vicinity, making it suitable for small-scale applications.
- Capacity: The arm can carry up to 0.5kg, making it capable of lifting and manipulating small objects.
- Compatibility with computer vision software: The RS2 can be programmed to work with computer vision software, enabling it to detect and interact with objects in its environment.
- Modular, parametric limbs: The RS2's limbs are designed to be easily modified and customized to suit your specific needs. You can adjust the arm's length, and other parameters as needed.
- Fully 3D printed: The entire RS2 arm can be 3D printed using most household 3D printers, making it an affordable and accessible option for robotics enthusiasts and small businesses.

## Prerequisites:

Before getting started, make sure you have the following prerequisites installed:

- Linux: This project requires a Ubunto 20.04 operating system to be installed.
- ROS: ROS (Robot Operating System) is a set of software libraries and tools that help you build robot applications. Make sure ROS is installed before starting this project.
- VSCode: Visual Studio Code is a source code editor that can be used with a variety of programming languages. It is recommended to use VSCode for this project.
 - rosserial: rosserial must be installed prior to launch to ensure a communcaiotn between microcontrollers such as arduinos is possible
 ```cd ~/Arduino/libraries```
```rm -rf ros_lib```
```rosrun rosserial_arduino make_libraries.py .```


### Installation:

Step-by-step instructions on how to install your project.

### Usage

0. Start ROS and open new terminal window

```roscore```

1. Have arduino code uploaded

2. Close arduino IDE

3. Ensure arduino is plugged into ROS platform

4. Run rosserial_node.py in terminal

```rosrun rosserial_python serial_node.py /dev/ttyACM1 _baud:=57600 __name:=arduino_uno```

5. Run rosTest.py in terminal

```rosrun rs2_pkg rosTest.py```

6. Echo the data for verification

```rostopic echo /testData```

## License:

This project is licensed under the MIT License.

The MIT License is a permissive open-source software license that allows for free use, modification, and distribution of the code, as long as the original copyright and license notice is included in all copies or substantial portions of the code.

By contributing to this project, you agree to license your contribution under the same terms as this project.

## Contacts:

For any questions or inquiries, please contact: 
 - Alexander Robinson at alexander.w.robinson@student.uts.edu.au.
 - Hamish Shaw at hamish.p.shaw@student.uts.edu.au
 - Angus Cheng at angus.m.cheng@student.uts.edu.au
 - Jack McCann at jack.mccann@student.uts.edu.au

## Contributing:

Instructions on how others can contribute to your project, including guidelines for submitting bug reports, feature requests, and pull requests.
