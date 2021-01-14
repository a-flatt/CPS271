#pragma once
#include <iostream>

using namespace std;

class Fraction {
    
    int num, den;

    public: 

        Fraction ();
        Fraction (int n);
        Fraction (double d);
        Fraction (int n, int d);

        // OPERATOR OVERLOADS
        void operator+= (double toAdd);

        bool checkFraction (istream& input);
        void print ();
    
    private:
        void reduce ();
};

