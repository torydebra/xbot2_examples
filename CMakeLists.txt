cmake_minimum_required(VERSION 3.0)
project(xbot2_examples)

option(XBOT2_ENABLE_XENO OFF "Compile against xenomai")

add_subdirectory(src/clock)
add_subdirectory(src/malloc_example)
add_subdirectory(src/homing_example)
add_subdirectory(src/ros_from_rt)
add_subdirectory(src/talker_listener)
add_subdirectory(src/client_server)
add_subdirectory(src/device)
add_subdirectory(src/joint_impedance)
add_subdirectory(src/cartesio)
