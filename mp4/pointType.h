#ifndef POINTTYPE_H_
#define POINTTYPE_H_

#include <iostream>
using namespace std;

class pointType {

    int d_x, d_y;

    public:
        pointType ();
        pointType (int x, int y);
        
        void setX (int x);
        void setY (int y);
        void printCoor ();

        int x ();
        int y ();
};
#endif