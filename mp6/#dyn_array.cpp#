#include "dyn_array.h"

int &Array::operator[] (int index)
{
    if (index < d_start || index > d_finish){
        cout << "Error: index is out of bounds. Aborting program." << endl;
        abort();
    }
    return d_size[index - d_start];
}

int Array::operator[] (int index) const
{
    if (index < d_start || index > d_finish){
        cout << "Error: index is out of bounds. Aborting program." << endl;
        abort();
    }
    return d_size[index - d_start];
}

Array::Array (int size)
:
    d_start(0),
    d_size(new int [size]),
    a_size(size)
{
    allocateArray(size);
}

Array::Array (int start, int finish)
:
    d_start(start),
    d_finish(finish),
    d_size(new int [finish - start]),
    a_size(finish - start)
{
    allocateArray(start, finish);
}

void Array::allocateArray (int size)
{
    for (int i = 0; i < size; i++){
        d_size[i] = i;
    }
}

void Array::allocateArray (int start, int finish)
{
    int idx = 0;
    for (int i = start; i < finish; i++){
        d_size[idx] = i;
        idx++;
    }
}

void Array::printArray () const
{
    for (int i = 0; i < a_size; i++){
        cout << d_size[i] << " ";
    }
    cout << "\n";
}