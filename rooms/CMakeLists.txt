cmake_minimum_required(VERSION 2.8.3)
project(rooms)

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

# room1 Executable
add_executable(${PROJECT_NAME}_room1 src/room1.cpp)
set_target_properties(${PROJECT_NAME}_room1 PROPERTIES OUTPUT_NAME room1 PREFIX "")
target_link_libraries(${PROJECT_NAME}_room1
  ${catkin_LIBRARIES}
)

# room2 Executable
add_executable(${PROJECT_NAME}_room2 src/room2.cpp)
set_target_properties(${PROJECT_NAME}_room2 PROPERTIES OUTPUT_NAME room2 PREFIX "")
target_link_libraries(${PROJECT_NAME}_room2
  ${catkin_LIBRARIES}
)

# room3 Executable
add_executable(${PROJECT_NAME}_room3 src/room3.cpp)
set_target_properties(${PROJECT_NAME}_room3 PROPERTIES OUTPUT_NAME room3 PREFIX "")
target_link_libraries(${PROJECT_NAME}_room3
  ${catkin_LIBRARIES}
)


# Navigation Executable
add_executable(${PROJECT_NAME}_Navigation src/Navigation.cpp)
set_target_properties(${PROJECT_NAME}_Navigation PROPERTIES OUTPUT_NAME Navigation PREFIX "")
target_link_libraries(${PROJECT_NAME}_Navigation
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
  ${PROJECT_NAME}_room1
  ${PROJECT_NAME}_room2
  ${PROJECT_NAME}_room3
  ${PROJECT_NAME}_Navigation
#  ${PROJECT_NAME}_NAME
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)