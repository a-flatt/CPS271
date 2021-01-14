#include "faculty.h"

Faculty::Faculty ()
{
    d_roomID = 0;
    d_tenure = false;
}

Faculty::Faculty (string name, 
                  string num, 
                  string email, 
                  myDate birthDate, 
                  long int salary, 
                  myDate hiredDate,
                  int roomID,
                  bool tenure,
                  vector <myDate> officeHrs)
:
    Employee(name, num, email, birthDate, salary, hiredDate),
    d_roomID(roomID),
    d_tenure(tenure)
{
    d_officeHrs = officeHrs;
}

void Faculty::inputData ()
{
    bool quit = false;
    int i_bool;
    
    Employee::inputData();
    cout << "Please enter the room number: "; cin >> d_roomID;
    cout << "Please enter whether the tenure is (true) or (false): "; cin >> boolalpha >> d_tenure;
    
    while (!quit){
        myDate availDate;
        cout << "Please enter available dates: ";
        availDate.myDate::inputDate();
        d_officeHrs.push_back(availDate);
        cout << "Do you want to enter another available date (0 = Y, 1 = N)?: "; cin >> i_bool;
        quit = bool(i_bool);
    }
    
}

void Faculty::printData ()
{
    Employee::printData();
    cout << "The room number is: " << d_roomID << "\n";
    cout << "The tenure status is: " << boolalpha << d_tenure << "\n";
    cout << "The available dates are: ";
    for (int i = 0; i < d_officeHrs.size(); i++){
        d_officeHrs[i].printDate();
        cout << ", ";
    }
}

string Faculty::getType ()
{
    return "Faculty";
}