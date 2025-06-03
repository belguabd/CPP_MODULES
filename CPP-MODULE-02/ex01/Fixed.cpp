#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed(const int _value) : _value(_value << fractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
};

Fixed::Fixed(const float floatingPoint) : _value(std::roundf(floatingPoint * (1 << fractionalBits)))
{
    std::cout << "Float constructor called" << std::endl;
};

int Fixed::toInt(void) const
{
    return (this->_value >> 8);
}

float Fixed::toFloat(void) const
{
    return (float)this->_value / (1 << fractionalBits);
}

Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_value = obj._value;
}

std::ostream &operator<<(std::ostream &os, const Fixed &copy)
{
    os << copy.toFloat();
    return (os);
}

Fixed &Fixed::operator=(const Fixed &copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
        this->_value = copy._value;
    return (*this);
}

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}