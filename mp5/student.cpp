#include "student.h"
#include <iomanip>

Student::Student (string name, string num, string email, double gpa, myDate birthDate)
:
    Person (name, num, email, birthDate)
{
    d_gpa = gpa;
}

void Student::setGrade ()
{
    char grade;

    cout << "Please enter the students grade (F, S, J, S): "; cin >> grade;

    switch ((int)grade) {
        case FRESHMAN: d_grade = FRESHMAN; break;
        case SOPHOMORE: d_grade = SOPHOMORE; break;
        case JUNIOR: d_grade = JUNIOR; break;
        case SENIOR: d_grade = SENIOR; break;
    }
}

string Student::getGrade ()
{
    switch (d_grade) {
        case FRESHMAN: return "Freshman"; break;
        case SOPHOMORE: return "Sophomore"; break;
        case JUNIOR: return "Junior"; break;
        case SENIOR: return "Senior"; break;
    }
}

void Student::inputData ()
{
    Person::inputData();
    cout << "Please enter the student's gpa: ";
    cin >> d_gpa;
    setGrade();
}

void Student::printData ()
{
    Person::printData();
    cout << "This person's grade is: " << getGrade() << "\n";
    cout << "This person's GPA is: " << fixed << setprecision(2) << d_gpa << endl;
}

string Student::getType ()
{
    return "Student";
}


