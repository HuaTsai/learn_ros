#include <ros/ros.h>
#include <pcl_ros/io/pcd_io.h>
#include <string>

void cb(const sensor_msgs::PointCloud2::ConstPtr &input) {
  static int idx = 0;
  pcl::io::savePCDFile("pc_" + std::to_string(idx), *input);
  ROS_INFO("save file pc_%d at %ld", idx, input->header.stamp.toNSec());
  idx++;
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "pcd_write");
  if (argc != 2) {
    ROS_FATAL("usage: rosrun pcl_ros_test pcd_write <topic_name>");
    return -1;
  }
  ros::NodeHandle nh;
  ros::Subscriber sub = nh.subscribe<sensor_msgs::PointCloud2>(argv[1], 10, cb);
  ros::spin();
}