#include <ros/ros.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_ros/transform_broadcaster.h>

int main(int argc, char **argv){
  ros::init(argc, argv, "send_tf");
  ros::NodeHandle nh;
  ros::Rate rate(1);
  tf2_ros::TransformBroadcaster br;
  geometry_msgs::TransformStamped trs;
  float x, y, z, roll, pitch, yaw;
  x = y = z = roll = pitch = yaw = 0.;
  while (ros::ok()) {
    trs.header.stamp = ros::Time::now();
    trs.header.frame_id = "world";
    trs.child_frame_id = "base_link";
    trs.transform.translation.x = x;
    trs.transform.translation.y = y;
    trs.transform.translation.z = z;
    tf2::Quaternion q;
    q.setRPY(roll, pitch, yaw);
    trs.transform.rotation.x = q.x();
    trs.transform.rotation.y = q.y();
    trs.transform.rotation.z = q.z();
    trs.transform.rotation.w = q.w();

    br.sendTransform(trs);
    ROS_INFO("[send] time %ld: %f, %f, %f, %f, %f, %f", trs.header.stamp.toNSec(), x, y, z, roll, pitch, yaw);
    x += 0.5;
    rate.sleep();
  }
}