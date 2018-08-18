#include <ros/ros.h>
#include <pcl_ros/io/pcd_io.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "pcd_read");
  if (argc != 2) {
    ROS_FATAL("usage: rosrun pcl_ros_test pcd_read <pcd_file>");
    return -1;
  }
  ros::NodeHandle nh;
  sensor_msgs::PointCloud2 pc;
  pcl::io::loadPCDFile(argv[1], pc);
  ROS_INFO("read pcd file %s (sensor_msgs)", argv[1]);
  ROS_INFO_STREAM(std::endl << pc);

  pcl::PointCloud<pcl::PointXYZI> pc2;
  pcl::io::loadPCDFile(argv[1], pc2);
  ROS_INFO("read pcd file %s (pcl::PointCloud)", argv[1]);
  for (int i = 0; i < pc2.size(); ++i) {
    ROS_INFO("%f, %f, %f, %f", pc2.points[i].x, pc2.points[i].y, pc2.points[i].z, pc2.points[i].intensity);
  }
}