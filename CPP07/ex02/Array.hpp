
#include <iostream>
#include <string>

template <typename T>
class Array {
private:
    T *array;
    unsigned int _size;
public:
    unsigned int size(void) const {
        return this->_size;
    }
    Array() {
        this->array = NULL;
        this->_size = 0;
    }
    Array(unsigned int n) {
        this->array = new T[n];
        this->_size = n;
    }
    Array(const Array &src) {
        *this = src;
    }
     ~Array() {
        delete[] this->array;
    }
    Array &operator=(const Array &src) {
        if (this != &src) {
            delete[] this->array;
            this->array = new T[src._size];
            for (unsigned int i = 0; i < src._size; i++)
                this->array[i] = src.array[i];
            this->_size = src._size;
        }
        return *this;
    }
    T &operator[](unsigned int i) {
        if (i >= this->_size) {
            throw std::exception();
        }
        return this->array[i];
    }
    
   
};
