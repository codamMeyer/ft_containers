#include "../Vector.hpp"
#include <gtest/gtest-death-test.h>
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

///////////////////////////////////////////////////////////////
//                          at()                             //
///////////////////////////////////////////////////////////////

TEST_F(EmptyVectorTest, atInvalidPos)
{
    EXPECT_THROW(ftVec.at(0), std::out_of_range);
    EXPECT_THROW(ftConstVec.at(0), std::out_of_range);
}

///////////////////////////////////////////////////////////////
//                       empty()                             //
///////////////////////////////////////////////////////////////

TEST_F(EmptyVectorTest, empty)
{
    EXPECT_EQ(ftConstVec.empty(), stdConstVec.empty());
}

///////////////////////////////////////////////////////////////
//                        size()                             //
///////////////////////////////////////////////////////////////

TEST_F(EmptyVectorTest, size)
{
    EXPECT_EQ(ftConstVec.size(), stdConstVec.size());
}

///////////////////////////////////////////////////////////////
//                       maxSize()                           //
///////////////////////////////////////////////////////////////

TEST_F(EmptyVectorTest, maxSize)
{
    EXPECT_EQ(ftConstVec.max_size(), stdConstVec.max_size());
}

///////////////////////////////////////////////////////////////
//                      capacity()                           //
///////////////////////////////////////////////////////////////

TEST_F(EmptyVectorTest, capacity)
{
    EXPECT_EQ(ftConstVec.capacity(), stdConstVec.capacity());
}

///////////////////////////////////////////////////////////////
//                        push_back()                        //
///////////////////////////////////////////////////////////////

TEST_F(EmptyVectorTest, pushBack)
{
    EXPECT_NO_THROW(ftVec.push_back(2));
    EXPECT_NO_THROW(stdVec.push_back(2));

    EXPECT_EQ(ftVec.capacity(), stdVec.capacity());
    EXPECT_EQ(ftVec.size(), stdVec.size());
    EXPECT_EQ(ftVec.at(0), stdVec.at(0));
}

///////////////////////////////////////////////////////////////
//                   NON EMPTY VECTOR                        //
///////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////
//                          at()                             //
///////////////////////////////////////////////////////////////

TEST_F(VectorTest, at)
{
    EXPECT_EQ(ftVec.at(0), stdVec.at(0));
    EXPECT_EQ(ftConstVec.at(0), stdConstVec.at(0));
}

///////////////////////////////////////////////////////////////
//                        operator[]                         //
///////////////////////////////////////////////////////////////

TEST_F(VectorTest, operatorIndex)
{
    EXPECT_EQ(ftVec[0], stdVec[0]);
    EXPECT_EQ(ftConstVec[0], stdConstVec[0]);
}

///////////////////////////////////////////////////////////////
//                        front()                            //
///////////////////////////////////////////////////////////////

TEST_F(VectorTest, front)
{
    ftVec.push_back(1);
    stdVec.push_back(1);
    EXPECT_EQ(ftVec.front(), stdVec.front());
    EXPECT_EQ(ftConstVec.front(), stdConstVec.front());
}

///////////////////////////////////////////////////////////////
//                          back()                           //
///////////////////////////////////////////////////////////////

TEST_F(VectorTest, back)
{
    ftVec.push_back(1);
    stdVec.push_back(1);
    EXPECT_EQ(ftVec.back(), stdVec.back());
    EXPECT_EQ(ftConstVec.back(), stdConstVec.back());
}

///////////////////////////////////////////////////////////////
//                          data()                           //
///////////////////////////////////////////////////////////////

TEST_F(VectorTest, data)
{
    ftVec.push_back(1);
    stdVec.push_back(1);
    EXPECT_EQ(*ftVec.data(), *stdVec.data());
    EXPECT_EQ(*ftConstVec.data(), *stdConstVec.data());
}

///////////////////////////////////////////////////////////////
//                          empty()                          //
///////////////////////////////////////////////////////////////

TEST_F(VectorTest, nonEmpty)
{
    EXPECT_EQ(ftVec.empty(), stdVec.empty());
}

