#ifndef VECTOR_H
#define VECTOR_H
#include <limits>
#include <memory>

namespace ft {

template <class T, class Allocator = std::allocator<T>> class vector {
public:
  typedef T value_type;
  typedef Allocator allocator_type;
  typedef std::size_t size_type;
  typedef std::ptrdiff_t difference_type;

  vector() : cur_size(0){};

  explicit vector(size_type count, const T &value = T(),
                  const Allocator &alloc = Allocator())
      : cur_size(count){};

  ~vector() {}

  bool empty() const { return cur_size == 0; };
  size_type size() const {
    return cur_size; // std::distance(begin(), end())
  };
  size_type max_size() const {
    return std::numeric_limits<difference_type>::max();
  };

private:
  size_type cur_size;
  // MEMBER TYPES
  // value_type
  // allocator_type
  // size_type
  // reference
  // const_reference
  // pointer
  // const_pointer
  // iterator
  // const_iterator
  // reverse_iterator
  // const_reverse_iterator

  // PUBLIC MEMBER FUNCTIONS
  // vector &operator=(const vector &other) {}
  // void assign(size_type count, const T &value);
  // allocator_type get_allocator() const;

  // ELEMENT ACCESS
  // reference at(size_type pos);
  // const_reference at( size_type pos ) const;
  // reference operator[](size_type pos);
  // const_reference operator[]( size_type pos ) const;
  // reference front();
  // const_reference front() const;
  // reference back();
  // const_reference back() const;
  // T *data();
  // const T* data() const noexcept;

  // ITERATOR
  // iterator begin();
  // iterator end();
  // iterator rbegin();
  // iterator rend();
  // const_iterator begin() const noexcep;
  // const_iterator end() const noexcep;
  // const_iterator rbegin() const noexcep;
  // const_iterator rend() const noexcep;

  // CAPACITY
  // void reserve(size_type new_cap);
  // size_type capacity() const;
  // size_type capacity() const noexcept;

  // MODIFIERS
  // void clear();
  // iterator insert( iterator pos, const T& value );
  // iterator erase( iterator pos );
  // iterator erase( iterator first, iterator last );
  // void push_back( const T& value );
  // void pop_back();
  // void resize( size_type count );
  // void resize( size_type count, T value = T() );
  // void swap( vector& other );

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
};

} // namespace ft
#endif // VECTOR_H