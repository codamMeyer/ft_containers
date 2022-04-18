#include "../Vector.hpp"
#include <cstddef>
#include <gtest/gtest.h>
#include <gtest/internal/gtest-internal.h>
#include <iostream>
#include <iterator>
#include <vector>

/*************************************************************/
/*                       ITERATORS TEST                      */
/*************************************************************/

class VectorIteratorTest : public ::testing::Test
{
public:
    typedef ft::vector<int>::difference_type difference_type;

    VectorIteratorTest()
        : ftConstVec(ftVec)
        , stdConstVec(stdVec)
    {
        ftVec.push_back(5);
        ftVec.push_back(7);
        ftVec.push_back(9);

        stdVec.push_back(5);
        stdVec.push_back(7);
        stdVec.push_back(9);
    };

    ft::vector<int> ftVec;
    const ft::vector<int>& ftConstVec;

    std::vector<int> stdVec;
    const std::vector<int>& stdConstVec;
};

TEST_F(VectorIteratorTest, begin)
{
    EXPECT_EQ(*ftVec.begin(), *stdVec.begin());
    EXPECT_EQ(*ftConstVec.begin(), *stdConstVec.begin());
}

TEST_F(VectorIteratorTest, end)
{
    ftVec.end(); // TODO make a real test
    ftConstVec.end(); // TODO make a real test
}

TEST_F(VectorIteratorTest, copyConstructor)
{
    ft::vector<int>::iterator it = ftVec.end();
    ft::vector<int>::iterator copy(it);

    EXPECT_EQ(*(copy - 1), *(it - 1));
}

TEST_F(VectorIteratorTest, assignmentOperator)
{
    ft::vector<int>::iterator it = ftVec.end();
    ft::vector<int>::iterator copy;

    copy = it;

    EXPECT_EQ(*copy, *it);
}

TEST_F(VectorIteratorTest, equal)
{
    ft::vector<int>::iterator it = ftVec.end();
    const ft::vector<int>::iterator constIt = ftVec.end();

    EXPECT_TRUE(it == ftVec.end());
    EXPECT_TRUE(constIt == ftConstVec.end());
    EXPECT_FALSE(it == ftVec.begin());
    EXPECT_FALSE(constIt == ftConstVec.begin());
}

TEST_F(VectorIteratorTest, notEqual)
{
    ft::vector<int>::iterator it = ftVec.end();
    const ft::vector<int>::iterator constIt = ftVec.end();

    EXPECT_TRUE(it != ftVec.begin());
    EXPECT_TRUE(constIt != ftConstVec.begin());
    EXPECT_FALSE(it != ftVec.end());
    EXPECT_FALSE(constIt != ftConstVec.end());
}

TEST_F(VectorIteratorTest, dereference)
{
    *ftVec.begin() = 7;

    EXPECT_EQ(*ftVec.begin(), 7);
    EXPECT_EQ(*ftConstVec.begin(), 7);
}

TEST_F(VectorIteratorTest, arrow)
{
    ft::vector<std::pair<int, char>> vecPair(1);
    ft::vector<std::pair<int, char>>::iterator it = vecPair.begin();

    it->first = 2;
    it->second = 'a';
    EXPECT_EQ(it->first, 2);
    EXPECT_EQ(it->second, 'a');
}

TEST_F(VectorIteratorTest, preIncrement)
{
    ft::vector<int>::iterator it = ftVec.begin();
    ++it;
    EXPECT_EQ(*it, 7);
}

TEST_F(VectorIteratorTest, postIncrement)
{
    ft::vector<int>::iterator it = ftVec.begin();
    ft::vector<int>::iterator old = it++;

    EXPECT_EQ(*old, 5);
    EXPECT_EQ(*it, 7);
}

TEST_F(VectorIteratorTest, preDecrement)
{
    ft::vector<int>::iterator it = ftVec.end();
    --it;
    EXPECT_EQ(*it, 9);
}

TEST_F(VectorIteratorTest, postDecrement)
{
    ft::vector<int>::iterator it = ftVec.end();
    --it;
    ft::vector<int>::iterator old = it--;
    EXPECT_EQ(*old, 9);
    EXPECT_EQ(*it, 7);
}

