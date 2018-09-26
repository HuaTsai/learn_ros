#include <std_msgs/String.h>
#include <ros/ros.h>

class Talker {
 public:
  Talker();
  void cb(const std_msgs::String &msg);
  std::string msg();
  void WaitForMessage();
 private:
  std::string msg_;
  bool received_;
};