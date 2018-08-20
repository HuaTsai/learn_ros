#include "lib_test/rectangle.h"
#include <gtest/gtest.h>

namespace lib_test {
  TEST(AreaTest, ShouldPass) {
    Rectangle rec(2, 3);
    ASSERT_EQ(6, rec.area());
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}