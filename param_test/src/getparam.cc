#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "param_test");
  ros::NodeHandle nh;
  ros::NodeHandle nh_param("~");
  int t1;
  double t2;
  std::string t3;
  // test 1: get global param from launch file
  nh.getParam("integer8", t1);
  nh.getParam("double8", t2);
  nh.getParam("string8", t3);
  ROS_INFO("GET global integer %d", t1);
  ROS_INFO("GET global double %f", t2);
  ROS_INFO("GET global string %s", t3.c_str());

  // test 2a: get node's param from launch file
  std::string nodename = ros::this_node::getName();
  nh.getParam(nodename + "/integer9", t1);
  nh.getParam(nodename + "/double9", t2);
  nh.getParam(nodename + "/string9", t3);
  ROS_INFO("GET node's integer %d", t1);
  ROS_INFO("GET node's double %f", t2);
  ROS_INFO("GET node's string %s", t3.c_str());

  // test 2b: use nh_param to get node's param from launch file
  nh_param.getParam("integer9", t1);
  nh_param.getParam("double9", t2);
  nh_param.getParam("string9", t3);
  ROS_INFO("GET node's integer %d (by nh_param)", t1);
  ROS_INFO("GET node's double %f (by nh_param)", t2);
  ROS_INFO("GET node's string %s (by nh_param)", t3.c_str());

  // test 3: get node's param from yaml file
  nh.getParam(nodename + "/integers/integer3", t1);
  nh.getParam(nodename + "/doubles/double34", t2);
  nh.getParam(nodename + "/strings/stringabc", t3);
  ROS_INFO("GET yaml integer %d", t1);
  ROS_INFO("GET yaml double %f", t2);
  ROS_INFO("GET yaml string %s", t3.c_str());

  // test 4: get param from other node
  while (!nh.getParam("integer5", t1)) { ROS_INFO("try to get integer5..."); }
  while (!nh.getParam("double5", t2)) { ROS_INFO("try to get double5..."); }
  while (!nh.getParam("string5", t3)) { ROS_INFO("try to get string5..."); }
  ROS_INFO("GET integer %d from other node", t1);
  ROS_INFO("GET double %f from other node", t2);
  ROS_INFO("GET string %s from other node", t3.c_str());



  ros::spin();
}