
#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

template <typename T> typename T::iterator easyfind(T &container, int n)
{
    typename T::iterator it = std::find(container.begin(), container.end(), n);
    if (it == container.end())
        throw std::exception();
    return it;
}
template <typename T> const typename T::const_iterator easyfind(const T &container, int n)
{
    const typename T::const_iterator it = std::find(container.begin(), container.end(), n);
    if (it == container.end())
        throw std::exception();
    return it;
}