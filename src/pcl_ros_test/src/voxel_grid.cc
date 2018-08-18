#include <ros/ros.h>
#include <pcl_ros/filters/voxel_grid.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "voxel_grid");
  if (argc != 2) {
    ROS_FATAL("usage: rosrun pcl_ros_test voxel_grid <pcd_file>");
    return -1;
  }
  ros::NodeHandle nh;
  ros::Rate rate(0.3);
  ros::Publisher input_pub = nh.advertise<sensor_msgs::PointCloud2>("input_pc", 10);
  ros::Publisher filtered_pub = nh.advertise<sensor_msgs::PointCloud2>("filtered_pc", 10);

  pcl::PointCloud<pcl::PointXYZ>::Ptr input_pc(new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::PointXYZ>::Ptr filtered_pc(new pcl::PointCloud<pcl::PointXYZ>);

  pcl::io::loadPCDFile(argv[1], *input_pc);
  pcl::VoxelGrid<pcl::PointXYZ> filter;
  filter.setLeafSize(0.2, 0.2, 0.2);
  filter.setInputCloud(input_pc);
  filter.filter(*filtered_pc);
  ROS_INFO("input pc size: %ld", input_pc->size());
  ROS_INFO("filtered pc size: %ld", filtered_pc->size());

  input_pc->header.frame_id = filtered_pc->header.frame_id = "velodyne";
  while(ros::ok()) {
    input_pub.publish(input_pc);
    filtered_pub.publish(filtered_pc);
    rate.sleep();
  }
}