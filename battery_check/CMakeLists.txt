cmake_minimum_required(VERSION 2.8.3)
project(battery_check)

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

# battery Executable
add_executable(${PROJECT_NAME}_battery src/battery.cpp)
set_target_properties(${PROJECT_NAME}_battery PROPERTIES OUTPUT_NAME battery PREFIX "")
target_link_libraries(${PROJECT_NAME}_battery
  ${catkin_LIBRARIES}
)

# battery1 Executable
add_executable(${PROJECT_NAME}_battery1 src/battery1.cpp)
set_target_properties(${PROJECT_NAME}_battery1 PROPERTIES OUTPUT_NAME battery1 PREFIX "")
target_link_libraries(${PROJECT_NAME}_battery1
  ${catkin_LIBRARIES}
)

# lige Executable
add_executable(${PROJECT_NAME}_lige src/lige.cpp)
set_target_properties(${PROJECT_NAME}_lige PROPERTIES OUTPUT_NAME lige PREFIX "")
target_link_libraries(${PROJECT_NAME}_lige
  ${catkin_LIBRARIES}
)

# ny Executable
add_executable(${PROJECT_NAME}_ny src/ny.cpp)
set_target_properties(${PROJECT_NAME}_ny PROPERTIES OUTPUT_NAME ny PREFIX "")
target_link_libraries(${PROJECT_NAME}_ny
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
  ${PROJECT_NAME}_battery
  ${PROJECT_NAME}_battery1
  ${PROJECT_NAME}_lige
  ${PROJECT_NAME}_ny
#  ${PROJECT_NAME}_NAME
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)