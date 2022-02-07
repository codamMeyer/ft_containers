#include "Vector.hpp"
#include <gtest/gtest.h>

class EmptyVectorTest : public ::testing::Test {
public:
  ft::vector<int> vec;
};

TEST_F(EmptyVectorTest, empty) { EXPECT_TRUE(vec.empty()); }
TEST_F(EmptyVectorTest, sizeZero) { EXPECT_EQ(vec.size(), 0); }

class VectorTest : public ::testing::Test {
public:
  VectorTest() : vec(1){};
  ft::vector<int> vec;
};

TEST_F(VectorTest, nonEmpty) { EXPECT_FALSE(vec.empty()); }
TEST_F(VectorTest, sizeOneElement) { EXPECT_EQ(vec.size(), 1); }