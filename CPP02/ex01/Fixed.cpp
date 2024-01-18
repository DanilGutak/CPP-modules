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

Fixed::Fixed(int value)
{
    this->value = value << this->bits;
    std::cout << "Int constructor called\n";
}
Fixed::Fixed(float value)
{
    this->value = roundf(value * (1 << this->bits));
    std::cout << "Float constructor called\n";
}
float Fixed::toFloat( void ) const
{
    return (float)this->value / (1 << this->bits);
}
int Fixed::toInt( void ) const
{
    return this->value >> this->bits;
}
std::ostream	&operator<<( std::ostream &stream, const Fixed &point )
{
    stream << point.toFloat();
    return stream;
}