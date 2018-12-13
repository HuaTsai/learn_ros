if [ $# -ne 1 ]
then
  echo "Usage: $0 <pkg_name>"
  exit $E_BADARGS
fi

mkdir -p $1/include/$1
mkdir -p $1/src
echo "cmake_minimum_required(VERSION 2.8.3)
project($1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Release)

find_package(catkin REQUIRED
  COMPONENTS
    roscpp
    rospy
)

catkin_package()

include_directories(
  include
  \${catkin_INCLUDE_DIRS}
)

file(GLOB_RECURSE ALL_SRCS \"*.cc\")
file(GLOB_RECURSE ALL_TESTS \"*_test.cc\")
file(GLOB_RECURSE ALL_MAINS \"*_main.cc\")
list(REMOVE_ITEM ALL_SRCS \${ALL_MAINS})
list(REMOVE_ITEM ALL_SRCS \${ALL_TESTS})

add_library(\${PROJECT_NAME} \${ALL_SRCS})
target_link_libraries(\${PROJECT_NAME} \${catkin_LIBRARIES})

foreach(FILE_PATH \${ALL_MAINS})
  get_filename_component(FILENAME \${FILE_PATH} NAME_WE)
  add_executable(\${FILENAME} \${FILE_PATH})
  target_link_libraries(\${FILENAME} \${catkin_LIBRARIES} \${PROJECT_NAME})
endforeach(FILE_PATH)

if (CATKIN_ENABLE_TESTING)
  foreach(FILE_PATH \${ALL_TESTS})
    get_filename_component(FILENAME \${FILE_PATH} NAME_WE)
    catkin_add_gtest(\${FILENAME} \${FILE_PATH})
    target_link_libraries(\${FILENAME} \${catkin_LIBRARIES} \${PROJECT_NAME})
  endforeach(FILE_PATH)
endif()

install(
  TARGETS \${PROJECT_NAME}
  ARCHIVE DESTINATION \${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION \${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION \${CATKIN_GLOBAL_BIN_DESTINATION}
)

install(
  DIRECTORY include/\${PROJECT_NAME}/
  DESTINATION \${CATKIN_PACKAGE_INCLUDE_DESTINATION}
)

# CATKIN_PACKAGE_INCLUDE_DESTINATION: include/tt
# CATKIN_PACKAGE_SHARE_DESTINATION: share/tt
# CATKIN_PACKAGE_BIN_DESTINATION: lib/tt
# CATKIN_PACKAGE_LIB_DESTINATION: lib
# CATKIN_GLOBAL_INCLUDE_DESTINATION: include
# CATKIN_GLOBAL_SHARE_DESTINATION: share
# CATKIN_GLOBAL_BIN_DESTINATION: bin
# CATKIN_GLOBAL_LIB_DESTINATION: lib" > $1/CMakeLists.txt

echo "<?xml version=\"1.0\"?>
<package format=\"2\">
  <name>$1</name>
  <version>0.0.0</version>
  <description>The $1 package</description>

  <author email=\"huatsai.eed07g@nctu.edu.tw\">HuaTsai</author>
  <maintainer email=\"huatsai.eed07g@nctu.edu.tw\">HuaTsai</maintainer>
  <license>BSD</license>

  <buildtool_depend>catkin</buildtool_depend>
  <depend>roscpp</depend>
  <depend>rospy</depend>
</package>" > $1/package.xml

echo Succesfully created packge $1
