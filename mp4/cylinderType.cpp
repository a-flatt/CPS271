#include "cylinderType.h"

cylinderType::cylinderType (const circleType &circle, int h)
:
    d_circle(circle),
    d_h(h)
{}


double cylinderType::volume ()
{
    return d_circle.circleType::pi() * pow(d_circle.r(), 2) * d_h;
}

double cylinderType::surfaceArea ()
{
    return 2 * d_circle.circleType::pi() * d_circle.circleType::r() * d_h + 2 * d_circle.circleType::pi() * pow(d_circle.circleType::r(), 2);
}

void cylinderType::setR(int r)
{
    d_circle.circleType::setR(r);
}

void cylinderType::setC (int x, int y)
{
    d_circle.circleType::setC(x, y);
}

void cylinderType::setH (int h)
{
    d_h = h;
}

void cylinderType::printVolume ()
{
    cout << volume() << "\n";
}

void cylinderType::printSurfaceArea ()
{
    cout << surfaceArea() << "\n";
}


