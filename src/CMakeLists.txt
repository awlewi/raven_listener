cmake_minimum_required(VERSION 2.8.3)
project(raven_listener)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS 
  roscpp rospy std_msgs 
  geometry_msgs message_generation
  raven_2)

## Add in message and service files
#add_message_files(FILES raven_automove.msg raven_state.msg)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs geometry_msgs)

## Declare a catkin package
catkin_package(CATKIN_DEPENDS message_runtime)

## Build listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(listenerRAVEN 
  src/listener.cpp  
#  src/Raven_Controller.cpp 
#  src/Raven_PathPlanner.cpp
)
target_link_libraries(listenerRAVEN ${catkin_LIBRARIES})
add_dependencies(listenerRAVEN raven_listener_generate_messages_cpp)
