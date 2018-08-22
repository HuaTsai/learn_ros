#include <ros/ros.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include <geometry_msgs/TransformStamped.h>
#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "interpolate");
  ros::NodeHandle nh;
  ros::Rate rate(3);
  double x, y, z, roll, pitch, yaw;
  tf2_ros::Buffer tfBuffer;
  tf2_ros::TransformListener tfListener(tfBuffer);
  geometry_msgs::TransformStamped trs;
  ros::Rate(0.3).sleep();
  while (ros::ok()) {
    ros::Time now = ros::Time::now();
    trs = tfBuffer.lookupTransform("world", now, "base_link", now, "world", ros::Duration(3));

    x = trs.transform.translation.x;
    y = trs.transform.translation.y;
    z = trs.transform.translation.z;
    tf2::Quaternion q(trs.transform.rotation.x, trs.transform.rotation.y,
                      trs.transform.rotation.z, trs.transform.rotation.w);
    tf2::Matrix3x3(q).getRPY(roll, pitch, yaw);

    ROS_INFO("[inte] time %ld: %f, %f, %f, %f, %f, %f", trs.header.stamp.toNSec(), x, y, z, roll, pitch, yaw);
    rate.sleep();
  }
}