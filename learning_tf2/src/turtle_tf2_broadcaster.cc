#include <ros/ros.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>
#include <turtlesim/Pose.h>

std::string turtle_name;

void poseCallback(const turtlesim::PoseConstPtr &msg) {
  static tf2_ros::TransformBroadcaster br;
  geometry_msgs::TransformStamped transformStamped;

  transformStamped.header.stamp = ros::Time::now();
  transformStamped.header.frame_id = "world";
  transformStamped.child_frame_id = turtle_name;
  transformStamped.transform.translation.x = msg->x;
  transformStamped.transform.translation.y = msg->y;
  transformStamped.transform.translation.z = 0.f;
  tf2::Quaternion q;
  q.setRPY(0, 0, msg->theta);
  transformStamped.transform.rotation.x = q.x();
  transformStamped.transform.rotation.y = q.y();
  transformStamped.transform.rotation.z = q.z();
  transformStamped.transform.rotation.w = q.w();

  br.sendTransform(transformStamped);
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "my_tf2_broadcaster");
  ros::NodeHandle nh_private("~");
  if (!nh_private.hasParam("turtle")) {
    if (argc != 2) {
      ROS_ERROR("need turtle name as argument");
      return -1;
    }
    turtle_name = argv[1];
  }
  ros::NodeHandle nh;
  ros::Subscriber sub = nh.subscribe(turtle_name + "/pose", 10, &poseCallback);
  ros::spin();
}