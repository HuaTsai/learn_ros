cmake_minimum_required(VERSION 2.8.3)
project(param_test)

set(CMAKE_CXX_STANDARD 11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(getparam src/getparam.cc)

add_executable(setparam src/setparam.cc)

target_link_libraries(getparam ${catkin_LIBRARIES})

target_link_libraries(setparam ${catkin_LIBRARIES})