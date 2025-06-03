#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
    const Fixed x;
    const Fixed y;

public:
    Point();
    ~Point();
    Point(const Point &point);
    Point &operator=(const Point &obj);

    int getX() const;
    int getY() const;
    
    Point(const float xCoordinate, const float yCoordinate);
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif