#include "circleType.h"

circleType::circleType (const pointType &point, double r)
:
    pointType(point),
    d_r(r)
{}

void circleType::setR (int const &r)
{
    d_r = r;
}

void circleType::setC (int x, int y)
{
    pointType::setX(x);
    pointType::setY(y);
}

double circleType::area () 
{
    return d_pi * pow(d_r, 2);
}

double circleType::circumference () 
{
    return 2 * d_pi * d_r;
}

void circleType::printArea () 
{
    cout << area() << "\n";
}

void circleType::printCircumference () 
{
    cout << circumference() << "\n";
}

int circleType::r () const
{
    return d_r;
}

double circleType::pi () const
{
    return d_pi;
}