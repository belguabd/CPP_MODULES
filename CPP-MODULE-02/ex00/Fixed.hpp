#include <iostream>

class Fixed
{
private:
    int rawValue;
    static const int fractional_Bits;

public:
    Fixed();
    Fixed(const Fixed &copy);
    Fixed &operator=(const Fixed &copy);
    ~Fixed();
    
    int getRawBits(void) const;
    void setRawBits(int const raw);
};
