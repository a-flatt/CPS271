#include <iostream>
#include <cmath>
using namespace std;

double power (double n, double p = 2)
{
   return pow(n, p);
}

long int hms_to_sec (int hours, int mins, int secs)
{
    long int total_secs = hours * 3600 + mins * 60 + secs;
    return total_secs;
}

void swap (int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp; 
}

int main ()
{
    // -- Power Function: --
    int n;
    int p;
    cout << "Power Function:" << endl;
    cout << "Please enter a base value: ";
    cin >> n;
    cout << "Please enter a power value: ";
    cin >> p;
    cout << "The result is: " << power(n, p) << endl; 
    cout << endl;
    
    // -- Hours, Minutes, Seconds Function: --
    int hours = 0;
    int mins;
    int secs;

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
