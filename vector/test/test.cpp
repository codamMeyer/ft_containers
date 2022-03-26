#include "../Vector.hpp"
#include <gtest/gtest.h>
#include <iostream>

class EmptyVectorTest : public ::testing::Test {
public:
  typedef ft::vector<int>::difference_type difference_type;

  EmptyVectorTest() : ftConstVec(ftVec), stdConstVec(stdVec){};

  ft::vector<int> ftVec;
  const ft::vector<int> &ftConstVec;

  std::vector<int> stdVec;
  const std::vector<int> &stdConstVec;

};

TEST_F(EmptyVectorTest, atInvalidPos) {
  EXPECT_THROW(ftVec.at(0), std::out_of_range);
  EXPECT_THROW(ftConstVec.at(0), std::out_of_range);
}
TEST_F(EmptyVectorTest, empty) { EXPECT_EQ(ftConstVec.empty(), stdConstVec.empty()); }

TEST_F(EmptyVectorTest, size) { EXPECT_EQ(ftConstVec.size(), stdConstVec.size()); }

TEST_F(EmptyVectorTest, maxSize) {
  EXPECT_EQ(ftConstVec.max_size(), stdConstVec.max_size());
}

TEST_F(EmptyVectorTest, capacity) { EXPECT_EQ(ftConstVec.capacity(), stdConstVec.capacity()); }

TEST_F(EmptyVectorTest, pushBack) {
  EXPECT_NO_THROW(ftVec.push_back(2));
  EXPECT_NO_THROW(stdVec.push_back(2));

  EXPECT_EQ(ftVec.capacity(), stdVec.capacity());
  EXPECT_EQ(ftVec.size(), stdVec.size());
  EXPECT_EQ(ftVec.at(0), stdVec.at(0));
}

class VectorTest : public ::testing::Test {
public:
  typedef ft::vector<int>::size_type size_type;

  VectorTest() : ftVec(1, 5), ftConstVec(ftVec), stdVec(1, 5), stdConstVec(stdVec) {};

  ft::vector<int> ftVec;
  const ft::vector<int> &ftConstVec;

   std::vector<int> stdVec;
  const std::vector<int> &stdConstVec;
};

TEST_F(VectorTest, at) {
  EXPECT_EQ(ftVec.at(0), stdVec.at(0));
  EXPECT_EQ(ftConstVec.at(0), stdConstVec.at(0));
}

TEST_F(VectorTest, operatorIndex) {
  EXPECT_EQ(ftVec[0], stdVec[0]);
  EXPECT_EQ(ftConstVec[0], stdConstVec[0]);
}

TEST_F(VectorTest, front) {
  ftVec.push_back(1);
  stdVec.push_back(1);
  EXPECT_EQ(ftVec.front(), stdVec.front());
  EXPECT_EQ(ftConstVec.front(), stdConstVec.front());
}

TEST_F(VectorTest, back) {
  ftVec.push_back(1);
  stdVec.push_back(1);
  EXPECT_EQ(ftVec.back(), stdVec.back());
  EXPECT_EQ(ftConstVec.back(), stdConstVec.back());
}

TEST_F(VectorTest, data) {
  ftVec.push_back(1);
  stdVec.push_back(1);
  EXPECT_EQ(ftVec.front(), stdVec.front());
  EXPECT_EQ(ftConstVec.front(), stdConstVec.front());
}

TEST_F(VectorTest, nonEmpty) { EXPECT_EQ(ftVec.empty(), stdVec.empty()); }

TEST_F(VectorTest, sizeOneElement) { EXPECT_EQ(ftVec.size(), stdVec.size()); }

TEST_F(VectorTest, capacity) {  
  EXPECT_EQ(
  ftVec.capacity(), stdVec.capacity()); }

TEST_F(VectorTest, reserveInvalidCapacity) {
  const size_type input = std::numeric_limits<size_type>::max();
  EXPECT_THROW(ftVec.reserve(input), std::length_error);
  EXPECT_THROW(stdVec.reserve(input), std::length_error);
}

TEST_F(VectorTest, reserveValidCapacity) {
  ftVec.reserve(10);
  stdVec.reserve(10);
  EXPECT_EQ(ftVec.capacity(), stdVec.capacity());
  EXPECT_EQ(ftVec.at(0), stdVec.at(0));
}

