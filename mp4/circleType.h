#ifndef CIRCLETYPE_H_
#define CIRCLETYPE_H_

#include "pointType.h"
#include <cmath>
using namespace std;

class circleType: public pointType {

    int d_r;

    protected:
        double d_pi = 3.14159;

    public:

        // circleType ();
        circleType (const pointType &point, double r);
        
        void setR (int const &r);
        void setC (int x, int y);
        double area ();
        double circumference ();
        void printArea ();
        void printCircumference ();
        int r () const;
        double pi () const;

};

#endif