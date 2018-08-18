cmake_minimum_required(VERSION 2.8.3)
project(gtest_test)

set(CMAKE_CXX_STANDARD 11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
)

catkin_package()

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_library(libcalculator src/calculator.cc)

if (CATKIN_ENABLE_TESTING)
  catkin_add_gtest(calculator_test src/calculator_test.cc)
  target_link_libraries(calculator_test ${catkin_LIBRARIES} libcalculator)
endif()