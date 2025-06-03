#include "Fixed.hpp"


const int Fixed::fractionalBits = 8;

Fixed::Fixed() : _value(0) {};

Fixed::Fixed(const Fixed &obj) { this->_value = obj._value; }

Fixed &Fixed::operator=(const Fixed &obj)
{
    if (this != &obj)
        this->_value = obj._value;
    return (*this);
}

Fixed::~Fixed() {};

Fixed::Fixed(const int rawValue) : _value(rawValue * (1 << fractionalBits)) {};

Fixed::Fixed(const float floatingPoint) : _value(std::roundf(floatingPoint * (1 << fractionalBits))) {};

float Fixed::toFloat(void) const
{
    return (float)this->_value / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
    return (_value >> fractionalBits);
}


int Fixed::getRawBits(void) const
{
    return (this->_value);
}