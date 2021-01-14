#pragma once

#include "myDate.h"
#include <iostream>
using namespace std;

class Person {

    string d_name;
    string d_num;
    string d_email;
    myDate d_bDay;
    
    public:
        Person ();
        Person (string name, string num, string email, myDate birthDate);
        virtual void inputData () = 0;
        virtual void printData () = 0;
        virtual string getType() = 0;
};

