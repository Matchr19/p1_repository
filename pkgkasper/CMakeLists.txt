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

# somecode executable
add_executable(${PROJECT_NAME}_somecode src/somecode.cpp)
set_target_properties(${PROJECT_NAME}_somecode PROPERTIES OUTPUT_NAME somecode PREFIX "")
# Link to Catkin libraries
target_link_libraries(${PROJECT_NAME}_somecode
  ${catkin_LIBRARIES}
)


#############
## Install ##
#############

# Mark executables for installation
install(TARGETS
  ${PROJECT_NAME}_somecode
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
