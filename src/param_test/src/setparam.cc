#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "setparam");
  ros::NodeHandle nh;
  nh.setParam("integer5", 5);
  nh.setParam("double5", 5.0);
  nh.setParam("string5", "five");
}