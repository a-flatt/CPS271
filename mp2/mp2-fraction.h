#include <iostream>

using namespace std;

class Fraction {
    
    // Note: no simplification function has been implemented yet as not in spec. 

    int num, den;

    public: 

        // Constructors:
        Fraction ();
        Fraction (int n);
        Fraction (double d);
        Fraction (int n, int d);

        // Functions 5-8
        Fraction add (Fraction f2);
        Fraction subtract (Fraction f2);
        Fraction multiply (Fraction f2);
        Fraction divide (Fraction f2);

        // Functions 9-12
        void add (Fraction f1, Fraction f2);
        void subtract (Fraction f1, Fraction f2);
        void multiply (Fraction f1, Fraction f2);
        void divide (Fraction f1, Fraction f2);

        bool checkFraction (istream& input);
        void math_op (Fraction f1, Fraction f2, char oper);
        void print ();
};

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