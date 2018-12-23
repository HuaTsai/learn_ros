#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <iostream>
#include <tf2/LinearMath/Transform.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <tf2_eigen/tf2_eigen.h>
#include <pcl_ros/io/pcd_io.h>
#include <pcl_ros/transforms.h>

Eigen::Matrix4d TransformMsgToMatrix4d(
    const geometry_msgs::Transform &msg) {
  Eigen::Isometry3d mtx = tf2::transformToEigen(msg);
  return mtx.matrix();
}

int main(int argc, char **argv) {
  double x = atof(argv[1]);
  double y = atof(argv[2]);
  double z = atof(argv[3]);
  double roll = atof(argv[4]);
  double pitch = atof(argv[5]);
  double yaw = atof(argv[6]);

  /* tf2::Quaternion::setRPY(roll, pitch, yaw) */
  Eigen::Isometry3d tr =
      Eigen::Translation3d(x, y, z) *
      Eigen::AngleAxisd(yaw, Eigen::Vector3d::UnitZ()) *
      Eigen::AngleAxisd(pitch, Eigen::Vector3d::UnitY()) *
      Eigen::AngleAxisd(roll, Eigen::Vector3d::UnitX());
  std::cout << tr.matrix() << std::endl;

  pcl::PointCloud<pcl::PointXYZ> pc;
  pcl::io::loadPCDFile("p1_1.pcd", pc);
  pcl::transformPointCloud(pc, pc, tr.matrix());
  pcl::io::savePCDFile("result.pcd", pc);
}
