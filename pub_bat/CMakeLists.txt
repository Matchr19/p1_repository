cmake_minimum_required(VERSION 2.8.3)
project(pub_bat)

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

# pubba Executable
add_executable(${PROJECT_NAME}_pubba src/pubba.cpp)
set_target_properties(${PROJECT_NAME}_pubba PROPERTIES OUTPUT_NAME pubba PREFIX "")
target_link_libraries(${PROJECT_NAME}_pubba
  ${catkin_LIBRARIES}
)

# subba Executable
add_executable(${PROJECT_NAME}_subba src/subba.cpp)
set_target_properties(${PROJECT_NAME}_subba PROPERTIES OUTPUT_NAME subba PREFIX "")
target_link_libraries(${PROJECT_NAME}_subba
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
  ${PROJECT_NAME}_pubba
  ${PROJECT_NAME}_subba
  #  ${PROJECT_NAME}_NAME
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)