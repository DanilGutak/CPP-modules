
#include <iostream>
#include <string>

template <typename Type> Type min(Type a, Type b) {
    return (a < b ? a : b);
}
template <typename T> T max(T a, T b) {
    return (a > b ? a : b);
}
template <typename T> void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

