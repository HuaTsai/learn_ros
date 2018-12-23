cmake_minimum_required(VERSION 2.8.3)
project(qt_test)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(catkin REQUIRED
  COMPONENTS
    roscpp
)

find_package(Qt5 REQUIRED
  COMPONENTS
    Core
    Gui
    Widgets
)

catkin_package()

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

qt5_wrap_ui(UI_HEADERS ui/qt_test.ui)

set(
  ALL_SRCS
    include/qt_test/qt_test.h
    src/qt_test_main.cc
    src/qt_test.cc
)

add_executable(qt_test_main ${ALL_SRCS} ${UI_HEADERS})
target_link_libraries(qt_test_main ${catkin_LIBRARIES} Qt5::Core Qt5::Widgets Qt5::Gui)
