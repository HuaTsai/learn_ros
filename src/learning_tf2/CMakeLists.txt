cmake_minimum_required(VERSION 2.8.3)
project(learning_tf2)

set(CMAKE_CXX_STANDARD 11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  tf2
  tf2_ros
  turtlesim
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(static_turtle_tf2_broadcaster src/static_turtle_tf2_broadcaster.cc)

add_executable(turtle_tf2_broadcaster src/turtle_tf2_broadcaster.cc)

add_executable(turtle_tf2_listener src/turtle_tf2_listener.cc)

add_executable(frame_tf2_broadcaster src/frame_tf2_broadcaster.cc)

target_link_libraries(static_turtle_tf2_broadcaster ${catkin_LIBRARIES})

target_link_libraries(turtle_tf2_broadcaster ${catkin_LIBRARIES})

target_link_libraries(turtle_tf2_listener ${catkin_LIBRARIES})

target_link_libraries(frame_tf2_broadcaster ${catkin_LIBRARIES})

install(FILES
  start_demo.launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)