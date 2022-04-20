#ifndef __TYPE_TRAITS_H__
#define __TYPE_TRAITS_H__

#include <iterator/IteratorTraits.hpp>

namespace ft
{

template <typename T, typename C = void>
struct is_iterator
{
    static const bool value = false;
};

template <>
struct is_iterator<std::input_iterator_tag>
{
    static const bool value = true;
};

template <>
struct is_iterator<std::output_iterator_tag>
{
    static const bool value = true;
};

template <>
struct is_iterator<std::forward_iterator_tag>
{
    static const bool value = true;
};

template <>
struct is_iterator<std::bidirectional_iterator_tag>
{
    static const bool value = true;
};

template <>
struct is_iterator<std::random_access_iterator_tag>
{
    static const bool value = true;
};

template <typename T, typename U>
struct is_same
{
    static const bool value = false;
};

template <typename T>
struct is_same<T, T>
{
    static const bool value = true;
};

template <bool b, class T = void>
struct enable_if
{};

template <class T>
struct enable_if<true, T>
{
    typedef T type;
};

} // namespace ft

#endif // __TYPE_TRAITS_H__