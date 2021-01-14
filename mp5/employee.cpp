#include "employee.h"

Employee::Employee ()
{
    d_hiredDate = myDate();
}

Employee::Employee (string name, 
                    string num, 
                    string email, 
                    myDate birthDate, 
                    long int salary, 
                    myDate hiredDate)
:
    Person (name, num, email, birthDate), 
    d_salary(salary)    
{
    d_hiredDate = hiredDate;
}

void Employee::inputData ()
{
    Person::inputData();
    cout << "Please enter the employee's salary: "; cin >> d_salary;
    cout << "Please enter the date of hire (fmt: YYYY MM DD): "; d_hiredDate.myDate::inputDate();
}

void Employee::printData ()
{
    Person::printData();
    cout << "The employee's salary is: " << d_salary << "\n";
    cout << "The employee's date of employment is: "; d_hiredDate.myDate::printDate();
    cout << "\n";
}