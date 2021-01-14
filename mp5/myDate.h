#pragma once

#include <iostream>
using namespace std;

class myDate {

    int d_year;
    int d_month;
    int d_day;

    public:
        myDate ();
        myDate (int year, int month, int day);

        myDate &operator= (const myDate &md);

        void inputDate ();
        void printDate();
};




