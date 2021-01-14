#include "fraction.h"

istream &operator>> (istream &is, Fraction &f)
{
    is >> f.d_num >> f.d_den;
    f.reduce();
	return is;
}

void Fraction::reduce ()
{
    for (int i = (d_num * d_den); i > 1; i--){
        if ((d_num % i == 0) && (d_den % i == 0)){
            d_num /= i;
            d_den /= i;
        }
    }
}

void Fraction::print () const
{
    cout << d_num << "/" << d_den;
}

bool Fraction::operator< (Fraction const &f2) const
{
    return (double) this->d_num / this->d_den < (double) f2.d_num / f2.d_den;
}

bool Fraction::operator> (Fraction const &f2) const
{
    return (double) this->d_num / this->d_den > (double) f2.d_num / f2.d_den;
}

bool Fraction::operator== (Fraction const &f2)
{
    return (this->d_num == f2.d_num && this->d_den == f2.d_den);
}

/*
bool Fraction::operator < (const Fraction &f) const
{
	long n1 = d_num * f.d_den;
	long n2 = f.d_num * d_den;
	return n1 < n2;
}

bool Fraction::operator > (const Fraction &f) const
{
	long n1 = d_num * f.d_den;
	long n2 = f.d_num * d_den;
	return n1 > n2;
}
*/

Fraction &Fraction::operator= (Fraction const &f2)
{
    this->d_num = f2.d_num;
    this->d_den = f2.d_den;
    return *this;
}

Fraction::operator double() const
{
    return (double) d_num / (double) d_den;
}