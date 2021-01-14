#include <array>
#include <iostream>
using namespace std;

class Array {

    int *d_size;            
    int a_size;    
    int d_start, d_finish;

    public:
        Array () {};
        Array (int size);
        Array (int start, int finish);
        ~Array () {delete[] d_size;};

        int &operator[] (int index);
        int operator[] (int index) const;

        void allocateArray (int size);
        void allocateArray (int start, int finish);
        void printArray () const;
        
};