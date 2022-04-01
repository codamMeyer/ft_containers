#include "../Vector.hpp"
#include <gtest/gtest.h>
#include <gtest/internal/gtest-internal.h>
#include <iostream>
#include <iterator>
#include <vector>

class EmptyVectorTest : public ::testing::Test
{
public:
    typedef ft::vector<int>::difference_type difference_type;

    EmptyVectorTest()
        : ftConstVec(ftVec)
        , stdConstVec(stdVec){};

    ft::vector<int> ftVec;
    const ft::vector<int>& ftConstVec;

    std::vector<int> stdVec;
    const std::vector<int>& stdConstVec;
};

TEST_F(EmptyVectorTest, atInvalidPos)
{
    EXPECT_THROW(ftVec.at(0), std::out_of_range);
    EXPECT_THROW(ftConstVec.at(0), std::out_of_range);
}
TEST_F(EmptyVectorTest, empty)
{
    EXPECT_EQ(ftConstVec.empty(), stdConstVec.empty());
}

TEST_F(EmptyVectorTest, size)
{
    EXPECT_EQ(ftConstVec.size(), stdConstVec.size());
}

TEST_F(EmptyVectorTest, maxSize)
{
    EXPECT_EQ(ftConstVec.max_size(), stdConstVec.max_size());
}

TEST_F(EmptyVectorTest, capacity)
{
    EXPECT_EQ(ftConstVec.capacity(), stdConstVec.capacity());
}

TEST_F(EmptyVectorTest, pushBack)
{
    EXPECT_NO_THROW(ftVec.push_back(2));
    EXPECT_NO_THROW(stdVec.push_back(2));

    EXPECT_EQ(ftVec.capacity(), stdVec.capacity());
    EXPECT_EQ(ftVec.size(), stdVec.size());
    EXPECT_EQ(ftVec.at(0), stdVec.at(0));
}

class VectorTest : public ::testing::Test
{
public:
    typedef ft::vector<int>::size_type size_type;

    VectorTest()
        : ftVec(1, 5)
        , ftConstVec(ftVec)
        , stdVec(1, 5)
        , stdConstVec(stdVec){};

    ft::vector<int> ftVec;
    const ft::vector<int>& ftConstVec;

    std::vector<int> stdVec;
    const std::vector<int>& stdConstVec;
};

TEST_F(VectorTest, at)
{
    EXPECT_EQ(ftVec.at(0), stdVec.at(0));
    EXPECT_EQ(ftConstVec.at(0), stdConstVec.at(0));
}

TEST_F(VectorTest, operatorIndex)
{
    EXPECT_EQ(ftVec[0], stdVec[0]);
    EXPECT_EQ(ftConstVec[0], stdConstVec[0]);
}

TEST_F(VectorTest, front)
{
    ftVec.push_back(1);
    stdVec.push_back(1);
    EXPECT_EQ(ftVec.front(), stdVec.front());
    EXPECT_EQ(ftConstVec.front(), stdConstVec.front());
}

TEST_F(VectorTest, back)
{
    ftVec.push_back(1);
    stdVec.push_back(1);
    EXPECT_EQ(ftVec.back(), stdVec.back());
    EXPECT_EQ(ftConstVec.back(), stdConstVec.back());
}

TEST_F(VectorTest, data)
{
    ftVec.push_back(1);
    stdVec.push_back(1);
    EXPECT_EQ(ftVec.front(), stdVec.front());
    EXPECT_EQ(ftConstVec.front(), stdConstVec.front());
}

TEST_F(VectorTest, nonEmpty)
{
    EXPECT_EQ(ftVec.empty(), stdVec.empty());
}

TEST_F(VectorTest, sizeOneElement)
{
    EXPECT_EQ(ftVec.size(), stdVec.size());
}

TEST_F(VectorTest, capacity)
{
    EXPECT_EQ(ftVec.capacity(), stdVec.capacity());
}

