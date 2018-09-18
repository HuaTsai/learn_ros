#include "lib_test/rectangle.h"
#include <iostream>

namespace lib_test {
namespace {
  void printresult(int result) {
    std::cout << "Area: " << result << std::endl;
  }
}

  Rectangle::Rectangle() : length_(0), width_(0) {}

  Rectangle::Rectangle(int length, int width) : length_(length), width_(width) {}

  int Rectangle::area() { return length_ * width_; }

  void Rectangle::print() { printresult(area()); }
}