TEST_F(VectorTest, pushBackWithoutCapacity) {
  ftVec.push_back(2);
  stdVec.push_back(2);
  EXPECT_EQ(ftVec.at(0), stdVec.at(0));
  EXPECT_EQ(ftVec.at(1), stdVec.at(1));
  EXPECT_EQ(ftVec.size(), stdVec.size());
  EXPECT_EQ(ftVec.capacity(), stdVec.capacity());
}

TEST_F(VectorTest, pushBackWithCapacity) {
  ftVec.reserve(3);
  ftVec.push_back(2);
  ftVec.push_back(3);
  
  stdVec.reserve(3);
  stdVec.push_back(2);
  stdVec.push_back(3);
  
  EXPECT_EQ(ftVec.at(0), stdVec.at(0));
  EXPECT_EQ(ftVec.at(1), stdVec.at(1));
  EXPECT_EQ(ftVec.at(2), stdVec.at(2));
  EXPECT_EQ(ftVec.size(), stdVec.size());
  EXPECT_EQ(ftVec.capacity(), stdVec.capacity());
}

TEST_F(VectorTest, popBack) {
  ftVec.push_back(100);
  stdVec.push_back(100);

  EXPECT_EQ(ftVec.back(), stdVec.back());
  EXPECT_EQ(ftVec.size(), stdVec.size());
  EXPECT_EQ(ftVec.capacity(), stdVec.capacity());

  ftVec.pop_back();
  stdVec.pop_back();
}

TEST_F(VectorTest, popBackLastOneElementContainer) {
  EXPECT_EQ(ftVec.back(), stdVec.back());
  EXPECT_EQ(ftVec.size(), stdVec.size());
  EXPECT_EQ(ftVec.capacity(), stdVec.capacity());

  ftVec.pop_back();
  stdVec.pop_back();

  EXPECT_EQ(ftVec.empty(), stdVec.empty());
  EXPECT_EQ(ftVec.size(), stdVec.size());
  EXPECT_EQ(ftVec.capacity(), stdVec.capacity());
}

TEST_F(VectorTest, resizeSameSize) {
  ftVec.resize(1);
  stdVec.resize(1);

  EXPECT_EQ(ftVec.empty(), stdVec.empty());
  EXPECT_EQ(ftVec.size(), stdVec.size());
  EXPECT_EQ(ftVec.capacity(), stdVec.capacity());
  EXPECT_EQ(ftVec.at(0), stdVec.at(0));
}

TEST_F(VectorTest, resizeWithoutValueAndBiggerThanOriginalSize) {
  ftVec.resize(5);
  stdVec.resize(5);

  EXPECT_EQ(ftVec.empty(), stdVec.empty());
  EXPECT_EQ(ftVec.size(), stdVec.size());
  EXPECT_EQ(ftVec.capacity(), stdVec.capacity());
  EXPECT_EQ(ftVec.at(0), stdVec.at(0));
  EXPECT_EQ(ftVec.at(1), stdVec.at(1));
  EXPECT_EQ(ftVec.at(2), stdVec.at(2));
  EXPECT_EQ(ftVec.at(3), stdVec.at(3));
  EXPECT_EQ(ftVec.at(4), stdVec.at(4));
}

TEST_F(VectorTest, resizeSmallerThanOriginal) {
  for (int i = 0; i < 10; ++i)
  {
    ftVec.push_back(3);
    stdVec.push_back(3);
  }

  ftVec.resize(5);
  stdVec.resize(5);

  EXPECT_EQ(ftVec.empty(), stdVec.empty());
  EXPECT_EQ(ftVec.size(), stdVec.size());
  EXPECT_EQ(ftVec.capacity(), stdVec.capacity());
  EXPECT_EQ(ftVec.at(0), stdVec.at(0));
  EXPECT_EQ(ftVec.at(1), stdVec.at(1));
  EXPECT_EQ(ftVec.at(2), stdVec.at(2));
  EXPECT_EQ(ftVec.at(3), stdVec.at(3));
  EXPECT_EQ(ftVec.at(4), stdVec.at(4));
  EXPECT_EQ(*ftVec.end(), *stdVec.end());
  
  EXPECT_THROW(stdVec.at(5), std::out_of_range);
  EXPECT_THROW(ftVec.at(5), std::out_of_range);

}


/*************************************************************/
/*                       ITERATORS TEST                      */
/*************************************************************/

class VectorIteratorTest : public VectorTest {
public:
  VectorIteratorTest() {
    ftVec.push_back(7);
    ftVec.push_back(9);

    stdVec.push_back(7);
    stdVec.push_back(9);
  }
};

