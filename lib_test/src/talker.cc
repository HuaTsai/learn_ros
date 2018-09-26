#include "lib_test/talker.h"
Talker::Talker() : received_(false){}

void Talker::cb(const std_msgs::String &msg) {
  msg_ = msg.data;
  received_ = true;
}

std::string Talker::msg() {
  return msg_;
}

void Talker::WaitForMessage() {
  while(!received_) {
    ros::spinOnce();
  }
  received_ = false;
}