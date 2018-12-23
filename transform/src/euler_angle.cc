#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <iostream>
#include <tf2/LinearMath/Transform.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <tf2_eigen/tf2_eigen.h>

Eigen::Matrix4d TransformMsgToMatrix4d(
    const geometry_msgs::Transform &msg) {
  Eigen::Isometry3d mtx = tf2::transformToEigen(msg);
  return mtx.matrix().cast<double>();
}

int main(int argc, char **argv) {
  double x = 2.2;
  double y = 4.4;
  double z = 6.6;
  double roll = 0.7;
  double pitch = 1.5;
  double yaw = 2.1;

  /* tf2::Quaternion::setRPY(roll, pitch, yaw) */
  Eigen::Isometry3d tr1 =
      Eigen::Translation3d(x, y, z) *
      Eigen::AngleAxisd(yaw, Eigen::Vector3d::UnitZ()) *
      Eigen::AngleAxisd(pitch, Eigen::Vector3d::UnitY()) *
      Eigen::AngleAxisd(roll, Eigen::Vector3d::UnitX());
  std::cout << "setRPY:" << std::endl;
  std::cout << tr1.matrix().cast<double>() << std::endl;
  tf2::Quaternion q;
  q.setRPY(roll, pitch, yaw);
  tf2::Vector3 v(x, y, z);
  tf2::Transform tr2_(q, v);
  geometry_msgs::Transform tr2 = tf2::toMsg(tr2_);
  auto tr2_mtx = TransformMsgToMatrix4d(tr2);
  std::cout << tr2_mtx << std::endl << std::endl;

  /* tf2::Quaternion::setEuler(yaw, pitch, roll) */
  std::cout << "setEuler:" << std::endl;
  Eigen::Isometry3d tr3 =
      Eigen::Translation3d(x, y, z) *
      Eigen::AngleAxisd(yaw, Eigen::Vector3d::UnitY()) *
      Eigen::AngleAxisd(pitch, Eigen::Vector3d::UnitX()) *
      Eigen::AngleAxisd(roll, Eigen::Vector3d::UnitZ());
  std::cout << tr3.matrix().cast<double>() << std::endl;
  q.setEuler(yaw, pitch, roll);
  tr2_.setRotation(q);
  tr2 = tf2::toMsg(tr2_);
  tr2_mtx = TransformMsgToMatrix4d(tr2);
  std::cout << tr2_mtx << std::endl;
}
