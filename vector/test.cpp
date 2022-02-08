#include "Vector.hpp"
#include <gtest/gtest.h>

class EmptyVectorTest : public ::testing::Test {
public:
  typedef ft::vector<int>::difference_type difference_type;
  ft::vector<int> vec;
};

TEST_F(EmptyVectorTest, empty) { EXPECT_TRUE(vec.empty()); }
TEST_F(EmptyVectorTest, size) { EXPECT_EQ(vec.size(), 0); }
TEST_F(EmptyVectorTest, maxSize) {
  EXPECT_EQ(vec.max_size(), std::numeric_limits<difference_type>::max());
}
TEST_F(EmptyVectorTest, capacity) { EXPECT_EQ(vec.capacity(), 0); }
TEST_F(EmptyVectorTest, pushBack) {
  EXPECT_NO_THROW(vec.push_back(2));
  EXPECT_EQ(vec.size(), 1);
}

class VectorTest : public ::testing::Test {
public:
  typedef ft::vector<int>::size_type size_type;
  VectorTest() : vec(1){};
  ft::vector<int> vec;
};

TEST_F(VectorTest, nonEmpty) { EXPECT_FALSE(vec.empty()); }
TEST_F(VectorTest, sizeOneElement) { EXPECT_EQ(vec.size(), 1); }
TEST_F(VectorTest, capacity) { EXPECT_EQ(vec.capacity(), 1); }
TEST_F(VectorTest, reserveInvalidCapacity) {
  const size_type input = std::numeric_limits<size_type>::max();
  EXPECT_THROW(vec.reserve(input), std::length_error);
}

TEST_F(VectorTest, reserveValidCapacity) {
  vec.reserve(10);
  EXPECT_EQ(vec.capacity(), 10);
}
