#include <std_msgs/String.h>

class Node {
 public:
  Node();
  ~Node();
  int count();
  std::string msg();
  void cb(const std_msgs::String &msg);
 private:
  int count_;
  std::string msg_;
};