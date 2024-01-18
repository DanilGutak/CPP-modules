#include <cstddef>
#include <iostream>
#include <fstream>
#include <string>

class Fixed
{
    private:
        int value;
        static const int bits = 8;
    public:
        Fixed();
        Fixed(int value);
        Fixed(float value);
        Fixed(Fixed const &src);
        ~Fixed();
        Fixed &operator=(Fixed const & src);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;
        
        int operator>(const Fixed & src) const;
        int operator<(const Fixed & src) const;
        int operator>=(const Fixed & src) const;
        int operator<=(const Fixed & src) const;
        int operator==(const Fixed & src) const;
        int operator!=(const Fixed & src) const;

        Fixed operator+(const Fixed & src) const;
        Fixed operator-(const Fixed & src) const;
        Fixed operator*(const Fixed & src) const;
        Fixed operator/(const Fixed & src) const;

        Fixed &operator++();
        Fixed operator++(int);
        Fixed &operator--();
        Fixed operator--(int);

        static const Fixed &min(const Fixed &a, const Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
        static Fixed &min(Fixed &a, Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
};
        std::ostream	&operator<<( std::ostream &stream, const Fixed &point );
