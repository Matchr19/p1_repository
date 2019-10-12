cmake_minimum_required(VERSION 2.8.3)
project(pkgkasper)

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


#############
## Install ##
#############

# Mark executables for installation
install(TARGETS

  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
