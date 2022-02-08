#include "Vector.hpp"
#include <gtest/gtest.h>

class EmptyVectorTest : public ::testing::Test {
public:
  typedef ft::vector<int>::difference_type difference_type;

  EmptyVectorTest() : const_vec(vec){};

  ft::vector<int> vec;
  const ft::vector<int> &const_vec;
};

TEST_F(EmptyVectorTest, atInvalidPos) {
  EXPECT_THROW(vec.at(0), std::out_of_range);
  EXPECT_THROW(const_vec.at(0), std::out_of_range);
}
TEST_F(EmptyVectorTest, empty) { EXPECT_TRUE(const_vec.empty()); }

TEST_F(EmptyVectorTest, size) { EXPECT_EQ(const_vec.size(), 0); }

TEST_F(EmptyVectorTest, maxSize) {
  EXPECT_EQ(const_vec.max_size(), std::numeric_limits<difference_type>::max());
}

TEST_F(EmptyVectorTest, capacity) { EXPECT_EQ(const_vec.capacity(), 0); }

TEST_F(EmptyVectorTest, pushBack) {
  EXPECT_NO_THROW(vec.push_back(2));
  EXPECT_EQ(vec.capacity(), 1);
  EXPECT_EQ(vec.size(), 1);
  EXPECT_EQ(vec.at(0), 2);
}

class VectorTest : public ::testing::Test {
public:
  typedef ft::vector<int>::size_type size_type;

  VectorTest() : vec(1, 5), const_vec(vec){};

  ft::vector<int> vec;
  const ft::vector<int> &const_vec;
};

TEST_F(VectorTest, at) {
  EXPECT_EQ(vec.at(0), 5);
  EXPECT_EQ(const_vec.at(0), 5);
}

TEST_F(VectorTest, operatorIndex) {
  EXPECT_EQ(vec[0], 5);
  EXPECT_EQ(const_vec[0], 5);
}

TEST_F(VectorTest, front) {
  vec.push_back(1);
  EXPECT_EQ(vec.front(), 5);
  EXPECT_EQ(const_vec.front(), 5);
}

TEST_F(VectorTest, back) {
  vec.push_back(1);
  EXPECT_EQ(vec.back(), 1);
  EXPECT_EQ(const_vec.back(), 1);
}

TEST_F(VectorTest, data) {
  vec.push_back(1);
  EXPECT_EQ(*vec.data(), vec.front());
  EXPECT_EQ(*const_vec.data(), vec.front());
}

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
  EXPECT_EQ(vec.at(0), 5);
}

TEST_F(VectorTest, pushBackWithoutCapacity) {
  vec.push_back(2);
  EXPECT_EQ(vec.at(0), 5);
  EXPECT_EQ(vec.at(1), 2);
  EXPECT_EQ(vec.size(), 2);
  EXPECT_EQ(vec.capacity(), 2);
}
TEST_F(VectorTest, pushBackWithCapacity) {
  vec.reserve(3);
  vec.push_back(2);
  vec.push_back(3);
  EXPECT_EQ(vec.at(0), 5);
  EXPECT_EQ(vec.at(1), 2);
  EXPECT_EQ(vec.at(2), 3);
  EXPECT_EQ(vec.size(), 3);
  EXPECT_EQ(vec.capacity(), 3);
}
