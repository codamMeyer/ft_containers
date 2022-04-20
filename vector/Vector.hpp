#ifndef VECTOR_H
#define VECTOR_H
#include <cstddef>
#include <iostream>
#include <iterator>
#include <limits>
#include <memory>
#include <stdexcept>

#include "VectorIterator.hpp"
#include "utils/type_traits.hpp"
#include <utils/utility.hpp>

namespace ft
{

// TODO review exception texts
template <class T, class Allocator = std::allocator<T>>
class vector
{

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
    typedef vector_iterator<T> iterator;
    typedef const vector_iterator<T> const_iterator;
    typedef vector_reverse_iterator<T> reverse_iterator;
    typedef const vector_reverse_iterator<T> const_reverse_iterator;

    vector()
        : _capacity(0)
        , _elements(NULL)
        , _begin(NULL)
        , _end(NULL){};

    explicit vector(const Allocator& alloc)
        : _allocator(alloc)
        , _capacity(0)
        , _elements(NULL)
        , _begin(NULL)
        , _end(NULL){};

    explicit vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator())
        : _allocator(alloc)
        , _capacity(count)
        , _elements(NULL)
    {

        _elements = _allocator.allocate(count);
        _allocator.construct(_elements, value);
        _begin = _elements;
        _end = &_elements[count];

        for(size_t i = 0; i < size(); ++i)
        {
            _allocator.construct(&_elements[i], value);
        }
    };

    // template <class InputIt>
    // vector(InputIt first, InputIt last, const Allocator& alloc = Allocator());

    vector(const vector& other)
        : _allocator(other._allocator)
        , _capacity(other._capacity)
        , _elements(NULL)
        , _begin(NULL)
        , _end(NULL)
    {
        if(!other.empty())
        {
            _elements = _allocator.allocate(other._capacity);
            for(size_t i = 0; i < other.size(); ++i)
            {
                this->_allocator.construct(&this->_elements[i], other._elements[i]);
            }
            _begin = &_elements[0];
            _end = &_elements[other.size()];
        }
    }

    ~vector()
    {
        if(capacity() > 0)
        {
            clear();
            _allocator.deallocate(_elements, capacity());
        }
    }

    // OPERATORS OVERLOAD
    vector& operator=(const vector& other)
    {
        vector tmp(other);
        swap(tmp);

        return *this;
    }

    void assign(size_type count, const T& value)
    {
        clear();
        if(count > capacity())
        {
            reallocate(count);
        }
        for(size_type i = 0; i < count; ++i)
        {
            _allocator.construct(&_elements[i], value);
        }
        _end = _begin + count;
    }

    // template< class InputIt >
    // void assign( InputIt first, InputIt last );

    allocator_type get_allocator() const
    {
        return _allocator;
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
        return *_begin;
    };

