#include "mp3-fraction.cpp"

/*
bool checkOperator (istream& input, char& oper, bool& quitFile)
{

    input >> oper;
    if (oper == 'Q' || oper == 'q'){
        quitFile = true;
        return false;
    }
    else if (oper == '+' || oper == '-' || oper == '*' || oper == '/'){
        quitFile = false;
        return true;
    }
    else{
        cout << "This is an invalid operator. Please try again." << endl;
        quitFile = false;
        return false;
    }
}
*/

void inputFraction (istream& input, bool& quitFile)
{
    Fraction f1, f2, f_ans;
    bool bf1, bf2, b_ans;
    float f_f1;
    double d_f1;

    cout << "Please enter a fraction such as 1/2: ";
    bf1 = f1.checkFraction(input);
    cout << "Please enter a second fraction: ";
    bf2 = f2.checkFraction(input);
    
    int oper;
    cout << "Please select a math operation from the list" << endl;
    cout << "1. +" << endl;
    cout << "2. -" << endl;
    cout << "3. *" << endl;
    cout << "4. /" << endl;
    cout << "5. +=" << endl;
    cout << "6. -=" << endl;
    cout << "7. *-" << endl;
    cout << "8. /=" << endl;
    cout << "9. -" << endl;
    cout << "10 !" << endl;
    cout << "11. ++ (prefix)" << endl;
    cout << "12. ++ (postfix)" << endl;
    cout << "13. -- (prefix)" << endl;
    cout << "14. -- (postfix)" << endl;
    cout << "15. <" << endl;
    cout << "16. >" << endl;
    cout << "17. <=" << endl;
    cout << "18. >=" << endl;
    cout << "19. ==" << endl;
    cout << "20. !=" << endl;
    cout << "21. !" << endl;
    cout << "22. (float) on the first fraction." << endl;
    cout << "23. (double) on the first fraction" << endl;
    cout << "24. Quit" << endl;
    cout << "The selection is: ";
    cin >> oper;
    
    switch (oper){
        case 1: f_ans = (f1 + f2); f_ans.print(); break;
        case 2: f_ans = (f1 - f2); f_ans.print(); break;
        case 3: f_ans = (f1 * f2); f_ans.print(); break;
        case 4: f_ans = (f1 / f2); f_ans.print(); break;
        case 5: f_ans = (f1 += f2); f_ans.print(); break;
        case 6: f_ans = (f1 -= f2); f_ans.print(); break;
        case 7: f_ans = (f1 *= f2); f_ans.print(); break;
        case 8: f_ans = (f1 /= f2); f_ans.print(); break;
        case 9: f_ans = (f1 = -f2); f_ans.print(); break;
        case 10: f_ans = (f1 = !f2); f_ans.print(); break;
        case 11: f_ans = ++f1; f_ans.print(); break;
        case 12: f_ans = f1++; f_ans.print(); break;
        case 13: f_ans = --f1; f_ans.print(); break;
        case 14: f_ans = f1++; f_ans.print(); break;
        case 15: f1 < f2 ? cout << "The answer is True\n" : cout << "The answer is False\n"; break;
        case 16: f1 > f2 ? cout << "The answer is True\n" : cout << "The answer is False\n"; break;
        case 17: f1 <= f2 ? cout << "The answer is True\n" : cout << "The answer is False\n"; break;
        case 18: f1 >= f2 ? cout << "The answer is True\n" : cout << "The answer is False\n"; break;
        case 19: f1 == f2 ? cout << "The answer is True\n" : cout << "The answer is False\n"; break;
        case 20: f1 != f2 ? cout << "The answer is True\n" : cout << "The answer is False\n"; break;
        case 21: !f2 ? cout << "The answer is True\n" : cout << "The answer is False\n"; break;
        case 22: f_f1 = (float) f1; cout << "The float value is: " << f_f1 << endl; break;
        case 23: d_f1 = (double) f1; cout << "The double value is: " << d_f1 << endl; break;
        case 24: quitFile = true;
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
    cout << "The program has ended, q/Q has been entered or an error has been identified." << endl;
}