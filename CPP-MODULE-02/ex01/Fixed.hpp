#include <cmath>
#include <iostream>
class Fixed
{
private:
    int _value;
    static const int fractionalBits;

public:
    Fixed();
    Fixed(const Fixed &copy);
    Fixed &operator=(const Fixed &copy);
    ~Fixed();

    int toInt(void) const;
    float toFloat(void) const;
    Fixed(const int _value);
    Fixed(const float floatingPoint);
};

std::ostream &operator<<(std::ostream &os, const Fixed &copy);