#ifndef CYLINDERTYPE_H_
#define CYLINDERTYPE_H_

#include "circleType.h"

class cylinderType {

    int d_h;

    protected:
        

    public:
        circleType d_circle;
        cylinderType ();
        cylinderType (const circleType &circle, int h);

        cylinderType inputData();
        // double pi ();        
        double volume ();
        double surfaceArea ();

        void setH (int h);
        void setR (int r);
        void setC (int x, int y);
        void printVolume ();
        void printSurfaceArea ();
};

#endif