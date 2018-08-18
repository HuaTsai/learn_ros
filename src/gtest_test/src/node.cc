#include "gtest_test/node.h"
#include <ros/ros.h>
#include <std_msgs/String.h>

Node::Node() : count_(0), msg_("default"){}

Node::~Node(){};

std::string Node::msg() {
  return msg_;
}

int Node::count() {
  return count_;
}

void Node::cb(const std_msgs::String &msg) {
  ++count_;
  msg_ = msg.data;
  ROS_INFO("Get %d msg: %s", count_, msg.data.c_str());
}