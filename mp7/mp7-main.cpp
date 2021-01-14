#include "mp7-2.h"

void inputFraction (istream& input, bool& quitFile)
{
    Fraction<char> f_ans;
    char throwawaySlash, f1_num, f1_den, f2_num, f2_den;
    bool bf1, bf2, b_ans;
    float f_f1;
    double d_f1;

    cout << "Please enter a fraction such as 1/2: ";
    cin >> f1_num >> throwawaySlash >> f1_den;
    Fraction<char> f1 {f1_num, f1_den};
    cout << "Please enter a second fraction: ";
    cin >> f2_num >> throwawaySlash >> f2_den;
    Fraction<char> f2 {f1_num, f1_den};
    
    int oper;
    cout << "Please select a math operation from the list" << endl;
    cout << "1. +" << endl;
    cout << "2. -" << endl;
    cout << "3. *" << endl;
    cout << "4. /" << endl;
    cout << "5. Quit" << endl;
    cout << "The selection is: ";
    cin >> oper;
    
    switch (oper){
        case 1: f_ans = (f1 + f2); f_ans.print(); break;
        case 2: f_ans = (f1 - f2); f_ans.print(); break;
        case 3: f_ans = (f1 * f2); f_ans.print(); break;
        case 4: f_ans = (f1 / f2); f_ans.print(); break;
        case 5: quitFile = true;
    }
}

int main ()
{
    bool quitFile = false;

    while(!quitFile){
        try{
            inputFraction(cin, quitFile);
        }
        catch (...){
            cout << "There seems to have been an error.";
            break;
        }
    }
    cout << "The program has ended, Quit has been selected or an error has been identified." << endl;
}