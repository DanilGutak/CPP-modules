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
        Fixed(Fixed const &src);
        ~Fixed();
        Fixed &operator=(Fixed const & src);
        int getRawBits(void) const;
        void setRawBits(int const raw);

};