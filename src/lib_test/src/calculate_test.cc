#include "lib_test/calculate.h"
#include <gtest/gtest.h>

namespace lib_test {
  TEST(CalculateTest, ShouldPass) {
    ASSERT_EQ(5, Add(2, 3));
    ASSERT_EQ(-1, Minus(2, 3));
    ASSERT_EQ(6, Multiply(2, 3));
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}