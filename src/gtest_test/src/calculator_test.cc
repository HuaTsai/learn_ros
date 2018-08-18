#include "gtest_test/calculator.h"
#include <gtest/gtest.h>

TEST(AddTest, ShouldPass) {
  Calculator cal;
  ASSERT_EQ(0, cal.Add(0, 0));
  ASSERT_EQ(3, cal.Add(1, 2));
  ASSERT_EQ(-1, cal.Add(1, -2));
}

TEST(MinusTest, ShouldPass) {
  Calculator cal;
  ASSERT_EQ(0, cal.Minus(0, 0));
  ASSERT_EQ(-1, cal.Minus(1, 2));
  ASSERT_EQ(3, cal.Minus(1, -2));
}

TEST(MultiplyTest, ShouldPass) {
  Calculator cal;
  ASSERT_EQ(0, cal.Multiply(0, 0));
  ASSERT_EQ(2, cal.Multiply(1, 2));
  ASSERT_EQ(-2, cal.Multiply(1, -2));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}