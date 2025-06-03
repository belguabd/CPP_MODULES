
#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>


class Fixed
{
private:
    int _value;
    static const int fractionalBits;

public:
    Fixed();
    Fixed &operator=(const Fixed &obj);
    Fixed(const Fixed &obj);
    ~Fixed();

    Fixed(const int _value);
    Fixed(const float floatingPoint);

    int toInt(void) const;
    float toFloat(void) const;  
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif