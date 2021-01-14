 #include "mp2-fraction.cpp"

bool checkOperator (istream& input, char& oper, bool& quitFile)
{
    // Return true if operator is valid, set quitFile to false to ensure program continues.
    // If invalid operator, return false, and set quitFile to false to allow another attempt.
    // If Q or q is entered, set quitFile to true to exit program.
    
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

void inputFraction (istream& input, bool& quitFile)
{
    // Create three fractions; f1 and f2 to represent inputted fractions, f_ans to represent result.
    // Check f1 and f2 are valid fractions - I.E denominator is non-zero.
    // If valid fraction and valid operator, perform math operation.
    
    char oper;
    Fraction f1, f2, f_ans;
    bool bf1, bf2, bo;

    cout << "Please enter a fraction such as 1/2: ";
    bf1 = f1.checkFraction(input);
    cout << "Please enter a second fraction: ";
    bf2 = f2.checkFraction(input);
    cout << "Please enter the mathematical operation to perform: ";
    bo = checkOperator(input, oper, quitFile);

    if (bf1 && bf2 && bo){
        f_ans.math_op(f1, f2, oper);
        cout << "The answer is: ";
        f_ans.print();
        quitFile = false;
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

