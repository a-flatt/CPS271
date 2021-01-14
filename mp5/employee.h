#pragma once

#include "person.h"
#include "myDate.h"

class Employee: public Person {

    long int d_salary;
    myDate d_hiredDate;

    public:
        Employee ();
        Employee (string name, 
                  string num, 
                  string email, 
                  myDate birthDate, 
                  long int salary, 
                  myDate hiredDate);

        virtual void inputData () = 0;
        virtual void printData() = 0;

};

