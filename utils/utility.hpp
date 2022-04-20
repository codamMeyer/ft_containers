#ifndef __UTILITY_H__
#define __UTILITY_H__

#include <cstddef>

#include <iterator/IteratorTraits.hpp>
#include <iterator>

namespace ft
{

template <typename T>
void swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

namespace detail
{

template <class It>
typename ft::iterator_traits<It>::difference_type
do_distance(It first, It last, std::input_iterator_tag)
{
    typename ft::iterator_traits<It>::difference_type result = 0;
    while(first != last)
    {
        ++first;
        ++result;
    }
    return result;
}

template <class It>
typename ft::iterator_traits<It>::difference_type
do_distance(It first, It last, std::random_access_iterator_tag)
{
    return last - first;
}

} // namespace detail

template <class InputIt>
typename ft::iterator_traits<InputIt>::difference_type distance(InputIt first, InputIt last)
{
    return detail::do_distance(
        first, last, typename ft::iterator_traits<InputIt>::iterator_category());
}

} // namespace ft
#endif // __UTILITY_H__