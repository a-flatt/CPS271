#include "person.h"
#include "student.h"
#include "employee.h"
#include "staff.h"
#include "faculty.h"

using namespace std;

enum choice {student = (int)'S', 
             staff = (int)'T', 
             faculty = (int)'F', 
             print = (int)'P', 
             quit = (int)'Q'};

int main ()
{
    bool cont = true;
    char select;

    vector <Person *> people;
    Student *t;
    Staff *s;
    Faculty *f;
    
    while (cont) {
        cout << "Please select the type of person you would like to create." << "\n";
        cout << "(S)tudent, S(T)aff, (F)aculty, (P)rint, (Q)uit: "; cin >> select;
        
        switch(select) {
            case student:
                t = new Student();
                t->inputData();
                people.push_back(t);
                break;
            case staff:
                s = new Staff();
                s->inputData();
                people.push_back(s);
                break;
            case faculty:
                f = new Faculty();
                f->inputData();
                people.push_back(f);
                break;
            case print:
                cout << "\n";
                for (int i = 0; i < people.size(); i++){
                    cout << people[i]->getType() << "\n";
                    people[i]->printData();
                    cout << "\n" << "\n";
                }
                break;
            case quit: cont = false; 
        }
    }
}