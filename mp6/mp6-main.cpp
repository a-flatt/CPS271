#include "dyn_array.h"

int main ()
{
    Array list(5);
    Array myList(2, 13);
    Array yourList(-5, 9);
    
    list.printArray();
    myList.printArray();
    yourList.printArray();
    cout << list[1] << "\n";
    cout << myList[6] << "\n";
    cout << yourList[-2] << "\n";
    cout << list[-3] << "\n";
}