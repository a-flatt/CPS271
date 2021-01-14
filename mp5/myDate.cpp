#include "myDate.h"

myDate::myDate ()
{
    d_year = 0;
    d_month = 0;
    d_day = 0;
}

myDate::myDate (int year, int month, int day)
{
    d_year = year;
    d_month = month;
    d_day = day;
}

void myDate::inputDate ()
{
    // cout << "Please enter the date in the following format YYYY MM DD: ";
    cin >> d_year >> d_month >> d_day;
}

void myDate::printDate()
{
    cout << d_year << "/" << d_month << "/" << d_day;
}

myDate &myDate::operator= (const myDate &md)
{
	d_year = md.d_year;
	d_month = md.d_month;
	d_day = md.d_day;
	return *this;
}
