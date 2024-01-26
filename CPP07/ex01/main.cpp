#include "iter.hpp"
template <typename T> void print(T const &x) {
    std::cout << x << " ";
}
template <typename T> void print(T &x) {
    std::cout << x << " ";
}
int main( void ) {
    int a[10] = {7 , 8, 9, 10, 11, 12, 13, 14, 15, 16};
    const int b[10] = {9,8,7,6,5,4,3,2,1,0};

    iter(a, 10, print);
    std::cout << "\n";
    iter(b, 10, print);
    std::cout << "\n";


    char c[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    const char d[10] = {'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};
    std::cout << "\n";

    iter(c, 10, print);
    std::cout << "\n";
    iter(d, 10, print);
    std::cout << "\n";
    std::cout << "\n";

    std::string e[10] = {"heh", "bon", "cc", "dasd", "e21", "vf", "bgg", "fh", "ii"};
    const std::string f[10] = {"ii", "fh", "bgg", "vf", "e21", "dasd", "cc", "bon", "heh"};
    iter(e, 10, print);
    std::cout << "\n";
    iter(f, 10, print);
    std::cout << "\n";
    return 0;






}