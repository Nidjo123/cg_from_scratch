#include <gtest/gtest.h>

#include <math/Vector.h>

TEST(TestVector, MultiplyByScalar) {
  const Vector3f v{1, 2, 3};
  const Vector3f w = v * 2;
  EXPECT_EQ(w[0], 2);
  EXPECT_EQ(w[1], 4);
  EXPECT_EQ(w[2], 6);
}

TEST(TestVector, DivideByScalar) {
  const Vector3f v{3, 4, 6};
  const Vector3f w = v / 3.0;
  EXPECT_EQ(w[0], 1.0);
  EXPECT_EQ(w[1], 4.0 / 3.0);
  EXPECT_EQ(w[2], 2.0);
}
