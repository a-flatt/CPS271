#include "cylinderType.h"
#include <iostream>

void outputData (cylinderType cylinder)
{
    int oper;
    
    while (oper != 4){
        cout << "What would you like to print information out about?" << "\n";
        cout << "1 = pointType, 2 = circleType, 3 = cylinderType, 4 = Quit." << "\n";
        cout << "Please enter your choice: ";
        cin >> oper;

        switch (oper) {
            case 1: 
                cout << "Information for pointType as follows: " << "\n";
                cout << "The coordinates of the points are: ";
                cylinder.d_circle.pointType::printCoor();
                break;
            case 2:
                cout << "Information for circleType (derived from pointType) as follows: " << "\n";
                cout << "The area of the circle is: ";
                cylinder.d_circle.printArea();
                cout << "The circumference of the circle is: ";
                cylinder.d_circle.printCircumference();
                break;
            case 3:
                cout << "Information for cylinderType (composed of circleType) as follows: " << "\n";
                cout << "The surface area of the cylinder is: ";
                cylinder.printSurfaceArea();
                cout << "The volume of the cylinder is: ";
                cylinder.printVolume();
                break;
        }
    }
}

void mainFunc ()
{
    int x, y, r, h;
    
    cout << "Please enter two point coordinates: ";
    cin >> x >> y;
    cout << "Please enter in the radius of the circle: ";
    cin >> r;
    cout << "Please enter in the height of the cyclinder: ";
    cin >> h;

    pointType point (x, y);
    circleType circle (point, r);
    cylinderType cylinder (circle, h);

    outputData(cylinder);
}

int main ()
{
    mainFunc();
}
