cmake_minimum_required(VERSION 2.8.3)
project(transform)

set(CMAKE_CXX_STANDARD 11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  tf
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(send_tf src/send_tf.cc)
add_executable(interpolate src/interpolate.cc)

target_link_libraries(send_tf ${catkin_LIBRARIES})
target_link_libraries(interpolate ${catkin_LIBRARIES})