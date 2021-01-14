#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int MAX = 20;     // Global variable for max size of student array.

struct Student {

    // Declare variables for Student.
    string studentFName;
    string studentLName;
    int testScore;
    char grade;

    // Constructor declarations, included overloaded constructor.
    Student ();
    Student (string f_name, string l_name, int t);

    // Declare member functions.
    char getGrade (int t);
    void print ();
};

Student::Student () 
{
    // Default constructor.
    
    studentFName = "No Name";
    studentLName = "No Name";
    testScore = 0;
}

Student::Student (string f_name, string l_name, int t)
{
    // Overloaded constructor:
    // Calls getGrade() to determine grade, passing testScore as an argument.
    
    studentFName = f_name;
    studentLName = l_name;
    testScore = t;
    grade = getGrade(t);
}

void Student::print ()
{
    // Print function for Student struct
    // Includes formatting to align columns.
    cout << left << setw(20) << (studentLName + ", " + studentFName);
    cout << left << setw(6) << testScore;
    cout << left << setw(5) << grade << endl;
}

char Student::getGrade (int s)
{
    // If-else statement to determine char grade based on score of type int.
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
    
    // Loop generates a new student for each line pass into the program from file.
    // Each new Student is added to the array of students called classroom, which is indexed by student number. 
    // Exception handling built into this loop to handle any invalid input data.

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
    // Non-member function which loops through array of Students and prints.
    // This function ensures that all the students in the class are printed. 
    // Member function print() determines what is printed about each student.
    
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
    // Alterate formatting and output for students with highest mark.
    // Loops through vector of student(s) with the highest mark. 
    // Can only be one 'highest mark', but many students may have achieved it. 
    // Hence, print all of these students.
    
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

    // Loop Description:

    /*  
    Initialise vector of top students with first (0th) student's mark.
    1. Loop through remainder of classroom and compare to first student's mark.
    2. If 1...20th student's mark greater than first students mark, replace first student with ith student that has the new highest mark.
    3. If i...20th student's mark equal to mark of highest student, add Student to vector.
    */
    
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