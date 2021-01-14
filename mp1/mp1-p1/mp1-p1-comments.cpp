// Adam Platt's MP1 Submission
// Student No. 00700113
// Subject CPS271
// Class No. 96607

#include <iostream>
#include <cmath>
using namespace std;

double power (double n, double p = 2)
{
    // Power Function:
    // Relatively self explantory; n is multiplied by p and returned.
   
   return pow(n, p);
}

long int hms_to_sec (int hours, int mins, int secs)
{
    // Convert hours and minutes to seconds then add sum to seconds.
    // Return result.
    
    long int total_secs = hours * 3600 + mins * 60 + secs;
    return total_secs;
}

void swap (int& x, int& y)
{
    // Take existing x and y values and swap; reference values passed.
    // Value of variables in the calling program changed.
    
    int temp = x;
    x = y;
    y = temp; 
}

int main ()
{
    // -- Power Function: --
    // Declare variables for base and power 
    int n;
    int p;
    // Read in values from console for base and power.
    cout << "Power Function:" << endl;
    cout << "Please enter a base value: ";
    cin >> n;
    cout << "Please enter a power value: ";
    cin >> p;
    // Output results of power() function.
    cout << "The result is: " << power(n, p) << endl; 
    cout << endl;
    
    // -- Hours, Minutes, Seconds Function: --
    int hours = 0;
    int mins;
    int secs;

    // Take input of hours, minutes and seconds then return value in seconds.
    // If hours = -1, then break out of loop.
    cout << "Hours, Minutes and Seconds Function: " << endl;
    while (hours >= 0){
        cout << "Please enter a number of hours: ";
        cin >> hours;
        if (hours == -1) break;
        cout << "Please enter the number of minutes: ";
        cin >> mins;
        cout << "Please enter the number of seconds: ";
        cin >> secs;
        cout << "The length of time in seconds is: " << hms_to_sec(hours, mins, secs) << endl;
    }

    // Swap Function:
    // Take x and y values and pass as reference parameters to swap function.
    // Return swapped x and y values.
    int x;
    int y;
    cout << endl;
    cout << "Swap Function: " << endl;
    cout << "Please enter a value for x: ";
    cin >> x;
    cout << "Please enter a value for y: ";
    cin >> y;
    cout << "The original values of x and y are " << x << " and " << y << "." << endl;
    swap(x, y);
    cout << "The swapped values of x and y are " << x << " and " << y << "." << endl;
}
