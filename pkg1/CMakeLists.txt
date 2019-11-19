cmake_minimum_required(VERSION 2.8.3)
project(recall_1point)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  roscpp
  turtlesim
)
###################################
## catkin specific configuration ##
###################################
catkin_package(
)

###########
## Build ##
###########
include_directories(
  ${catkin_INCLUDE_DIRS}
)

# _recall_1point Executable
add_executable(${PROJECT_NAME}_recall_1point src/_recall_1point.cpp)
set_target_properties(${PROJECT_NAME}_recall_1point PROPERTIES OUTPUT_NAME _recall_1point PREFIX "")
target_link_libraries(${PROJECT_NAME}__recall_1point
  ${catkin_LIBRARIES}
)
#add_executable(${PROJECT_NAME}_NAME src/NAME.cpp)
#set_target_properties(${PROJECT_NAME}_NAME PROPERTIES OUTPUT_NAME NAME PREFIX "")
#target_link_libraries(${PROJECT_NAME}_NAME
#  ${catkin_LIBRARIES}
#)

#############
## Install ##
#############

# Mark executables for installation
install(TARGETS
  ${PROJECT_NAME}_recall_1point
#  ${PROJECT_NAME}_NAME
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
