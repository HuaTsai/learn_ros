#include <ros/ros.h>
#include <pcl_ros/io/pcd_io.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "pcd_readandpub");
  if (argc != 2) {
    ROS_FATAL("usage: rosrun pcl_ros_test pcd_readandpub <pcd_file>");
    return -1;
  }
  ros::NodeHandle nh;
  ros::Rate rate(0.3);
  ros::Publisher pub = nh.advertise<sensor_msgs::PointCloud2>("pc", 10);

  pcl::PointCloud<pcl::PointXYZ>::Ptr pc(new pcl::PointCloud<pcl::PointXYZ>);

  pcl::io::loadPCDFile(argv[1], *pc);
  pc->header.frame_id = "pc";
  while(ros::ok()) {
    pub.publish(pc);
    rate.sleep();
  }
}