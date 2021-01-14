#include <iostream>
#include <sstream>

using namespace std;

class Fraction {

    int d_num, d_den;

    public:
        Fraction () {};
        Fraction (int num, int den);

        Fraction &operator= (Fraction const &f2);
        
        bool operator> (Fraction const &f2) const;
        bool operator< (Fraction const &f2) const;
        bool operator== (Fraction const &f2);

        operator double() const;
        
        void reduce ();
        void print () const;

        friend istream &operator>> (istream &is, Fraction &f);

};