TEST_F(VectorIteratorTest, preIncrementAndDereference)
{
    ft::vector<int>::iterator it = ftVec.begin();
    *++it = 15;

    EXPECT_EQ(*ftVec.begin(), 5);
    EXPECT_EQ(*it, 15);
}

TEST_F(VectorIteratorTest, postIncrementAndDereference)
{
    ft::vector<int>::iterator it = ftVec.begin();
    *it++ = 15;

    EXPECT_EQ(*ftVec.begin(), 15);
    EXPECT_EQ(*it, 7);
}

TEST_F(VectorIteratorTest, plus)
{
    ft::vector<int>::iterator it1 = ftVec.begin();
    ft::vector<int>::iterator it2 = it1 + 2;
    EXPECT_EQ(*it1, 5);
    EXPECT_EQ(*it2, 9);

    ft::vector<int>::iterator it3 = ftVec.begin();
    ft::vector<int>::iterator it4 = 2 + it3;
    EXPECT_EQ(*it3, 5);
    EXPECT_EQ(*it4, 9);
}

TEST_F(VectorIteratorTest, minus)
{
    ft::vector<int>::iterator it1 = ftVec.end();
    ft::vector<int>::iterator it2 = it1 - 2;
    EXPECT_EQ(*(it1 - 1), 9);
    EXPECT_EQ(*it2, 7);

    ft::vector<int>::iterator it3 = ftVec.end();
    ft::vector<int>::iterator it4 = 2 - it3;
    EXPECT_EQ(*(it3 - 1), 9);
    EXPECT_EQ(*it4, 7);

    EXPECT_EQ((stdVec.end() - stdVec.begin()), (ftVec.end() - ftVec.begin()));
}

TEST_F(VectorIteratorTest, lessThan)
{
    EXPECT_TRUE(ftVec.begin() < ftVec.end());
    EXPECT_TRUE(ftConstVec.begin() < ftConstVec.end());
}

TEST_F(VectorIteratorTest, lessThanOrEqual)
{
    EXPECT_TRUE(ftVec.begin() <= ftVec.end());
    EXPECT_TRUE(ftConstVec.begin() <= ftConstVec.end());
    EXPECT_TRUE(ftVec.end() <= ftVec.end());
    EXPECT_TRUE(ftConstVec.end() <= ftConstVec.end());
}

TEST_F(VectorIteratorTest, biggerThan)
{
    EXPECT_TRUE(ftVec.end() > ftVec.begin());
    EXPECT_TRUE(ftConstVec.end() > ftConstVec.begin());
}

TEST_F(VectorIteratorTest, biggerThanOrEqual)
{
    EXPECT_TRUE(ftVec.end() >= ftVec.begin());
    EXPECT_TRUE(ftConstVec.end() >= ftConstVec.begin());
    EXPECT_TRUE(ftVec.end() >= ftVec.end());
    EXPECT_TRUE(ftConstVec.end() >= ftConstVec.end());
}

TEST_F(VectorIteratorTest, plusEqual)
{
    ft::vector<int>::iterator it = ftVec.begin();
    it += 2;
    EXPECT_EQ(*it, 9);
}

TEST_F(VectorIteratorTest, minusEqual)
{
    ft::vector<int>::iterator it = ftVec.end();
    it -= 2;
    EXPECT_EQ(*it, 7);
}

TEST_F(VectorIteratorTest, offsetOperator)
{
    EXPECT_EQ(ftVec.begin()[0], 5);
    EXPECT_EQ(ftVec.begin()[2], 9);

    EXPECT_EQ(ftConstVec.begin()[0], 5);
    EXPECT_EQ(ftConstVec.begin()[2], 9);

    int& value = ftVec.begin()[1];
    const int& const_value = ftConstVec.begin()[1];

    value = 11;

    EXPECT_EQ(ftVec.begin()[1], 11);
    EXPECT_EQ(const_value, 11);
}

/*************************************************************/
/*                       ITERATORS TEST                      */
/*************************************************************/

class ReverseVectorIteratorTest : public ::testing::Test
{
public:
    typedef ft::vector<int>::difference_type difference_type;

