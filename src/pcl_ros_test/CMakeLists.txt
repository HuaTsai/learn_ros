cmake_minimum_required(VERSION 2.8.3)
project(pcl_ros_test)

set(CMAKE_CXX_STANDARD 11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  pcl_ros
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(pcd_write src/pcd_write.cc)

target_link_libraries(pcd_write ${catkin_LIBRARIES})