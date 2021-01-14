#pragma once

#include "person.h"

enum Grade  {FRESHMAN = (int)'F',
             SOPHOMORE = (int)'S',
             JUNIOR = (int)'J',
             SENIOR = (int)'R'};

class Student: public Person {

    double d_gpa;
    Grade d_grade;

    public:
        Student () {};
        Student (string name, string num, string email, double gpa, myDate birthDate);
        
        void setGrade ();
        string getGrade ();
        void inputData ();
        void printData ();
        string getType ();
};

