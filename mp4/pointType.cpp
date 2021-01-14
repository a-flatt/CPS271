#include "pointType.h"

pointType::pointType (int x, int y)
:
    d_x(x),
    d_y(y)
{}

void pointType::setX (int x)
{
    d_x = x;
}

void pointType::setY (int y)
{
    d_y = y;
}

void pointType::printCoor ()
{
    cout << "(" << d_x << "," << d_y << ")" << "\n";
}

int pointType::x ()
{
    return d_x;
}

int pointType::y ()
{
    return d_y;
}