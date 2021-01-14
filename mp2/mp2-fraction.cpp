#include "mp2-fraction.h"

void Fraction::print ()
{
    cout << num << "/" << den << endl;
}

Fraction Fraction::add (Fraction f2)
{
    int a_num = num * f2.den + f2.num * den;
    int a_den = den * f2.den;
    Fraction fraction (a_num, a_den);
    return fraction;
}

void Fraction::add (Fraction f1, Fraction f2)
{
    num = f1.num * f2.den + f2.num * f1.den;
    den = f1.den * f2.den;
}

Fraction Fraction::subtract (Fraction f2)
{
    int a_num = num * f2.den - f2.num * den;
    int a_den = den * f2.den;
    Fraction fraction (a_num, a_den);
    return fraction;
}

void Fraction::subtract (Fraction f1, Fraction f2)
{
    num = f1.num * f2.den - f2.num * f1.den;
    den = f1.den * f2.den;
}

Fraction Fraction::multiply (Fraction f2)
{
    int a_num = num * f2.num;
    int a_den = den * f2.den;
    Fraction fraction (a_num, a_den);
    return fraction;
}

void Fraction::multiply (Fraction f1, Fraction f2)
{
    num = f1.num * f2.num;
    den = f1.den * f2.den;
}

Fraction Fraction::divide (Fraction f2)
{
    int a_num = num * f2.den;
    int a_den = den * f2.num;
    Fraction fraction (a_num, a_den);
    return fraction;
}

void Fraction::divide (Fraction f1, Fraction f2)
{
    num = f1.num * f2.den;
    den = f1.den * f2.num;
}

void Fraction::math_op (Fraction f1, Fraction f2, char oper)
{
    // Modfify f_ans to contain result of math operation on f1 and f2.
    
    switch (oper){
        case '+': add(f1, f2); break;
        case '-': subtract(f1, f2); break;
        case '*': multiply(f1, f2); break;
        case '/': divide(f1, f2); break;
    }
}

bool Fraction::checkFraction (istream& input)
{
    // Repeat entry of fraction until denominator is non-zero.
    // Then return true once denominator is valid.
    
    char notUsed;

    input >> num >> notUsed >> den;
    while (den == 0){
        cout << "Denominators must be non-zero. Please re-input: ";
        input >> num >> notUsed >> den;
    }
    return true;
}