#include "lib_test/talker.h"
#include <gtest/gtest.h>
#include <ros/ros.h>
#include <thread>

class TestSuite : public ::testing::Test {
 public:
  TestSuite() {
    nh_ = ros::NodeHandle();
    pub_ = nh_.advertise<std_msgs::String>("talker_test", 0);
  }

  void SetUp() {
    // "rostopic echo talker_test" to see result
    // while(pub_.getNumSubscribers() != 1) {}
  }
  void Publish(std_msgs::String msg) {
    pub_.publish(msg);
  }
  
 private:
  ros::NodeHandle nh_;
  ros::Publisher pub_;
};

TEST_F(TestSuite, First) {
  ros::NodeHandle nh;
  Talker talker;
  ros::Subscriber sub = nh.subscribe("talker_test", 0, &Talker::cb, &talker);

  std_msgs::String msg;
  msg.data = "str1";
  Publish(msg);
  talker.WaitForMessage();
  EXPECT_EQ(talker.msg(), msg.data);

  msg.data = "str2";
  Publish(msg);
  talker.WaitForMessage();
  EXPECT_EQ(talker.msg(), msg.data);
}

TEST_F(TestSuite, Second) {
  ros::NodeHandle nh;
  Talker talker;
  ros::Subscriber sub = nh.subscribe("talker_test", 0, &Talker::cb, &talker);
  
  std_msgs::String msg;
  msg.data = "str3";
  Publish(msg);
  talker.WaitForMessage();
  EXPECT_EQ(talker.msg(), msg.data);

  msg.data = "str4";
  Publish(msg);
  talker.WaitForMessage();
  EXPECT_EQ(talker.msg(), msg.data);
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  ros::init(argc, argv, "talker_test");
  return RUN_ALL_TESTS();
}