    ReverseVectorIteratorTest()
        : ftConstVec(ftVec)
        , stdConstVec(stdVec)
    {
        ftVec.push_back(5);
        ftVec.push_back(7);
        ftVec.push_back(9);

        stdVec.push_back(5);
        stdVec.push_back(7);
        stdVec.push_back(9);
    };

    ft::vector<int> ftVec;
    const ft::vector<int>& ftConstVec;

    std::vector<int> stdVec;
    const std::vector<int>& stdConstVec;
};

TEST_F(ReverseVectorIteratorTest, begin)
{
    EXPECT_EQ(*ftVec.rbegin(), *stdVec.rbegin());
    EXPECT_EQ(*ftConstVec.rbegin(), *stdConstVec.rbegin());
}

TEST_F(ReverseVectorIteratorTest, end)
{
    ftVec.rend(); // TODO make a real test
    ftConstVec.rend(); // TODO make a real test
}

TEST_F(ReverseVectorIteratorTest, copyConstructor)
{
    ft::vector<int>::reverse_iterator it = ftVec.rend();
    ft::vector<int>::reverse_iterator copy(it);
    EXPECT_EQ(*(copy - 1), *(it - 1));
}

TEST_F(ReverseVectorIteratorTest, assignmentOperator)
{
    ft::vector<int>::reverse_iterator it = ftVec.rend();
    ft::vector<int>::reverse_iterator copy;

    copy = it;

    EXPECT_EQ(*(copy - 1), *(it - 1));
}

TEST_F(ReverseVectorIteratorTest, equal)
{
    ft::vector<int>::reverse_iterator it = ftVec.rend();
    const ft::vector<int>::reverse_iterator constIt = ftVec.rend();

    EXPECT_TRUE(it == ftVec.rend());
    EXPECT_TRUE(constIt == ftConstVec.rend());
    EXPECT_FALSE(it == ftVec.rbegin());
    EXPECT_FALSE(constIt == ftConstVec.rbegin());
}

TEST_F(ReverseVectorIteratorTest, notEqual)
{
    ft::vector<int>::reverse_iterator it = ftVec.rend();
    const ft::vector<int>::reverse_iterator constIt = ftVec.rend();

    EXPECT_TRUE(it != ftVec.rbegin());
    EXPECT_TRUE(constIt != ftConstVec.rbegin());
    EXPECT_FALSE(it != ftVec.rend());
    EXPECT_FALSE(constIt != ftConstVec.rend());
}

TEST_F(ReverseVectorIteratorTest, dereference)
{
    *ftVec.rbegin() = 7;

    EXPECT_EQ(*ftVec.rbegin(), 7);
    EXPECT_EQ(*ftConstVec.rbegin(), 7);
}

TEST_F(ReverseVectorIteratorTest, arrow)
{
    ft::vector<std::pair<int, char>> vecPair(1);
    ft::vector<std::pair<int, char>>::reverse_iterator it = vecPair.rbegin();

    it->first = 2;
    it->second = 'a';
    EXPECT_EQ(it->first, 2);
    EXPECT_EQ(it->second, 'a');
}

TEST_F(ReverseVectorIteratorTest, preIncrement)
{
    ft::vector<int>::reverse_iterator it = ftVec.rbegin();
    ++it;
    EXPECT_EQ(*it, 7);
}

TEST_F(ReverseVectorIteratorTest, postIncrement)
{
    ft::vector<int>::reverse_iterator it = ftVec.rbegin();
    ft::vector<int>::reverse_iterator old = it++;

    EXPECT_EQ(*old, 9);
    EXPECT_EQ(*it, 7);
}

TEST_F(ReverseVectorIteratorTest, preDecrement)
{
    ft::vector<int>::reverse_iterator it = ftVec.rend();
    --it;
    EXPECT_EQ(*it, 5);
}

TEST_F(ReverseVectorIteratorTest, postDecrement)
{
    ft::vector<int>::reverse_iterator it = ftVec.rend();
    --it;
    ft::vector<int>::reverse_iterator old = it--;
    EXPECT_EQ(*old, 5);
    EXPECT_EQ(*it, 7);
}