///////////////////////////////////////////////////////////////
//                          size()                           //
///////////////////////////////////////////////////////////////

TEST_F(VectorTest, sizeOneElement)
{
    EXPECT_EQ(ftVec.size(), stdVec.size());
}

///////////////////////////////////////////////////////////////
//                         capacity()                        //
///////////////////////////////////////////////////////////////

TEST_F(VectorTest, capacity)
{
    EXPECT_EQ(ftVec.capacity(), stdVec.capacity());
}

///////////////////////////////////////////////////////////////
//                       reserve()                           //
///////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////
//                     push_back()                           //
///////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////
//                     pop_back()                            //
///////////////////////////////////////////////////////////////

TEST_F(EmptyVectorTest, popBackEmptyVector)
{
    ftVec.pop_back();
    EXPECT_EQ(ftVec.size(), 0);
    EXPECT_EQ(ftVec.capacity(), 0);
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

TEST_F(VectorTest, popBack)
{
    ftVec.push_back(100);
    stdVec.push_back(100);

    ftVec.pop_back();
    stdVec.pop_back();

    EXPECT_EQ(ftVec.back(), stdVec.back());
    EXPECT_EQ(ftVec.size(), stdVec.size());
    EXPECT_EQ(ftVec.capacity(), stdVec.capacity());
}
///////////////////////////////////////////////////////////////
//                       resize()                            //
///////////////////////////////////////////////////////////////

TEST_F(VectorTest, resizeSameSize)
{
    ftVec.resize(1);
    stdVec.resize(1);

    EXPECT_EQ(ftVec.empty(), stdVec.empty());
    EXPECT_EQ(ftVec.size(), stdVec.size());
    EXPECT_EQ(ftVec.capacity(), stdVec.capacity());
    EXPECT_EQ(ftVec.at(0), stdVec.at(0));
}

TEST_F(VectorTest, resizeSameSizeWithElements)
{
    ftVec.push_back(10);
    ftVec.push_back(10);

    stdVec.push_back(10);
    stdVec.push_back(10);

    ftVec.resize(4);
    stdVec.resize(4);

    EXPECT_EQ(ftVec.empty(), stdVec.empty());
    EXPECT_EQ(ftVec.size(), stdVec.size());
    EXPECT_EQ(ftVec.capacity(), stdVec.capacity());
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

TEST_F(VectorTest, DISABLED_resizeOneBiggerThanCapacity)
{
    for(int i = 0; i < 3; ++i)
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

///////////////////////////////////////////////////////////////
//                        swap()                             //
///////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////
//                         clear()                           //
///////////////////////////////////////////////////////////////

TEST_F(EmptyVectorTest, clearContainer)
{
    ftVec.clear();
    stdVec.clear();

    EXPECT_EQ(ftVec.size(), stdVec.size());
    EXPECT_EQ(ftVec.capacity(), stdVec.capacity());
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

///////////////////////////////////////////////////////////////
//                        insert()                           //
///////////////////////////////////////////////////////////////

TEST_F(EmptyVectorTest, insertInBeginEmptyVector)
{
    ftVec.insert(ftVec.begin(), 300);

    EXPECT_EQ(ftVec.at(0), 300);
    EXPECT_EQ(ftVec.size(), 1);
    EXPECT_EQ(ftVec.capacity(), 1);
    EXPECT_EQ(*ftVec.begin(), 300);
    EXPECT_EQ(*(ftVec.end() - 1), 300);
}

TEST_F(VectorTest, insertInEndEmptyVector)
{
    ft::vector<int> myVec;
    myVec.insert(myVec.end(), 300);

    EXPECT_EQ(myVec.at(0), 300);
    EXPECT_EQ(myVec.size(), 1);
    EXPECT_EQ(myVec.capacity(), 1);
    EXPECT_EQ(*myVec.begin(), 300);
    EXPECT_EQ(*(myVec.end() - 1), 300);
}

TEST_F(EmptyVectorTest, insertBeginWithEnoughCapacity)
{
    ftVec.reserve(5);
    ftVec.push_back(400);
    ftVec.push_back(500);

    ftVec.insert(ftVec.begin(), 300);

    EXPECT_EQ(ftVec.at(0), 300);
    EXPECT_EQ(ftVec.at(1), 400);
    EXPECT_EQ(ftVec.at(2), 500);
    EXPECT_EQ(ftVec.size(), 3);
    EXPECT_EQ(ftVec.capacity(), 5);
    EXPECT_EQ(*ftVec.begin(), 300);
    EXPECT_EQ(*(ftVec.end() - 1), 500);
}

TEST_F(EmptyVectorTest, insertEndWithEnoughCapacity)
{
    ftVec.reserve(5);
    ftVec.push_back(400);
    ftVec.push_back(500);

    ftVec.insert(ftVec.end(), 300);

    EXPECT_EQ(ftVec.at(0), 400);
    EXPECT_EQ(ftVec.at(1), 500);
    EXPECT_EQ(ftVec.at(2), 300);
    EXPECT_EQ(ftVec.size(), 3);
    EXPECT_EQ(ftVec.capacity(), 5);
    EXPECT_EQ(*ftVec.begin(), 400);
    EXPECT_EQ(*(ftVec.end() - 1), 300);
}

TEST_F(VectorTest, insertBeginWithoutCapacity)
{
    EXPECT_EQ(*ftVec.insert(ftVec.begin(), 300), 300);
    EXPECT_EQ(*stdVec.insert(stdVec.begin(), 300), 300);

    EXPECT_EQ(ftVec.at(0), stdVec.at(0));
    EXPECT_EQ(ftVec.at(1), stdVec.at(1));
    EXPECT_EQ(ftVec.size(), stdVec.size());
    EXPECT_EQ(ftVec.capacity(), stdVec.capacity());
}

TEST_F(VectorTest, insertEndWithoutCapacity)
{
    EXPECT_EQ(*ftVec.insert(ftVec.end(), 300), 300);
    EXPECT_EQ(*stdVec.insert(stdVec.end(), 300), 300);

    EXPECT_EQ(ftVec.at(0), stdVec.at(0));
    EXPECT_EQ(ftVec.at(1), stdVec.at(1));
    EXPECT_EQ(ftVec.size(), stdVec.size());
    EXPECT_EQ(ftVec.capacity(), stdVec.capacity());
}

TEST_F(VectorTest, insertCountBegin)
{
    ftVec.insert(ftVec.begin(), 6, 300);
    stdVec.insert(stdVec.begin(), 6, 300);

    EXPECT_EQ(ftVec.size(), stdVec.size());
    EXPECT_EQ(ftVec.capacity(), stdVec.capacity());
    EXPECT_EQ(ftVec.at(0), stdVec.at(0));
    EXPECT_EQ(ftVec.at(1), stdVec.at(1));
    EXPECT_EQ(ftVec.at(2), stdVec.at(2));
    EXPECT_EQ(ftVec.at(3), stdVec.at(3));
    EXPECT_EQ(ftVec.at(4), stdVec.at(4));
    EXPECT_EQ(ftVec.at(5), stdVec.at(5));
    EXPECT_EQ(ftVec.at(6), stdVec.at(6));
}

TEST_F(VectorTest, insertCountEnd)
{
    ftVec.insert(ftVec.end(), 6, 300);
    stdVec.insert(stdVec.end(), 6, 300);

    EXPECT_EQ(ftVec.size(), stdVec.size());
    EXPECT_EQ(ftVec.capacity(), stdVec.capacity());
    EXPECT_EQ(ftVec.at(0), stdVec.at(0));
    EXPECT_EQ(ftVec.at(1), stdVec.at(1));
    EXPECT_EQ(ftVec.at(2), stdVec.at(2));
    EXPECT_EQ(ftVec.at(3), stdVec.at(3));
    EXPECT_EQ(ftVec.at(4), stdVec.at(4));
    EXPECT_EQ(ftVec.at(5), stdVec.at(5));
    EXPECT_EQ(ftVec.at(6), stdVec.at(6));
}

TEST_F(VectorTest, insertCountMiddle)
{
    ftVec.push_back(4);
    ftVec.push_back(3);
    ftVec.push_back(2);
    ftVec.insert(ftVec.begin() + 1, 3, 0);

    stdVec.push_back(4);
    stdVec.push_back(3);
    stdVec.push_back(2);
    stdVec.insert(stdVec.begin() + 1, 3, 0);

    EXPECT_EQ(ftVec.size(), stdVec.size());
    // EXPECT_EQ(ftVec.capacity(), stdVec.capacity());
    EXPECT_EQ(ftVec.at(0), stdVec.at(0));
    EXPECT_EQ(ftVec.at(1), stdVec.at(1));
    EXPECT_EQ(ftVec.at(2), stdVec.at(2));
    EXPECT_EQ(ftVec.at(3), stdVec.at(3));
    EXPECT_EQ(ftVec.at(4), stdVec.at(4));
    EXPECT_EQ(ftVec.at(5), stdVec.at(5));
    EXPECT_EQ(ftVec.at(6), stdVec.at(6));
}

///////////////////////////////////////////////////////////////
//                         erase()                           //
///////////////////////////////////////////////////////////////

TEST_F(VectorTest, eraseOneElementFromEndVector)
{
    stdVec.push_back(100);
    stdVec.push_back(500);
    stdVec.push_back(700);

    ftVec.push_back(100);
    ftVec.push_back(500);
    ftVec.push_back(700);

    EXPECT_EQ(*stdVec.erase(stdVec.end() - 1), *ftVec.erase(ftVec.end() - 1));
    EXPECT_EQ(stdVec.size(), ftVec.size());
    EXPECT_EQ(stdVec.capacity(), ftVec.capacity());
    EXPECT_EQ(ftVec.at(0), stdVec.at(0));
    EXPECT_EQ(ftVec.at(1), stdVec.at(1));
    EXPECT_EQ(ftVec.at(2), stdVec.at(2));
}

TEST_F(VectorTest, eraseOneElementFromBeginVector)
{
    stdVec.push_back(100);
    stdVec.push_back(500);
    stdVec.push_back(700);

    ftVec.push_back(100);
    ftVec.push_back(500);
    ftVec.push_back(700);

    EXPECT_EQ(*stdVec.erase(stdVec.begin()), *ftVec.erase(ftVec.begin()));
    EXPECT_EQ(stdVec.size(), ftVec.size());
    EXPECT_EQ(stdVec.capacity(), ftVec.capacity());
    EXPECT_EQ(ftVec.at(0), stdVec.at(0));
    EXPECT_EQ(ftVec.at(1), stdVec.at(1));
    EXPECT_EQ(ftVec.at(2), stdVec.at(2));
}

TEST_F(VectorTest, eraseRangeOfElementsLastEqualEnd)
{
    stdVec.push_back(6);
    stdVec.push_back(7);
    stdVec.push_back(1);
    stdVec.push_back(2);

    ftVec.push_back(6);
    ftVec.push_back(7);
    ftVec.push_back(1);
    ftVec.push_back(2);

    EXPECT_EQ(*stdVec.erase(stdVec.begin() + 1, stdVec.end()),
              *ftVec.erase(ftVec.begin() + 1, ftVec.end()));
    EXPECT_EQ(stdVec.size(), ftVec.size());
    EXPECT_EQ(stdVec.capacity(), ftVec.capacity());

    EXPECT_EQ(ftVec.at(0), stdVec.at(0));
}

TEST_F(VectorTest, eraseRangeOfElements)
{
    stdVec.push_back(6);
    stdVec.push_back(7);
    stdVec.push_back(0);
    stdVec.push_back(1);
    stdVec.push_back(2);
    stdVec.push_back(3);
    stdVec.push_back(4);

    ftVec.push_back(6);
    ftVec.push_back(7);
    ftVec.push_back(0);
    ftVec.push_back(1);
    ftVec.push_back(2);
    ftVec.push_back(3);
    ftVec.push_back(4);

    EXPECT_EQ(*stdVec.erase(stdVec.begin(), stdVec.begin() + 3),
              *ftVec.erase(ftVec.begin(), ftVec.begin() + 3));
    EXPECT_EQ(stdVec.size(), ftVec.size());
    EXPECT_EQ(stdVec.capacity(), ftVec.capacity());

    EXPECT_EQ(ftVec.at(0), stdVec.at(0));
    EXPECT_EQ(ftVec.at(1), stdVec.at(1));
    EXPECT_EQ(ftVec.at(2), stdVec.at(2));
    EXPECT_EQ(ftVec.at(3), stdVec.at(3));
    EXPECT_EQ(ftVec.at(4), stdVec.at(4));
}

TEST_F(VectorTest, eraseRangeOfElementsFirstEqualLast)
{
    EXPECT_EQ(*stdVec.erase(stdVec.begin(), stdVec.begin()),
              *ftVec.erase(ftVec.begin(), ftVec.begin()));
    EXPECT_EQ(stdVec.size(), ftVec.size());
    EXPECT_EQ(stdVec.capacity(), ftVec.capacity());
}

TEST_F(EmptyVectorTest, eraseRangeFromEmptyVector)
{
    stdVec.erase(stdVec.begin(), stdVec.end());
    ftVec.erase(ftVec.begin(), ftVec.end());
    EXPECT_EQ(stdVec.size(), ftVec.size());
    EXPECT_EQ(stdVec.capacity(), ftVec.capacity());
}

///////////////////////////////////////////////////////////////
//                 get_allocator()                           //
///////////////////////////////////////////////////////////////

TEST_F(VectorTest, get_allocator)
{
    EXPECT_EQ(stdVec.get_allocator(), ftVec.get_allocator());
}

///////////////////////////////////////////////////////////////
//                      operator =                           //
///////////////////////////////////////////////////////////////

TEST_F(EmptyVectorTest, assignmentOperatorVector)
{
    ft::vector<int> vec;
    ftVec = vec;
    EXPECT_TRUE(vec == ftVec);
    EXPECT_EQ(vec.get_allocator(), ftVec.get_allocator());
    EXPECT_EQ(vec.capacity(), ftVec.capacity());
    EXPECT_EQ(vec.size(), ftVec.size());
}

TEST_F(EmptyVectorTest, assignmentOperatorVectorInverted)
{
    ft::vector<int> vec;
    vec = ftVec;
    EXPECT_EQ(vec.get_allocator(), ftVec.get_allocator());
    EXPECT_EQ(vec.capacity(), ftVec.capacity());
    EXPECT_EQ(vec.size(), ftVec.size());
}

TEST_F(VectorTest, assignmentOperatorNonEmptyVector)
{
    ft::vector<int> vec;

    vec = ftVec;
    EXPECT_TRUE(vec == ftVec);
    EXPECT_EQ(ftVec.size(), vec.size());
    EXPECT_EQ(ftVec.capacity(), vec.capacity());
    EXPECT_EQ(ftVec.get_allocator(), vec.get_allocator());
}

TEST_F(VectorTest, assignmentOperatorOverwritingNonEmptyVector)
{
    ft::vector<int> vec;

    ftVec = vec;
    EXPECT_TRUE(vec == ftVec);
    EXPECT_EQ(ftVec.size(), vec.size());
    EXPECT_EQ(ftVec.capacity(), vec.capacity());
    EXPECT_EQ(ftVec.get_allocator(), vec.get_allocator());
}

///////////////////////////////////////////////////////////////
//                      assign()                             //
///////////////////////////////////////////////////////////////

TEST_F(EmptyVectorTest, DISABLED_assignToEmpty)
{
    std::vector<int> newVec;
    ftVec.assign(5, 1);
    newVec.assign(5, 1);

    EXPECT_EQ(ftVec.capacity(), newVec.capacity());
    EXPECT_EQ(ftVec.size(), newVec.size());
}

TEST_F(VectorTest, assignToNonEmptyLessThanExistent)
{
    ftVec.insert(ftVec.begin(), 10, 100);
    ftVec.assign(5, 1);

    stdVec.insert(stdVec.begin(), 10, 100);
    stdVec.assign(5, 1);

    EXPECT_EQ(ftVec.size(), stdVec.size());
    EXPECT_EQ(ftVec.capacity(), stdVec.capacity());
}

TEST_F(VectorTest, assignToNonEmptyMoreThanExistent)
{
    ftVec.assign(5, 100);
    stdVec.assign(5, 100);

    EXPECT_EQ(ftVec.size(), stdVec.size());
    EXPECT_EQ(ftVec.capacity(), stdVec.capacity());
}

///////////////////////////////////////////////////////////////
//                      operator ==                          //
///////////////////////////////////////////////////////////////

TEST_F(EmptyVectorTest, equalEmptyVector)
{
    ft::vector<int> vec;

    EXPECT_TRUE(vec == ftVec);
}

TEST_F(VectorTest, equalOperatorSameSize)
{
    ft::vector<int> rhs(5, 100);
    ft::vector<int> lhs(5, 100);

    EXPECT_TRUE(lhs == rhs);
}

TEST_F(VectorTest, equalOperatorDifferentSize)
{
    ft::vector<int> rhs(5, 100);
    ft::vector<int> lhs(10, 100);

    EXPECT_FALSE(lhs == rhs);
}

///////////////////////////////////////////////////////////////
//                      operator !=                          //
///////////////////////////////////////////////////////////////

TEST_F(EmptyVectorTest, notEqualEmptyVector)
{
    ft::vector<int> vec;

    EXPECT_FALSE(vec != ftVec);
}

TEST_F(VectorTest, notEqualOperatorSameSize)
{
    ft::vector<int> rhs(5, 100);
    ft::vector<int> lhs(5, 100);

    EXPECT_FALSE(lhs != rhs);
}

TEST_F(VectorTest, notEqualOperatorDifferentSize)
{
    ft::vector<int> rhs(5, 100);
    ft::vector<int> lhs(10, 100);

    EXPECT_TRUE(lhs != rhs);
}

///////////////////////////////////////////////////////////////
//                      operator <                           //
///////////////////////////////////////////////////////////////

TEST_F(EmptyVectorTest, smallerThanOperatorEmpty)
{
    ft::vector<int> vec;

    EXPECT_FALSE(vec < ftVec);
}

TEST_F(VectorTest, smallerThanOperatorSameContent)
{
    ft::vector<int> rhs(5, 100);
    ft::vector<int> lhs(5, 100);

    EXPECT_FALSE(lhs < rhs);
}

TEST_F(VectorTest, smallerThanOperatorWithDifferentSizes)
{
    ft::vector<int> lhs(4, 100);
    ft::vector<int> rhs(5, 100);

    EXPECT_TRUE(lhs < rhs);
    EXPECT_FALSE(rhs < lhs);
}

TEST_F(VectorTest, smallerThanOperatorWithSameSizes)
{
    ft::vector<int> lhs(4, 100);
    ft::vector<int> rhs(5, 100);

    lhs.push_back(50);
    EXPECT_TRUE(lhs < rhs);
}

///////////////////////////////////////////////////////////////
//                      operator <=                          //
///////////////////////////////////////////////////////////////

TEST_F(EmptyVectorTest, smallerOrEqualThanOperatorEmpty)
{
    ft::vector<int> vec;

    EXPECT_TRUE(vec <= ftVec);
}

TEST_F(VectorTest, smallerOrEqualThanOperatorSameContent)
{
    ft::vector<int> rhs(5, 100);
    ft::vector<int> lhs(5, 100);

    EXPECT_TRUE(lhs <= rhs);
}

TEST_F(VectorTest, smallerOrEqualThanOperatorWithDifferentSizes)
{
    ft::vector<int> lhs(4, 100);
    ft::vector<int> rhs(5, 100);

    EXPECT_TRUE(lhs <= rhs);
    EXPECT_FALSE(rhs <= lhs);
}

TEST_F(VectorTest, smallerOrEqualThanOperatorWithSameSizes)
{
    ft::vector<int> lhs(4, 100);
    ft::vector<int> rhs(5, 100);

    lhs.push_back(50);
    EXPECT_TRUE(lhs <= rhs);
}

///////////////////////////////////////////////////////////////
//                      operator >                           //
///////////////////////////////////////////////////////////////

TEST_F(EmptyVectorTest, biggerThanOperatorEmpty)
{
    ft::vector<int> vec;

    EXPECT_FALSE(vec > ftVec);
}

TEST_F(VectorTest, biggerThanOperatorSameContent)
{
    ft::vector<int> lhs(5, 100);
    ft::vector<int> rhs(5, 100);

    EXPECT_FALSE(lhs > rhs);
}

TEST_F(VectorTest, biggerThanOperatorWithDifferentSizes)
{
    ft::vector<int> rhs(4, 100);
    ft::vector<int> lhs(5, 100);

    EXPECT_TRUE(lhs > rhs);
    EXPECT_FALSE(rhs > lhs);
}

TEST_F(VectorTest, biggerThanOperatorWithSameSizes)
{
    ft::vector<int> rhs(4, 100);
    ft::vector<int> lhs(5, 100);

    lhs.push_back(50);
    EXPECT_TRUE(lhs > rhs);
}

///////////////////////////////////////////////////////////////
//                      operator >=                          //
///////////////////////////////////////////////////////////////

TEST_F(EmptyVectorTest, biggerOrEqualThanOperatorEmpty)
{
    ft::vector<int> vec;

    EXPECT_TRUE(vec >= ftVec);
}

TEST_F(VectorTest, biggerOrEqualThanOperatorSameContent)
{
    ft::vector<int> lhs(5, 100);
    ft::vector<int> rhs(5, 100);

    EXPECT_TRUE(lhs >= rhs);
}

TEST_F(VectorTest, biggerOrEqualThanOperatorWithDifferentSizes)
{
    ft::vector<int> rhs(4, 100);
    ft::vector<int> lhs(5, 100);

    EXPECT_TRUE(lhs >= rhs);
    EXPECT_FALSE(rhs >= lhs);
}

TEST_F(VectorTest, biggerOrEqualThanOperatorWithSameSizes)
{
    ft::vector<int> rhs(4, 100);
    ft::vector<int> lhs(5, 100);

    lhs.push_back(50);
    EXPECT_TRUE(lhs >= rhs);
}

///////////////////////////////////////////////////////////////
//                  Object Destruction                       //
///////////////////////////////////////////////////////////////

class ObjectDestruction : public ::testing::Test
{
public:
    class MyObject
    {
    public:
        MyObject(int* count)
            : destructionCount(count)
        {}

        MyObject(const MyObject& other)
            : destructionCount(other.destructionCount)
        {}

        ~MyObject()
        {
            (*destructionCount)++;
        }

        MyObject& operator=(const MyObject& other)
        {
            this->destructionCount = other.destructionCount;
            return *this;
        }
        int* destructionCount;
    };

    ObjectDestruction()
        : counter(0){};

    typedef ft::vector<MyObject>::difference_type difference_type;

    int counter;
};

TEST_F(ObjectDestruction, clearCheckObjectDestruction)
{
    MyObject a(&counter);
    std::vector<MyObject> objs(3, a);
    EXPECT_EQ(counter, 0);
    objs.clear();

    EXPECT_EQ(counter, 3);
}

TEST_F(ObjectDestruction, popBackCheckObjectDestruction)
{
    MyObject a(&counter);
    std::vector<MyObject> objs(3, a);
    EXPECT_EQ(counter, 0);

    objs.pop_back();

    EXPECT_EQ(counter, 1);
}

TEST_F(ObjectDestruction, destructorCheckObjectDestruction)
{
    MyObject a(&counter);
    {
        std::vector<MyObject> objs(1, a);
        EXPECT_EQ(counter, 0);
    }

    EXPECT_EQ(counter, 1);
}

TEST_F(ObjectDestruction, resizeCheckObjectDestruction)
{
    MyObject a(&counter);
    {
        ft::vector<MyObject> objs(2, a);

        EXPECT_EQ(objs.size(), 2);
        objs.resize(4, a);
    }
    EXPECT_EQ(counter, 7); // +1 because of param
}

TEST_F(ObjectDestruction, reserveCheckObjectDestruction)
{
    MyObject a(&counter);
    {
        ft::vector<MyObject> objs(2, a);

        EXPECT_EQ(objs.size(), 2);
        objs.reserve(10);
    }
    EXPECT_EQ(counter, 4);
}