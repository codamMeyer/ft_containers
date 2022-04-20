#ifndef __VECTORITERATOR_H__
#define __VECTORITERATOR_H__

#include <cstdlib>
#include <iterator/IteratorTraits.hpp>
#include <iterator>

namespace ft
{
template <typename T>
class vector_iterator : public ft::iterator<std::random_access_iterator_tag, T>
{
public:
    vector_iterator()
        : _value(NULL)
    {}
    vector_iterator(T* value)
        : _value(value)
    {}
    vector_iterator(const vector_iterator& other)
        : _value(other._value)
    {}

    vector_iterator& operator=(const vector_iterator& other)
    {
        _value = other._value;
        return *this;
    }

    bool operator==(const vector_iterator& other) const
    {
        return _value == other._value;
    };

    bool operator!=(const vector_iterator& other) const
    {
        return !(*this == other);
    };

    T& operator*()
    {
        return *_value;
    };

    const T& operator*() const
    {
        return *_value;
    };

    T* operator->()
    {
        return _value;
    };

    const T* operator->() const
    {
        return _value;
    };

    vector_iterator& operator++()
    {
        ++_value;
        return *this;
    };

    vector_iterator operator++(int)
    {
        vector_iterator old = *this;
        ++_value;
        return old;
    };

    vector_iterator& operator--()
    {
        --_value;
        return *this;
    };

    vector_iterator operator--(int)
    {
        vector_iterator old = *this;
        --_value;
        return old;
    };

    vector_iterator operator+(int amount)
    {
        vector_iterator ret(*this);
        ret._value += amount;
        return ret;
    };

    friend vector_iterator operator+(int amount, vector_iterator other)
    {
        other._value += amount;
        return other;
    };

    vector_iterator operator-(int amount)
    {
        vector_iterator ret(*this);
        ret._value -= amount;
        return ret;
    };

    friend vector_iterator operator-(int amount, vector_iterator other)
    {
        other._value -= amount;
        return other;
    };

    size_t operator-(vector_iterator other) const
    {
        return (this->_value - other._value);
    };

    bool operator<(const vector_iterator& other) const
    {
        return this->_value < other._value;
    };

    bool operator<=(const vector_iterator& other) const
    {
        return this->_value <= other._value;
    };

    bool operator>(const vector_iterator& other) const
    {
        return this->_value > other._value;
    };

    bool operator>=(const vector_iterator& other) const
    {
        return this->_value >= other._value;
    };

    vector_iterator& operator+=(int amount)
    {
        _value += amount;
        return *this;
    };

    vector_iterator& operator-=(int amount)
    {
        _value -= amount;
        return *this;
    };

    T& operator[](int n)
    {
        return *(_value + n);
    };

    const T& operator[](int n) const
    {
        return *(_value + n);
    };

private:
    T* _value;
};

template <typename T>
class vector_reverse_iterator : public ft::iterator<std::random_access_iterator_tag, T>
{
public:
    vector_reverse_iterator()
        : _value(NULL)
    {}
    vector_reverse_iterator(T* value)
        : _value(value)
    {}
    vector_reverse_iterator(const vector_reverse_iterator& other)
        : _value(other._value)
    {}

    vector_reverse_iterator& operator=(const vector_reverse_iterator& other)
    {
        _value = other._value;
        return *this;
    }

    bool operator==(const vector_reverse_iterator& other) const
    {
        return _value == other._value;
    };

    bool operator!=(const vector_reverse_iterator& other) const
    {
        return !(*this == other);
    };

    T& operator*()
    {
        return *_value;
    };

    const T& operator*() const
    {
        return *_value;
    };

    T* operator->()
    {
        return _value;
    };

    const T* operator->() const
    {
        return _value;
    };

    vector_reverse_iterator& operator++()
    {
        --_value;
        return *this;
    };

    vector_reverse_iterator operator++(int)
    {
        vector_reverse_iterator old = *this;
        --_value;
        return old;
    };

    vector_reverse_iterator& operator--()
    {
        ++_value;
        return *this;
    };

    vector_reverse_iterator operator--(int)
    {
        vector_reverse_iterator old = *this;
        ++_value;
        return old;
    };

    vector_reverse_iterator operator+(int amount)
    {
        vector_reverse_iterator ret(*this);
        ret._value -= amount;
        return ret;
    };

    friend vector_reverse_iterator operator+(int amount, vector_reverse_iterator other)
    {
        other._value -= amount;
        return other;
    };

    vector_reverse_iterator operator-(int amount)
    {
        vector_reverse_iterator ret(*this);
        ret._value += amount;
        return ret;
    };

    friend vector_reverse_iterator operator-(int amount, vector_reverse_iterator other)
    {
        other._value += amount;
        return other;
    };

    size_t operator-(vector_reverse_iterator other) const
    {
        return (this->_value + other._value);
    };

    bool operator<(const vector_reverse_iterator& other) const
    {
        return this->_value > other._value;
    };

    bool operator<=(const vector_reverse_iterator& other) const
    {
        return this->_value >= other._value;
    };

    bool operator>(const vector_reverse_iterator& other) const
    {
        return this->_value < other._value;
    };

    bool operator>=(const vector_reverse_iterator& other) const
    {
        return this->_value <= other._value;
    };

    vector_reverse_iterator& operator+=(int amount)
    {
        _value -= amount;
        return *this;
    };

    vector_reverse_iterator& operator-=(int amount)
    {
        _value += amount;
        return *this;
    };

    T& operator[](int n)
    {
        return *(_value - n);
    };

    const T& operator[](int n) const
    {
        return *(_value - n);
    };

private:
    T* _value;
};

} // namespace ft
#endif // __VECTORITERATOR_H__