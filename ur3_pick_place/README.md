## Intro

The following package utilises moveit and the Universal robots moveit config
to calculate movements for the UR lineup. This utilises ros using moveits
c++ move_group_interface. This is a relatively easy way to make the most of 
moveits capabilities

## Installation:

depending on your version of ros/ubuntu, you will need to download the appropriate libraries

create a new or use an existing catkin workspace

first install moveit, the following link is a good guide on this

https://moveit.ros.org/install/

download the following repositories from git
https://github.com/ros-industrial/universal_robot

## Use:
first launch the ur3 rviz demo in 1 terminal

roslaunch ur3_moveit_config demo.launch

in another terminal run the program

rosrun ur3_pick_and_place pick_and_place

## TODO:

impliment collision avoidance by inputting objects into the robots workspace, also setting up the robot so it is on a bench as with
many of the setups at UTS
