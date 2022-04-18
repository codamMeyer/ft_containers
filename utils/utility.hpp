#ifndef __UTILITY_H__
#define __UTILITY_H__

namespace ft
{

template <typename T>
void swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

} // namespace ft
#endif // __UTILITY_H__