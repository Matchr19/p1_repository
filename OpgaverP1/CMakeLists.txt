cmake_minimum_required(VERSION 2.8.3)
project(Opgaver)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED
    roscpp
)


## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES Opgaver
#  CATKIN_DEPENDS other_catkin_pkg
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
 ${catkin_INCLUDE_DIRS}
)



## Declare a C++ executable
## With catkin_make all packages are built within a single CMake context
## The recommended prefix ensures that target names across packages don't collide
add_executable(${PROJECT_NAME}_Turtleroundweeee src/Turtleroundweeee.cpp)
set_target_properties(${PROJECT_NAME}_Turtleroundweeee PROPERTIES OUTPUT_NAME Turtleroundweeee PREFIX "")
target_link_libraries(${PROJECT_NAME}_Turtleroundweeee
  ${catkin_LIBRARIES}
)
add_executable(${PROJECT_NAME}_helloworld src/helloworld.cpp)
set_target_properties(${PROJECT_NAME}_helloworld PROPERTIES OUTPUT_NAME helloworld PREFIX "")
target_link_libraries(${PROJECT_NAME}_helloworld
  ${catkin_LIBRARIES}
)
add_executable(${PROJECT_NAME}_functions src/functions.cpp)
set_target_properties(${PROJECT_NAME}_functions PROPERTIES OUTPUT_NAME functions PREFIX "")
target_link_libraries(${PROJECT_NAME}_functions
  ${catkin_LIBRARIES}
)
add_executable(${PROJECT_NAME}_Test src/Test.cpp)
set_target_properties(${PROJECT_NAME}_Test PROPERTIES OUTPUT_NAME Test PREFIX "")
target_link_libraries(${PROJECT_NAME}_Test
  ${catkin_LIBRARIES}
)
add_executable(${PROJECT_NAME}_Smallest src/Smallest.cpp)
set_target_properties(${PROJECT_NAME}_Smallest PROPERTIES OUTPUT_NAME Smallest PREFIX "")
target_link_libraries(${PROJECT_NAME}_Smallest
  ${catkin_LIBRARIES}
)
add_executable(${PROJECT_NAME}_Algorithm src/Algorithm.cpp)
set_target_properties(${PROJECT_NAME}_Algorithm PROPERTIES OUTPUT_NAME Algorithm PREFIX "")
target_link_libraries(${PROJECT_NAME}_Algorithm
  ${catkin_LIBRARIES}
)

add_executable(${PROJECT_NAME}_struct src/struct.cpp)
set_target_properties(${PROJECT_NAME}_struct PROPERTIES OUTPUT_NAME struct PREFIX "")
target_link_libraries(${PROJECT_NAME}_struct
  ${catkin_LIBRARIES}
)
add_executable(${PROJECT_NAME}_Trees src/Trees.cpp)
set_target_properties(${PROJECT_NAME}_Trees PROPERTIES OUTPUT_NAME Trees PREFIX "")
target_link_libraries(${PROJECT_NAME}_Trees
  ${catkin_LIBRARIES}
)


## Specify libraries to link a library or executable target against
 #target_link_libraries(${PROJECT_NAME}_node
 #  ${catkin_LIBRARIES}
 #)


 install(TARGETS
 ${PROJECT_NAME}_Turtleroundweeee
 ${PROJECT_NAME}_helloworld
 ${PROJECT_NAME}_functions
 ${PROJECT_NAME}_Test
 ${PROJECT_NAME}_Smallest
 ${PROJECT_NAME}_Algorithm
 ${PROJECT_NAME}_struct
 ${PROJECT_NAME}_Trees
 RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)