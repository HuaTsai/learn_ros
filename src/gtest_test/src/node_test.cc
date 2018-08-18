#include "gtest_test/node.h"
#include <ros/ros.h>
#include <gtest/gtest.h>
#include <std_msgs/String.h>
#include <thread>

void pub_func() {
  ros::NodeHandle nh;
  ros::Publisher pub = nh.advertise<std_msgs::String>("topic", 10);
  std_msgs::String msg;
  ros::Rate rate(2);
  for (int idx = 1; idx < 10; ++idx) {
    msg.data = "string" + std::to_string(idx);
    pub.publish(msg);
    rate.sleep();
  }
}

TEST(SubscribeTest, ShouldPass) {
  ros::NodeHandle nh;
  Node node;
  ros::Subscriber sub = nh.subscribe("topic", 100, &Node::cb, &node);
  std::thread mThread(pub_func);
  ros::Rate(0.5).sleep();
  ros::spinOnce();
  ASSERT_EQ(node.msg(), "string" + std::to_string(node.count()));
  mThread.join();
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  ros::init(argc, argv, "node_test");
  return RUN_ALL_TESTS();
}