TEST_F(ReverseVectorIteratorTest, preIncrementAndDereference)
{
    ft::vector<int>::reverse_iterator it = ftVec.rbegin();
    *++it = 15;

    EXPECT_EQ(*ftVec.rbegin(), 9);
    EXPECT_EQ(*it, 15);
}

TEST_F(ReverseVectorIteratorTest, postIncrementAndDereference)
{
    ft::vector<int>::reverse_iterator it = ftVec.rbegin();
    *it++ = 15;

    EXPECT_EQ(*ftVec.rbegin(), 15);
    EXPECT_EQ(*it, 7);
}

TEST_F(ReverseVectorIteratorTest, plus)
{
    ft::vector<int>::reverse_iterator it1 = ftVec.rbegin();
    ft::vector<int>::reverse_iterator it2 = it1 + 2;
    EXPECT_EQ(*it1, 9);
    EXPECT_EQ(*it2, 5);

    ft::vector<int>::reverse_iterator it3 = ftVec.rbegin();
    ft::vector<int>::reverse_iterator it4 = 2 + it3;
    EXPECT_EQ(*it3, 9);
    EXPECT_EQ(*it4, 5);
}

TEST_F(ReverseVectorIteratorTest, minus)
{
    ft::vector<int>::reverse_iterator it1 = ftVec.rend();
    ft::vector<int>::reverse_iterator it2 = it1 - 2;
    EXPECT_EQ(*(it1 - 1), 5);
    EXPECT_EQ(*it2, 7);

    ft::vector<int>::reverse_iterator it3 = ftVec.rend();
    ft::vector<int>::reverse_iterator it4 = 2 - it3;
    EXPECT_EQ(*(it3 - 1), 5);
    EXPECT_EQ(*it4, 7);

    // TODO fix this test
    // EXPECT_EQ((stdVec.rend() - stdVec.rbegin()), (ftVec.rend() - ftVec.rbegin()));
}

TEST_F(ReverseVectorIteratorTest, lessThan)
{
    EXPECT_TRUE(ftVec.rbegin() < ftVec.rend());
    EXPECT_TRUE(ftConstVec.rbegin() < ftConstVec.rend());
}

TEST_F(ReverseVectorIteratorTest, lessThanOrEqual)
{
    EXPECT_TRUE(ftVec.rbegin() <= ftVec.rend());
    EXPECT_TRUE(ftConstVec.rbegin() <= ftConstVec.rend());
    EXPECT_TRUE(ftVec.rend() <= ftVec.rend());
    EXPECT_TRUE(ftConstVec.rend() <= ftConstVec.rend());
}

TEST_F(ReverseVectorIteratorTest, biggerThan)
{
    EXPECT_TRUE(ftVec.rend() > ftVec.rbegin());
    EXPECT_TRUE(ftConstVec.rend() > ftConstVec.rbegin());
}

TEST_F(ReverseVectorIteratorTest, biggerThanOrEqual)
{
    EXPECT_TRUE(ftVec.rend() >= ftVec.rbegin());
    EXPECT_TRUE(ftConstVec.rend() >= ftConstVec.rbegin());
    EXPECT_TRUE(ftVec.rend() >= ftVec.rend());
    EXPECT_TRUE(ftConstVec.rend() >= ftConstVec.rend());
}

TEST_F(ReverseVectorIteratorTest, plusEqual)
{
    ft::vector<int>::reverse_iterator it = ftVec.rbegin();
    it += 2;
    EXPECT_EQ(*it, 5);
}

TEST_F(ReverseVectorIteratorTest, minusEqual)
{
    ft::vector<int>::reverse_iterator it = ftVec.rend();
    it -= 2;
    EXPECT_EQ(*it, 7);
}

TEST_F(ReverseVectorIteratorTest, offsetOperator)
{
    EXPECT_EQ(ftVec.rbegin()[0], 9);
    EXPECT_EQ(ftVec.rbegin()[2], 5);

    EXPECT_EQ(ftConstVec.rbegin()[0], 9);
    EXPECT_EQ(ftConstVec.rbegin()[2], 5);

    int& value = ftVec.rbegin()[1];
    const int& const_value = ftConstVec.rbegin()[1];

    value = 11;

    EXPECT_EQ(ftVec.rbegin()[1], 11);
    EXPECT_EQ(const_value, 11);
}
