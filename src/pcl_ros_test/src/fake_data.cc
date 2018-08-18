#include <ros/ros.h>
#include <pcl_ros/io/pcd_io.h>
#include <random>

int main(int argc, char **argv) {
  ros::init(argc, argv, "fake_data");
  ros::NodeHandle nh;
  std::random_device rd;
  std::default_random_engine gen = std::default_random_engine(rd());
  std::uniform_int_distribution<int> dis(2,8);

  pcl::PointCloud<pcl::PointXYZ> pc;
  pc.width = 5;
  pc.height = 1;
  pc.is_dense = false;
  pc.points.resize(pc.width * pc.height);
  for (int i = 0; i < pc.size(); ++i) {
    pc.points[i].x = dis(gen);
    pc.points[i].y = dis(gen);
    pc.points[i].z = dis(gen);
    ROS_INFO("%f, %f, %f", pc.points[i].x, pc.points[i].y, pc.points[i].z);
  }
}