#include "person.h"

Person::Person ()
{
    myDate d_birthDate = myDate();
}

Person::Person (string name, string num, string email, myDate birthDate)
:
    d_name(name),
    d_num(num),
    d_email(email)
{
    d_bDay = birthDate;
}

void Person::inputData ()
{
    cout << "Please enter the Name: "; cin >> d_name;
    cout << "Please enter the Phone Number: "; cin >> d_num;
    cout << "Please enter the Birth Date (fmt: YYYY MM DD): "; d_bDay.myDate::inputDate();
    cout << "Please enter an Email Address: "; cin >> d_email;
}

void Person::printData()
{
    cout << "This person's name is: " << d_name << "\n";
    cout << "This person's number is: " << d_num << "\n";
    cout << "This person's email is: " << d_email << "\n";
    cout << "This person's birthday is: "; d_bDay.myDate::printDate();
    cout << "\n";
}