    const_reference front() const
    {
        return *_begin;
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

    reverse_iterator rbegin()
    {
        return reverse_iterator(_elements + size() - 1);
    }

    reverse_iterator rbegin() const
    {
        return reverse_iterator(_elements + size() - 1);
    }

    reverse_iterator rend()
    {
        return reverse_iterator(_elements - 1);
    }
    const_reverse_iterator rend() const
    {
        return reverse_iterator(_elements - 1);
    }

    // CAPACITY
    bool empty() const
    {
        return begin() == end();
    };

    size_type size() const
    {
        return ft::distance(begin(), end());
    };

    size_type max_size() const
    {
        return std::numeric_limits<difference_type>::max() / sizeof(value_type);
    };

    void reserve(size_type new_cap)
    {
        if(new_cap > max_size())
        {
            throw std::length_error("Invalid reserve new_cap");
        }

        // n = ft::max(n, this->_capacity * 2); TODO
        reallocate(new_cap);
    }

    size_type capacity() const
    {
        return _capacity;
    };

    // MODIFIERS
    void clear()
    {
        destroyElements(0, size());
        _end = _begin;
    }

    iterator insert(iterator pos, const T& value)
    {
        difference_type offset = pos - begin();
        insert(pos, 1, value);
        pos = begin() + offset;
        return pos;
    }

    void insert(iterator pos, size_type count, const T& value)
    {
        if(size() + count > capacity())
        {
            difference_type offset = pos - begin();
            reallocate(size() + count);
            pos = begin() + offset;
        }

        iterator i = end() - 1;
        iterator j = i + count;
        _end += count;

        for(; i >= pos; --i, --j)
        {
            _allocator.construct(&(*j), *i);
            _allocator.destroy(&(*j));
        }
        for(iterator it = pos; it < (pos + count); ++it)
        {
            _allocator.construct(&(*it), value);
        }
    }

    template <class InputIt>
    typename ft::enable_if<ft::is_iterator<typename InputIt::iterator_category>::value>::type
    insert(iterator pos, InputIt first, InputIt last)
    {
        const size_type count = ft::distance(first, last);

        if(size() + count > capacity())
        {
            difference_type offset = pos - begin();
            reallocate(size() + count);
            pos = begin() + offset;
        }
        _end += count;
        for(; first != last; ++first, ++pos)
        {
            _allocator.construct(&(*pos), *first);
        }
    }

    iterator erase(iterator pos)
    {
        if(pos == (end() - 1))
        {
            --_end;
            return end();
        }
        return erase(pos, pos + 1);
    }

    iterator erase(iterator first, iterator last)
    {
        difference_type diff = ft::distance(first, last);
        if(diff > 0)
        {
            for(iterator it = last; it != end(); ++it)
            {
                _allocator.destroy(&(*first));
                _allocator.construct(&(*first), *it);
                ++first;
            }
        }
        if(last == end())
        {
            return _end -= diff;
        }
        _end -= diff;
        return last - diff;
    }

    void push_back(const T& value)
    {
        if(size() >= capacity())
        {
            reallocate(getNewCapacity());
        }
        _allocator.construct(&(*_end), value);
        ++_end;
    };

    void pop_back()
    {
        if(empty())
        {
            return;
        }
        _allocator.destroy(_elements + size() - 1);
        --_end;
    }

    void resize(size_type count, T value = T())
    {
        if(count <= size())
        {
            destroyElements(count, size());
            _end -= size() - count;

            return;
        }
        if(count > capacity())
        {
            reallocate(count);
        }
        iterator oldEnd = _end;
        _end = _begin + count;
        for(iterator it = oldEnd; it != end(); ++it)
        {
            _allocator.construct(&(*it), value);
        }
    }

    void swap(vector& other)
    {
        ft::swap(this->_elements, other._elements);
        ft::swap(this->_end, other._end);
        ft::swap(this->_begin, other._begin);
        ft::swap(this->_capacity, other._capacity);
    }

private:
    size_type getNewCapacity() const
    {
        if(capacity() == 0)
        {
            return 1;
        }
        return capacity() * 2;
    };

    void destroyElements(size_type from, size_type to)
    {
        for(size_type i = from; i < to; ++i)
        {
            _allocator.destroy(_elements + i);
        }
    }

    void reallocate(size_type new_cap)
    {
        size_type oldSize = size();
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
        for(size_type i = 0; i < oldSize; ++i)
        {
            _allocator.construct(&_elements[i], oldElements[i]);
            _allocator.destroy(&oldElements[i]);
        }
        _end += oldSize;
        _allocator.deallocate(oldElements, oldCapacity);
    }

    allocator_type _allocator;
    size_type _capacity;
    pointer _elements;
    iterator _begin;
    iterator _end;
};

// NON-MEMBER FUNCTIONS
// operator==
template <class T, class Alloc>
bool operator==(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{
    if(lhs.size() != rhs.size())
    {
        return false;
    }
    typename ft::vector<T>::iterator lit = lhs.begin();
    typename ft::vector<T>::iterator rit = rhs.begin();
    for(; lit != lhs.end() && rit != rhs.end(); ++lit, ++rit)
    {
        if(*lit != *rit)
        {
            return false;
        }
    }
    return true;
}

// operator!=
template <class T, class Alloc>
bool operator!=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{
    return !(lhs == rhs);
}

// operator<
template <class T, class Alloc>
bool operator<(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{
    if(lhs.size() < rhs.size())
    {
        return true;
    }
    typename ft::vector<T>::iterator lit = lhs.begin();
    typename ft::vector<T>::iterator rit = rhs.begin();
    for(; lit != lhs.end() && rit != rhs.end(); ++lit, ++rit)
    {
        if(*lit != *rit)
        {
            return (*lit - *rit);
        }
    }
    return (false);
}

// operator<=
template <class T, class Alloc>
bool operator<=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{
    return (lhs == rhs || lhs < rhs);
}

// operator>
template <class T, class Alloc>
bool operator>(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{
    if(lhs.size() > rhs.size())
    {
        return true;
    }
    typename ft::vector<T>::iterator lit = lhs.begin();
    typename ft::vector<T>::iterator rit = rhs.begin();
    for(; lit != lhs.end() && rit != rhs.end(); ++lit, ++rit)
    {
        if(*lit != *rit)
        {
            return (*lit - *rit);
        }
    }
    return (false);
}

// operator>=
template <class T, class Alloc>
bool operator>=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{
    return (lhs == rhs || lhs > rhs);
}

template <class T, class Alloc>
void swap(vector<T, Alloc>& lhs, vector<T, Alloc>& rhs)
{
    vector<T, Alloc> tmp(lhs);
    lhs = rhs;
    rhs = tmp;
}
} // namespace ft

#endif // VECTOR_H
