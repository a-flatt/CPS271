#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int MAX = 20;     // Global variable for max size of student array.

struct Student {

    string studentFName;
    string studentLName;
    int testScore;
    char grade;

    Student ();
    Student (string f_name, string l_name, int t);

    char getGrade (int t);
    void print ();
};

Student::Student () 
{    
    studentFName = "No Name";
    studentLName = "No Name";
    testScore = 0;
}

Student::Student (string f_name, string l_name, int t)
{
    studentFName = f_name;
    studentLName = l_name;
    testScore = t;
    grade = getGrade(t);
}

void Student::print ()
{
    cout << left << setw(20) << (studentLName + ", " + studentFName);
    cout << left << setw(6) << testScore;
    cout << left << setw(5) << grade << endl;
}

char Student::getGrade (int s)
{
    if (s < 60)
        return 'E';
    else if (s <= 69)
        return 'D';
    else if (s <= 79)
        return 'C'; 
    else if (s <= 89)
        return 'B';
    else
        return 'A';    
}

void createStudents(ifstream& if_Stream, Student arr[MAX])
{
    string f_name, l_name;
    int score;
    int stud_num = 0;
    
    while (!if_Stream.eof()){
        try {
            if_Stream >> f_name >> l_name >> score;
            Student student (f_name, l_name, score);
            arr[stud_num] = student;
            stud_num++;
        }
        catch (...) {
            cout << "Invalid data in the input file. " << endl;
            break;
        }
    }
    if_Stream.close();
}

void printStudents(Student arr[MAX])
{
    cout << left << setw(20) << "STUDENT NAME";
    cout << left << setw(6) << "SCORE";
    cout << left << setw(5) << "GRADE" << endl;
    
    for (int i = 0; i < MAX; i++){
        arr[i].print();
    }
    cout << endl;
}

void printHighestMark (vector<Student>& vec)
{
    cout << "The student(s) with the highest mark are: " << endl;
    for (int i = 0; i < vec.size(); i++){
        cout << vec[i].studentFName << " " << vec[i].studentLName << " with a mark of " << vec[i].testScore << " and a grade of " << vec[i].grade << "." << endl;
    }
}

void findHighestMark (Student arr[MAX])
{
    vector<Student> topStudents;
    int count = 0;
    int topMark = arr[0].testScore;

    topStudents.push_back(arr[0]);
    for (int i = 1; i < MAX; i++){
        if (arr[i].testScore > topMark){
            topStudents[0] = arr[i];
            topMark = arr[i].testScore;
        }
        else if (arr[i].testScore == topMark){
            topStudents.push_back(arr[i]);
        }
    }
    printHighestMark(topStudents);
}

int main ()
{
    Student classroom[MAX];
    ifstream if_Stream ("students.txt");
    
    createStudents(if_Stream, classroom);
    printStudents(classroom);
    findHighestMark(classroom);
}