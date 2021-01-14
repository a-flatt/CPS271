#pragma once

#include "employee.h"
#include <vector>

class Faculty: public Employee {
    
    int d_roomID;
    bool d_tenure;
    vector <myDate> d_officeHrs;

    public:
        Faculty ();
        Faculty (string name, 
                 string num, 
                 string email, 
                 myDate birthDate, 
                 long int salary, 
                 myDate hiredDate,
                 int roomID,
                 bool tenure,
                 vector <myDate> officeHrs);

        string getType ();
        void inputData ();
        void printData ();

};