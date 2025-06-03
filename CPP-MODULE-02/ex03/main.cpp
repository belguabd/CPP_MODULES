
#include "Point.hpp"

int main(void)
{

    Point a(0, 20);
    Point b(20, 20);
    Point c(30, 30);
    Point point(19, 25);
    if(bsp(a, b, c, point))
        std::cout << "Point is inside the triangle\n";
    else
        std::cout << "Point is outside the triangle\n";

    return 0;
}