#ifndef VECTOR_H
#define VECTOR_H
#include <cstddef>
#include <iostream>
#include <iterator>
#include <limits>
#include <memory>
#include <stdexcept>

namespace ft
{

// TODO review exception texts
template <class T, class Allocator = std::allocator<T>>
class vector
{
    class vector_iterator
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

        size_t operator-(vector_iterator other)
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

public:
    // MEMBER TYPES
    typedef T value_type;
    typedef Allocator allocator_type;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef typename Allocator::pointer pointer;
    typedef typename Allocator::const_pointer const_pointer;
    typedef vector_iterator iterator;
    typedef const vector_iterator const_iterator;
    // reverse_iterator
    // const_reverse_iterator

    vector()
        : _size(0)
        , _capacity(0)
        , _elements(NULL)
        , _begin(NULL)
        , _end(NULL){};

    explicit vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator())
        : _allocator(alloc)
        , _size(count)
        , _capacity(count)
        , _elements(NULL)
    {

        _elements = _allocator.allocate(count);
        _allocator.construct(_elements, value);
        _begin = _elements;
        _end = &_elements[size()];
        for(size_t i = 0; i < size(); ++i)
        {
            _elements[i] = value;
        }
    };

    ~vector()
    {
        if(capacity() > 0)
        {
            _allocator.deallocate(_elements, capacity());
        }
    }

    // ELEMENT ACCESS
    reference at(size_type pos)
    {
        if(!(pos < size()))
        {
            throw std::out_of_range("Invalid at pos, out of range");
        }
        return _elements[pos];
    };

    const_reference at(size_type pos) const
    {
        if(!(pos < size()))
        {
            throw std::out_of_range("Invalid at pos, out of range");
        }
        return _elements[pos];
    };

    reference operator[](size_type pos)
    {
        return _elements[pos];
    };

    const_reference operator[](size_type pos) const
    {
        return _elements[pos];
    };

    reference front()
    {
        return _elements[0];
    };

    const_reference front() const
    {
        return _elements[0];
    };

    reference back()
    {
        return _elements[size() - 1];
    };

    const_reference back() const
    {
        return _elements[size() - 1];
    };

    T* data()
    {
        return _elements;
    };
    const T* data() const
    {
        return _elements;
    };

    // CAPACITY
    bool empty() const
    {
        return _size == 0;
    };
    size_type size() const
    {
        // TODO
        return _size; // std::distance(begin(), end())
    };
    size_type max_size() const
    {
        return std::numeric_limits<difference_type>::max() / sizeof(value_type);
    };
    size_type capacity() const
    {
        return _capacity;
    };
    void reserve(size_type new_cap)
    {
        if(new_cap > max_size())
        {
            throw std::length_error("Invalid reserve new_cap");
        }
        reallocate(new_cap);
    }

    // MODIFIERS
    void clear()
    {
        _size = 0;
    }

    iterator insert(iterator pos, const T& value)
    {
        difference_type index = pos - begin();
        if(size() + 1 > capacity())
        {
            reallocate(getNewCapacity());
        }
        for(difference_type cur = size(); cur > index; --cur)
        {
            _elements[cur] = _elements[cur - 1];
        }
        ++_end;
        ++_size;
        _elements[index] = value;
        return &(_elements[index]);
    }

    // void insert( iterator pos, size_type count, const T& value );
    // iterator erase( iterator pos );
    // iterator erase( iterator first, iterator last );
    void push_back(const T& value)
    {
        // TODO with iterators
        if(size() >= capacity())
        {
            reallocate(getNewCapacity());
        }
        _elements[size()] = value;
        ++_size;
        ++_end;
    };

    void pop_back()
    {
        --_size;
        --_end;
    }

    void resize(size_type count, T value = T())
    {
        if(capacity() < count)
        {
            size_t oldSize = size();
            reallocate(count);
            _size = count;
            for(size_type i = oldSize; i < size(); ++i)
            {
                _elements[i] = value;
            }
        }
        else if(size() > count)
        {
            _end -= _size - count;
            _size = count;
        }
    }

    void swap(vector& other)
    {
        pointer elements_tmp = this->_elements;
        this->_elements = other._elements;
        other._elements = elements_tmp;

        iterator it_tmp = this->_end;
        this->_end = other._end;
        other._end = it_tmp;

        this->_begin = &this->_elements[0];
        other._begin = &other._elements[0];

        size_type capacity_tmp = this->_capacity;
        this->_capacity = other._capacity;
        other._capacity = capacity_tmp;

        size_type size_tmp = this->_size;
        this->_size = other._size;
        other._size = size_tmp;
    }

    // ITERATOR
    iterator begin()
    {
        return _begin;
    };
    iterator end()
    {
        return _end;
    };
    const_iterator begin() const
    {
        return _begin;
    };
    const_iterator end() const
    {
        return _end;
    };
    // iterator rend();
    // iterator rbegin();
    // const_iterator rbegin() const;
    // const_iterator rend() const;

    // OPERATORS OVERLOAD
    // vector &operator=(const vector &other) {}
    // void assign(size_type count, const T &value);
    // allocator_type get_allocator() const;

    // NON-MEMBER FUNCTIONS
    // operator==
    // template <class T, class Alloc>
    // bool operator==(const std::vector<T, Alloc> &lhs,
    //                 const std::vector<T, Alloc> &rhs);

    // operator!=
    // template <class T, class Alloc>
    // bool operator!=(const std::vector<T, Alloc> &lhs,
    //                 const std::vector<T, Alloc> &rhs);

    // operator<
    // template <class T, class Alloc>
    // bool operator<(const std::vector<T, Alloc> &lhs,
    //                const std::vector<T, Alloc> &rhs);

    // operator<=
    // template <class T, class Alloc>
    // bool operator<=(const std::vector<T, Alloc> &lhs,
    //                 const std::vector<T, Alloc> &rhs);

    // operator>
    // template <class T, class Alloc>
    // bool operator>(const std::vector<T, Alloc> &lhs,
    //                const std::vector<T, Alloc> &rhs);

    // operator>=
    // template <class T, class Alloc>
    // bool operator>=(const std::vector<T, Alloc> &lhs,
    //                 const std::vector<T, Alloc> &rhs);

    // std::swap(std::vector)
    // template <class T, class Alloc>
    // void swap(std::vector<T, Alloc> &lhs, std::vector<T, Alloc> &rhs);

private:
    size_type getNewCapacity() const
    {
        if(capacity() == 0)
        {
            return 1;
        }
        return capacity() * 2;
    };

    void reallocate(size_type new_cap)
    {
        size_type oldCapacity = capacity();
        pointer oldElements = _elements;
        _elements = _allocator.allocate(new_cap);
        _capacity = new_cap;
        _begin = _elements;
        _end = _elements;
        if(oldElements == NULL)
        {
            return;
        }
        for(size_type i = 0; i < size(); ++i)
        {
            _elements[i] = oldElements[i];
        }
        _end += size();
        _allocator.deallocate(oldElements, oldCapacity);
    }

    allocator_type _allocator;
    size_type _size;
    size_type _capacity;
    pointer _elements;
    iterator _begin;
    iterator _end;
};

} // namespace ft
#endif // VECTOR_H
