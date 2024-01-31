# include "Array.hpp"

int main(){
    Array<int> a(5);

    for (int i = 0; i < 5; i++)
        a[i] = i;
    
    Array<int> b(a);
    Array<int> c;
    c = a;
    Array<int> d(0);

    c[0] = 42;
    std::cout << "a: " << a[0] << std::endl;
    std::cout << "b: " << b[0] << std::endl;

    std::cout << "c: " << c[0] << std::endl;

    try {
        std::cout << "d: " << d[0] << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "d: " << e.what() << std::endl;
    }
    int i = a.size(); 

};