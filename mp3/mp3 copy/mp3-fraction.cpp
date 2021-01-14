#include "mp3-fraction.h"

// BINARY FUNCTIONS

Fraction &Fraction::operator= (Fraction const &f2)
{
    this->num = f2.num;
    this->den = f2.den;
    return *this;
}

Fraction operator+ (Fraction const &f1, Fraction const &f2)
{
    Fraction f_ans;
    f_ans.add(f1, f2);
    return f_ans;
}

Fraction operator- (Fraction const &f1, Fraction const &f2)
{
    Fraction f_ans;
    f_ans.subtract(f1, f2);
    return f_ans;
}

Fraction operator* (Fraction const &f1, Fraction const &f2)
{
    Fraction f_ans;
    f_ans.multiply(f1, f2);
    return f_ans;
}

Fraction operator/ (Fraction const &f1, Fraction const &f2)
{
    Fraction f_ans;
    f_ans.divide(f1, f2);
    return f_ans;
}

Fraction &Fraction::operator+= (Fraction const &f2)
{
    Fraction temp (*this);
    *this = temp.add(f2);
    return *this;
}

Fraction &Fraction::operator-= (Fraction const &f2)
{
    Fraction temp (*this);
    *this = temp.subtract(f2);
    return *this;
}

Fraction &Fraction::operator*= (Fraction const &f2)
{
    Fraction temp (*this);
    *this = temp.multiply(f2);
    return *this;
}

Fraction &Fraction::operator/= (Fraction const &f2)
{
    Fraction temp (*this);
    *this = temp.divide(f2);
    return *this;
}

// UNARY FUNCTIONS

Fraction &Fraction::operator++ ()
{
    Fraction temp (*this);
    Fraction const var (1, 1);
    *this = temp.add(var);
    return *this;
}

Fraction Fraction::operator++ (int)
{
    Fraction temp (*this);
    Fraction const var (1, 1);
    *this = temp.add(var);
    return temp;
}

Fraction &Fraction::operator-- ()
{
    Fraction temp (*this);
    Fraction const var (1, 1);
    *this = temp.subtract(var);
    return *this;
}

Fraction Fraction::operator-- (int)
{
    Fraction temp (*this);
    Fraction const var (1, 1);
    *this = temp.subtract(var);
    return temp;
}

Fraction &Fraction::operator- ()
{
    Fraction temp (*this);
    Fraction const var (-1, 1);
    *this = temp.multiply(var);
    return *this;
}

Fraction &Fraction::operator~ ()
{
    Fraction temp (this->den, this->num);
    *this = temp;
    return *this;
}

// BOOL FUNCTIONS

bool Fraction::operator!= (Fraction const &f2)
{
    return (this->num != f2.num && this->den != f2.den);
}

bool Fraction::operator< (Fraction const &f2) 
{
    return (float) this->num / this->den < (float) f2.num / f2.den;
}

bool Fraction::operator> (Fraction const &f2)
{
    return (float) this->num / this->den > (float) f2.num / f2.den;
}

bool Fraction::operator<= (Fraction const &f2)
{
    return (float) this->num / this->den <= (float) f2.num / f2.den;
}

bool Fraction::operator>= (Fraction const &f2)
{
    return (float) this->num / this->den >= (float) f2.num / f2.den;
}

bool Fraction::operator== (Fraction const &f2)
{
    return (this->num == f2.num && this->den == f2.den);
}

bool Fraction::operator! () const
{
    return num == 0;
}

// CASTING FUNCTIONS

Fraction::operator float()
{
    return (float) num / (float) den;
}

Fraction::operator double()
{
    return (double) num / (double) den;
}

// INSERTION AND EXTRACTION

ostream &operator<< (ostream &os, Fraction const &f)
{
	os << f.num << "/" << f.den;
	return os;
}

istream &operator>> (istream &is, Fraction &f)
{
	char notUsed;

    is >> f.num >> notUsed >> f.den;
	return is;
}

// ASSIGNMENT TWO FUNCTIONS 

void Fraction::print () const
{
    cout << num << "/" << den << endl;
}

Fraction Fraction::add (Fraction f2)
{
    int a_num = num * f2.den + f2.num * den;
    int a_den = den * f2.den;
    Fraction fraction (a_num, a_den);
    fraction.reduce();
    return fraction;
}

void Fraction::add (Fraction f1, Fraction f2)
{
    num = f1.num * f2.den + f2.num * f1.den;
    den = f1.den * f2.den;
    reduce();
}

Fraction Fraction::subtract (Fraction f2)
{
    int a_num = num * f2.den - f2.num * den;
    int a_den = den * f2.den;
    Fraction fraction (a_num, a_den);
    fraction.reduce();
    return fraction;
}

void Fraction::subtract (Fraction f1, Fraction f2)
{
    num = f1.num * f2.den - f2.num * f1.den;
    den = f1.den * f2.den;
    reduce();
}

Fraction Fraction::multiply (Fraction f2)
{
    int a_num = num * f2.num;
    int a_den = den * f2.den;
    Fraction fraction (a_num, a_den);
    fraction.reduce();
    return fraction;
}

void Fraction::multiply (Fraction f1, Fraction f2)
{
    num = f1.num * f2.num;
    den = f1.den * f2.den;
    reduce();
}

Fraction Fraction::divide (Fraction f2)
{
    int a_num = num * f2.den;
    int a_den = den * f2.num;
    Fraction fraction (a_num, a_den);
    fraction.reduce();
    return fraction;
}

void Fraction::divide (Fraction f1, Fraction f2)
{
    num = f1.num * f2.den;
    den = f1.den * f2.num;
    reduce();
}

bool Fraction::checkFraction (istream& input)
{
    char notUsed;

    input >> num >> notUsed >> den;
    while (den == 0){
        cout << "Denominators must be non-zero. Please re-input: ";
        input >> num >> notUsed >> den;
    }
    return true;
}

void Fraction::reduce ()
{
    for (int i = (num * den); i > 1; i--){
        if ((num % i == 0) && (den % i == 0)){
            num /= i;
            den /= i;
        }
    }
}