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

int Fixed::getRawBits(void) const { return (this->_value); }
void Fixed::setRawBits(int const raw) { this->_value = raw; }

bool Fixed::operator>(const Fixed &obj) const { return (this->_value > obj._value); }
bool Fixed::operator<(const Fixed &obj) const { return (this->_value < obj._value); }
bool Fixed::operator>=(const Fixed &obj) const { return (this->_value >= obj._value); }
bool Fixed::operator<=(const Fixed &obj) const { return (this->_value <= obj._value); }
bool Fixed::operator==(const Fixed &obj) const { return (this->_value == obj._value); }
bool Fixed::operator!=(const Fixed &obj) const { return (this->_value != obj._value); }

Fixed Fixed::operator+(const Fixed &obj) const
{
    Fixed newObj;
    newObj._value = this->toFloat() + obj.toFloat();
    return newObj;
}
Fixed Fixed::operator-(const Fixed &obj) const
{
    return Fixed(this->toFloat() - obj.toFloat());
}

Fixed Fixed::operator*(const Fixed &obj) const
{
    return Fixed((this->toFloat() * obj.toFloat()));
}

Fixed Fixed::operator/(const Fixed &obj) const
{
    if (obj._value != 0)
        return Fixed(this->toFloat() / obj.toFloat());
    std::cerr << "Division by zero is not allowed" << std::endl;
    std::exit(EXIT_FAILURE);
}

std::ostream &operator<<(std::ostream &out, const Fixed &f)
{
    out << f.toFloat();
    return (out);
}

Fixed &Fixed::operator++()
{
    ++_value;
    return (*this);
}
Fixed &Fixed::operator--()
{
    --_value;
    return (*this);
}
Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    ++_value;
    return (tmp);
}
Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    --_value;
    return (tmp);
}

Fixed &Fixed::min(Fixed &fixedPoint1, Fixed &fixedPoint2)
{
    return fixedPoint1._value < fixedPoint2._value ? fixedPoint1 : fixedPoint2;
}

const Fixed &Fixed::min(const Fixed &fixedPoint1, const Fixed &fixedPoint2)
{
    return (fixedPoint1._value < fixedPoint2._value) ? fixedPoint1 : fixedPoint2;
}

Fixed &Fixed::max(Fixed &fixedPoint1, Fixed &fixedPoint2)
{
    return fixedPoint1._value > fixedPoint2._value ? fixedPoint1 : fixedPoint2;
}

const Fixed &Fixed::max(const Fixed &fixedPoint1, const Fixed &fixedPoint2)
{
    return (fixedPoint1._value > fixedPoint2._value) ? fixedPoint1 : fixedPoint2;
}
