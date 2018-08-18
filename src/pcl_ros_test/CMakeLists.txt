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

add_executable(pcd_read src/pcd_read.cc)
add_executable(pcd_readandpub src/pcd_readandpub.cc)
add_executable(pcd_write src/pcd_write.cc)
add_executable(fake_data src/fake_data.cc)
add_executable(voxel_grid src/voxel_grid.cc)
add_executable(ndt src/ndt.cc)

target_link_libraries(pcd_read ${catkin_LIBRARIES})
target_link_libraries(pcd_readandpub ${catkin_LIBRARIES})
target_link_libraries(pcd_write ${catkin_LIBRARIES})
target_link_libraries(fake_data ${catkin_LIBRARIES})
target_link_libraries(voxel_grid ${catkin_LIBRARIES})
target_link_libraries(ndt ${catkin_LIBRARIES})