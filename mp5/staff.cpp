#include "staff.h"

Staff::Staff ()
{
    d_title = "";
}

Staff::Staff (string name, 
              string num, 
              string email, 
              myDate birthDate, 
              long int salary, 
              myDate hiredDate, 
              string title)
:
    Employee(name, num, email, birthDate, salary, hiredDate),
    d_title(title)
{}

void Staff::inputData ()
{
    Employee::inputData();
    cout << "Please enter the staff member's title: "; cin >> d_title;
}

void Staff::printData ()
{
    Employee::printData();
    cout << "This staff member's title is: " << d_title << "\n";
}

string Staff::getType ()
{
    return "Staff";
}
