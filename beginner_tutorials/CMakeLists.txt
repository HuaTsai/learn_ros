cmake_minimum_required(VERSION 2.8.3)
project(beginner_tutorials)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Release)

find_package(catkin REQUIRED
  COMPONENTS
    roscpp
    rospy
    std_msgs
    message_generation    
)

add_service_files(
  FILES
    AddTwoInts.srv
)

generate_messages(
  DEPENDENCIES
    std_msgs
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

file(GLOB_RECURSE ALL_SRCS "*.cc")

if (CATKIN_ENABLE_TESTING)
  foreach(FILE_PATH ${ALL_SRCS})
    get_filename_component(FILENAME ${FILE_PATH} NAME_WE)
    add_executable(${FILENAME} ${FILE_PATH})
    target_link_libraries(${FILENAME} ${catkin_LIBRARIES})
    add_dependencies(${FILENAME} beginner_tutorials_gencpp)
  endforeach(FILE_PATH)
endif()