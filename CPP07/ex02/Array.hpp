
#include <iostream>
#include <string>

template <typename Type> void iter(const Type *array, int len, void (*f)(Type const &))
{
    for (int i = 0; i < len; i++)
        f(array[i]);
}

template <typename Type> void iter(Type *array, int len, void (*f)(Type &))
{
    for (int i = 0; i < len; i++)
        f(array[i]);
}
