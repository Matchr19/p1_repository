cmake_minimum_required(VERSION 2.8.3)
project(docking)

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

# dock Executable
add_executable(${PROJECT_NAME}_dock src/dock.cpp)
set_target_properties(${PROJECT_NAME}_dock PROPERTIES OUTPUT_NAME dock PREFIX "")
target_link_libraries(${PROJECT_NAME}_dock
  ${catkin_LIBRARIES}
)

# call_dock Executable
add_executable(${PROJECT_NAME}_call_dock src/call_dock.cpp)
set_target_properties(${PROJECT_NAME}_call_dock PROPERTIES OUTPUT_NAME call_dock PREFIX "")
target_link_libraries(${PROJECT_NAME}_call_dock
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
  ${PROJECT_NAME}_dock
  ${PROJECT_NAME}_call_dock
#  ${PROJECT_NAME}_NAME
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)