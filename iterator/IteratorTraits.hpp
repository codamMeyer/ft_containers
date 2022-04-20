#ifndef __ITERATORTRAITS_H__
#define __ITERATORTRAITS_H__
#include <cstddef>
#include <iterator>

namespace ft
{

template <class Category,
          class T,
          class Distance = ptrdiff_t,
          class Pointer = T*,
          class Reference = T&>
struct iterator
{
    typedef T value_type;
    typedef Distance difference_type;
    typedef Pointer pointer;
    typedef Reference reference;
    typedef Category iterator_category;
};

template <class T>
struct iterator_traits
{
    typedef typename T::value_type value_type;
    typedef typename T::difference_type difference_type;
    typedef typename T::iterator_category iterator_category;
    typedef typename T::pointer pointer;
    typedef typename T::reference reference;
};
} // namespace ft

#endif // __ITERATORTRAITS_H__