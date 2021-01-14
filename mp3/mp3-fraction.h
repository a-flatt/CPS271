#include <iostream>

using namespace std;

class Fraction {
    
    friend ostream &operator<< (ostream &os, Fraction const &f);
    friend istream &operator>> (istream &is, Fraction &f);
    
    int num, den;

    public: 

        Fraction ();
        Fraction (int n);
        Fraction (double d);
        Fraction (int n, int d);

        // MEMBER FUNCTIONS
        Fraction add (Fraction f2);
        Fraction subtract (Fraction f2);
        Fraction multiply (Fraction f2);
        Fraction divide (Fraction f2);
        
        void add (Fraction f1, Fraction f2);
        void subtract (Fraction f1, Fraction f2);
        void multiply (Fraction f1, Fraction f2);
        void divide (Fraction f1, Fraction f2);
        
        // OPERATOR OVERLOADS
        Fraction &operator+= (Fraction const &f2);
        Fraction &operator-= (Fraction const &f2);
        Fraction &operator*= (Fraction const &f2);
        Fraction &operator/= (Fraction const &f2);
        Fraction &operator= (Fraction const &f2);

        Fraction &operator++ ();
        Fraction operator++ (int);
        Fraction &operator-- ();
        Fraction operator-- (int);
        Fraction &operator- ();
        Fraction &operator~ ();
        operator float();
        operator double();

        bool operator!= (Fraction const &f2);
        bool operator== (Fraction const &f2);
        bool operator! ();;
        bool operator< (Fraction const &f2);
        bool operator> (Fraction const &f2);
        bool operator<= (Fraction const &f2);
        bool operator>= (Fraction const &f2);

        bool checkFraction (istream& input);
        void math_op (Fraction f1, Fraction f2);
        void print () const;
    
    private:
        void reduce ();
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