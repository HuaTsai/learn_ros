cmake_minimum_required(VERSION 2.8.3)
project(transform)

set(CMAKE_CXX_STANDARD 11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  tf
  pcl_ros
)

find_package(Eigen3 REQUIRED)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${EIGEN3_INCLUDE_DIRS}
)

add_executable(send_tf src/send_tf.cc)
add_executable(interpolate src/interpolate.cc)
add_executable(euler_angle src/euler_angle.cc)
add_executable(pairwise_pc src/pairwise_pc.cc)

target_link_libraries(send_tf ${catkin_LIBRARIES})
target_link_libraries(interpolate ${catkin_LIBRARIES})
target_link_libraries(euler_angle ${catkin_LIBRARIES})
target_link_libraries(pairwise_pc ${catkin_LIBRARIES})