TEST_F(VectorIteratorTest, begin) {
  EXPECT_EQ(*ftVec.begin(), *stdVec.begin());
  EXPECT_EQ(*ftConstVec.begin(), *stdConstVec.begin());
}

TEST_F(VectorIteratorTest, end) {
  ftVec.end();      // TODO make a real test
  ftConstVec.end(); // TODO make a real test
}

TEST_F(VectorIteratorTest, copyConstructor) {
  ft::vector<int>::iterator it = ftVec.end();
  ft::vector<int>::iterator copy(it);

  EXPECT_EQ(*copy, *it);
}

TEST_F(VectorIteratorTest, assignmentOperator) {
  ft::vector<int>::iterator it = ftVec.end();
  ft::vector<int>::iterator copy;

  copy = it;

  EXPECT_EQ(*copy, *it);
}

TEST_F(VectorIteratorTest, equal) {
  ft::vector<int>::iterator it = ftVec.end();
  const ft::vector<int>::iterator constIt = ftVec.end();

  EXPECT_TRUE(it == ftVec.end());
  EXPECT_TRUE(constIt == ftConstVec.end());
  EXPECT_FALSE(it == ftVec.begin());
  EXPECT_FALSE(constIt == ftConstVec.begin());
}

TEST_F(VectorIteratorTest, notEqual) {
  ft::vector<int>::iterator it = ftVec.end();
  const ft::vector<int>::iterator constIt = ftVec.end();

  EXPECT_TRUE(it != ftVec.begin());
  EXPECT_TRUE(constIt != ftConstVec.begin());
  EXPECT_FALSE(it != ftVec.end());
  EXPECT_FALSE(constIt != ftConstVec.end());
}

TEST_F(VectorIteratorTest, dereference) {
  *ftVec.begin() = 7;

  EXPECT_EQ(*ftVec.begin(), 7);
  EXPECT_EQ(*ftConstVec.begin(), 7);
}

TEST_F(VectorIteratorTest, arrow) {
  ft::vector<std::pair<int, char>> vecPair(1);
  ft::vector<std::pair<int, char>>::iterator it = vecPair.begin();

  it->first = 2;
  it->second = 'a';
  EXPECT_EQ(it->first, 2);
  EXPECT_EQ(it->second, 'a');
}

TEST_F(VectorIteratorTest, preIncrement) {
  ft::vector<int>::iterator it = ftVec.begin();
  ++it;
  EXPECT_EQ(*it, 7);
}

TEST_F(VectorIteratorTest, postIncrement) {
  ft::vector<int>::iterator it = ftVec.begin();
  ft::vector<int>::iterator old = it++;

  EXPECT_EQ(*old, 5);
  EXPECT_EQ(*it, 7);
}

TEST_F(VectorIteratorTest, preDecrement) {
  ft::vector<int>::iterator it = ftVec.end();
  --it;
  EXPECT_EQ(*it, 9);
}

TEST_F(VectorIteratorTest, postDecrement) {
  ft::vector<int>::iterator it = ftVec.end();
  --it;
  ft::vector<int>::iterator old = it--;
  EXPECT_EQ(*old, 9);
  EXPECT_EQ(*it, 7);
}

TEST_F(VectorIteratorTest, preIncrementAndDereference) {
  ft::vector<int>::iterator it = ftVec.begin();
  *++it = 15;

  EXPECT_EQ(*ftVec.begin(), 5);
  EXPECT_EQ(*it, 15);
}

TEST_F(VectorIteratorTest, postIncrementAndDereference) {
  ft::vector<int>::iterator it = ftVec.begin();
  *it++ = 15;

  EXPECT_EQ(*ftVec.begin(), 15);
  EXPECT_EQ(*it, 7);
}

TEST_F(VectorIteratorTest, plusEqual) {
  ft::vector<int>::iterator it = ftVec.begin();
  it += 2;
  EXPECT_EQ(*it, 9);
}

TEST_F(VectorIteratorTest, minusEqual) {
  ft::vector<int>::iterator it = ftVec.end();
  it -= 2;
  EXPECT_EQ(*it, 7);
}

TEST_F(VectorIteratorTest, plus) {
  ft::vector<int>::iterator it = ftVec.begin();
  it = it + 2;
  EXPECT_EQ(*it, 9);
}

TEST_F(VectorIteratorTest, minus) {
  ft::vector<int>::iterator it = ftVec.end();
  it = it - 2;
   EXPECT_EQ(*it, 7);
}
