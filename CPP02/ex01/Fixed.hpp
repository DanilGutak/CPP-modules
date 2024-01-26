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
};
std::ostream	&operator<<( std::ostream &stream, const Fixed &point );