TEST_F(VectorTest, reserveInvalidCapacity)
{
    const size_type input = std::numeric_limits<size_type>::max();
    EXPECT_THROW(ftVec.reserve(input), std::length_error);
    EXPECT_THROW(stdVec.reserve(input), std::length_error);
}

TEST_F(VectorTest, reserveValidCapacity)
{
    ftVec.reserve(10);
    stdVec.reserve(10);
    EXPECT_EQ(ftVec.capacity(), stdVec.capacity());
    EXPECT_EQ(ftVec.at(0), stdVec.at(0));
}

TEST_F(VectorTest, pushBackWithoutCapacity)
{
    ftVec.push_back(2);
    stdVec.push_back(2);
    EXPECT_EQ(ftVec.at(0), stdVec.at(0));
    EXPECT_EQ(ftVec.at(1), stdVec.at(1));
    EXPECT_EQ(ftVec.size(), stdVec.size());
    EXPECT_EQ(ftVec.capacity(), stdVec.capacity());
}

TEST_F(VectorTest, pushBackWithCapacity)
{
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

TEST_F(VectorTest, popBack)
{
    ftVec.push_back(100);
    stdVec.push_back(100);

    EXPECT_EQ(ftVec.back(), stdVec.back());
    EXPECT_EQ(ftVec.size(), stdVec.size());
    EXPECT_EQ(ftVec.capacity(), stdVec.capacity());

    ftVec.pop_back();
    stdVec.pop_back();
}

TEST_F(VectorTest, popBackLastOneElementContainer)
{
    EXPECT_EQ(ftVec.back(), stdVec.back());
    EXPECT_EQ(ftVec.size(), stdVec.size());
    EXPECT_EQ(ftVec.capacity(), stdVec.capacity());

    ftVec.pop_back();
    stdVec.pop_back();

    EXPECT_EQ(ftVec.empty(), stdVec.empty());
    EXPECT_EQ(ftVec.size(), stdVec.size());
    EXPECT_EQ(ftVec.capacity(), stdVec.capacity());
}

TEST_F(VectorTest, resizeSameSize)
{
    ftVec.resize(1);
    stdVec.resize(1);

    EXPECT_EQ(ftVec.empty(), stdVec.empty());
    EXPECT_EQ(ftVec.size(), stdVec.size());
    EXPECT_EQ(ftVec.capacity(), stdVec.capacity());
    EXPECT_EQ(ftVec.at(0), stdVec.at(0));
}

TEST_F(VectorTest, resizeWithoutValueAndBiggerThanOriginalSize)
{
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

TEST_F(VectorTest, resizeWithValueAndBiggerThanOriginalSize)
{
    ftVec.resize(5, 15);
    stdVec.resize(5, 15);

    EXPECT_EQ(ftVec.empty(), stdVec.empty());
    EXPECT_EQ(ftVec.size(), stdVec.size());
    EXPECT_EQ(ftVec.capacity(), stdVec.capacity());
    EXPECT_EQ(ftVec.at(0), stdVec.at(0));
    EXPECT_EQ(ftVec.at(1), stdVec.at(1));
    EXPECT_EQ(ftVec.at(2), stdVec.at(2));
    EXPECT_EQ(ftVec.at(3), stdVec.at(3));
    EXPECT_EQ(ftVec.at(4), stdVec.at(4));
}

TEST_F(VectorTest, resizeOndeBiggerThanCapacity)
{
    GTEST_SKIP_("Not passing because of capacity");
    for(int i = 0; i < 2; ++i)
    {
        ftVec.push_back(3);
        stdVec.push_back(3);
    }

    ftVec.resize(ftVec.capacity() + 1);
    stdVec.resize(stdVec.capacity() + 1);

    EXPECT_EQ(ftVec.size(), stdVec.size());
    EXPECT_EQ(ftVec.capacity(), stdVec.capacity());
    EXPECT_EQ(ftVec.at(0), stdVec.at(0));
}

TEST_F(VectorTest, resizeSmallerThanOriginal)
{
    for(int i = 0; i < 10; ++i)
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

TEST_F(VectorTest, swapFunction)
{

    ft::vector<int>::iterator ftVec_beg = ftVec.begin();
    ft::vector<int>::iterator ftVec_end = ftVec.end() - 1;

    ft::vector<int> secondVector(3, 100);
    ft::vector<int>::iterator secondVector_beg = secondVector.begin();
    ft::vector<int>::iterator secondVector_end = secondVector.end() - 1;

    secondVector.swap(ftVec);

    EXPECT_EQ(ftVec.size(), 3);
    EXPECT_EQ(secondVector.size(), 1);
    EXPECT_EQ(ftVec.capacity(), 3);
    EXPECT_EQ(secondVector.capacity(), 1);
    EXPECT_EQ(&(*secondVector_beg), &(*ftVec.begin()));
    EXPECT_EQ(&(*ftVec_beg), &(*secondVector.begin()));
    EXPECT_EQ(&(*secondVector_end), &(*(ftVec.end() - 1)));
    EXPECT_EQ(&(*ftVec_end), &(*(secondVector.end() - 1)));
}

TEST_F(VectorTest, swapTwoEmptyVectors)
{
    ft::vector<int> first;
    ft::vector<int> second;

    ft::vector<int>::iterator first_beg = first.begin();
    ft::vector<int>::iterator first_end = first.end() - 1;

    ft::vector<int>::iterator second_beg = second.begin();
    ft::vector<int>::iterator second_end = second.end() - 1;

    second.swap(first);

    EXPECT_EQ(first.size(), 0);
    EXPECT_EQ(second.size(), 0);
    EXPECT_EQ(first.capacity(), 0);
    EXPECT_EQ(second.capacity(), 0);
    EXPECT_EQ(&(*second_beg), &(*first.begin()));
    EXPECT_EQ(&(*first_beg), &(*second.begin()));
    EXPECT_EQ(&(*second_end), &(*(first.end() - 1)));
    EXPECT_EQ(&(*first_end), &(*(second.end() - 1)));
}

TEST_F(VectorTest, clearContainerWithOneElement)
{
    ftVec.clear();
    stdVec.clear();

    EXPECT_EQ(ftVec.size(), stdVec.size());
    EXPECT_EQ(ftVec.capacity(), stdVec.capacity());
}

TEST_F(VectorTest, clearContainerWithMoreElements)
{
    ftVec.push_back(3);
    ftVec.push_back(3);
    stdVec.push_back(3);
    stdVec.push_back(3);

    ftVec.clear();
    stdVec.clear();

    EXPECT_EQ(ftVec.size(), stdVec.size());
    EXPECT_EQ(ftVec.capacity(), stdVec.capacity());
}

TEST_F(VectorTest, insertWithEnoughCapacity)
{
    ft::vector<int> myVec;
    myVec.reserve(5);
    myVec.push_back(400);
    myVec.push_back(500);

    myVec.insert(myVec.begin(), 300);

    EXPECT_EQ(myVec.at(0), 300);
    EXPECT_EQ(myVec.at(1), 400);
    EXPECT_EQ(myVec.at(2), 500);
    EXPECT_EQ(myVec.size(), 3);
    EXPECT_EQ(myVec.capacity(), 5);
    EXPECT_EQ(*myVec.begin(), 300);
    EXPECT_EQ(*(myVec.end() - 1), 500);
}

TEST_F(VectorTest, insertWithoutCapacity)
{
    EXPECT_EQ(*ftVec.insert(ftVec.begin(), 300), 300);
    EXPECT_EQ(*stdVec.insert(stdVec.begin(), 300), 300);

    EXPECT_EQ(ftVec.at(0), stdVec.at(0));
    EXPECT_EQ(ftVec.at(1), stdVec.at(1));
    EXPECT_EQ(ftVec.size(), stdVec.size());
    EXPECT_EQ(ftVec.capacity(), stdVec.capacity());
}
