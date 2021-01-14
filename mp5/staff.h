#pragma once

#include "employee.h"

class Staff: public Employee {
    
    string d_title;

    public:
        Staff ();
        Staff (string name, 
               string num, 
               string email, 
               myDate birthDate, 
               long int salary, 
               myDate hiredDate, 
               string title);

        string getType ();
        void inputData ();
        void printData (); 
};