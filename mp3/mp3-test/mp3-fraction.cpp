
#include "mp3-fraction.h"

Fraction::Fraction ()
{
    num = 0;
    den = 0;
}

Fraction::Fraction (int n)
{
    num = n;
    den = 1;
}

Fraction::Fraction (double d)
{
    num = d * 100000;
    den = 100000;
}

Fraction::Fraction (int n, int d)
{
    num = n;
    den = d;
}

// BINARY FUNCTIONS

void Fraction::operator+= (double toAdd)
{
    // Fraction f;
    num = num + toAdd;
    // den = den;
    // return f;
}


// ASSIGNMENT TWO FUNCTIONS 

void Fraction::print () 
{
    cout << num << "/" << den << endl;
}

