#include "Fixed.hpp"
Fixed::Fixed()
{
    this->value = 0;
    std::cout << "Default constructor called\n";
}
Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}
Fixed::Fixed(const Fixed & src)
{
    std::cout << "Copy constructor called\n";
    *this=src;
}
Fixed & Fixed::operator=(Fixed const & src)
{
    std::cout << "Copy operator called\n";
    if (this != &src)
    {
        this->value = src.getRawBits();
    }
    return *this;
}
void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits function called\n";
    this->value = raw;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits function called\n";
    return this->value;
}