cmake_minimum_required(VERSION 2.8.3)
project(rrooms)

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

# rroom1 Executable
add_executable(${PROJECT_NAME}_rroom1 src/rroom1.cpp)
set_target_properties(${PROJECT_NAME}_rroom1 PROPERTIES OUTPUT_NAME rroom1 PREFIX "")
target_link_libraries(${PROJECT_NAME}_rroom1
  ${catkin_LIBRARIES}
)

# rroom2 Executable
add_executable(${PROJECT_NAME}_rroom2 src/rroom2.cpp)
set_target_properties(${PROJECT_NAME}_rroom2 PROPERTIES OUTPUT_NAME rroom2 PREFIX "")
target_link_libraries(${PROJECT_NAME}_rroom2
  ${catkin_LIBRARIES}
)

# rroom3 Executable
add_executable(${PROJECT_NAME}_rroom3 src/rroom3.cpp)
set_target_properties(${PROJECT_NAME}_rroom3 PROPERTIES OUTPUT_NAME rroom3 PREFIX "")
target_link_libraries(${PROJECT_NAME}_rroom3
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
  ${PROJECT_NAME}_rroom1
  ${PROJECT_NAME}_rroom2
  ${PROJECT_NAME}_rroom3
#  ${PROJECT_NAME}_NAME
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
