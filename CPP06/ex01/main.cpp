
#include "Serializer.hpp"

int main()
{
    Data *data = new Data;
    data->s1 = "Hello";
    data->n = 42;
    data->s2 = "World";
    uintptr_t raw = Serializer::serialize(data);
    Data *data2 = Serializer::deserialize(raw);
    std::cout << data2->s1 << std::endl;
    std::cout << data2->n << std::endl;
    std::cout << data2->s2 << std::endl;

    return 0;
}