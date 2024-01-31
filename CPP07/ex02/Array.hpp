
#include <iostream>
#include <string>

template <typename T>
class Array {
private:
    T *array;
    unsigned int size;
public:
    unsigned int size(void) const {
        return this->size;
    }
    Array() {
        this->array = NULL;
        this->size = 0;
    }
    Array(unsigned int n) {
        this->array = new T[n];
        this->size = n;
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
            this->array = new T[src.size];
            for (unsigned int i = 0; i < src.size; i++)
                this->array[i] = src.array[i];
            this->size = src.size;
        }
        return *this;
    }
    T &operator[](unsigned int i) {
        if (i >= this->size) {
            throw std::exception();
        }
        return this->array[i];
    }
    
   
};
