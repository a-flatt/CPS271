#include "fraction.h"
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>

bool equality (Fraction a, Fraction b)
{
    return a == b;
} 

vector<Fraction> merge (vector<Fraction> vec, list<Fraction> list)
{
    vector<Fraction> temp = vec;
    temp.insert(temp.end(), list.begin(), list.end());
    temp.erase(unique(temp.begin(), temp.end(), equality), temp.end());
    sort(temp.begin(), temp.end());
    return temp;
}

bool lessThan (Fraction a, Fraction b)
{
    return a < b;
}

template <typename Sequence>
void selectionSort (Sequence &seq, int size)
{
    
    for (int x = 0; x < size; x++){
		for (int y = x + 1; y < size; y++){
			if (seq[x] > seq[y]){
				Fraction t = seq[x];
				seq[x] = seq[y];
				seq[y] = t;
			}
		}
	}
}

int main ()
{
    // 'Quasi-global' local variable declaration:
    string i_string;
    
    // Read in data file:
    vector<Fraction> fraction_vector;
    ifstream vector_file ("FractsToVector.txt");

    while(getline(vector_file, i_string)){
        Fraction f;
        istringstream iss(i_string);
        iss >> f;
        fraction_vector.push_back(f);
    }
    selectionSort(fraction_vector, fraction_vector.size());
    
    cout << "Fraction Vector: ";
    cout << "[";
    for (int i = 0; i < fraction_vector.size(); i++){
        if (fraction_vector[i] == fraction_vector.back()){
            fraction_vector[i].print();
            break;
        }
        fraction_vector[i].print(); cout << ",";
    }
    cout << "]" << "\n";

    list<Fraction> fraction_list;
    ifstream list_file ("FractsToList.txt");

    while(getline(list_file, i_string)){
        Fraction f;
        istringstream iss(i_string);
        iss >> f;
        fraction_list.push_back(f);
    }
    fraction_list.sort(lessThan);

    cout << "Fraction List: ";
    cout << "[";
    for (auto const& i : fraction_list){
        if(i == fraction_list.back()){
            i.print();
            break;
        }
        i.print(); cout << ",";
    }
    cout << "]";
    
    cout << "\n";
    
    vector<Fraction> merged_fractions = merge(fraction_vector, fraction_list);
    cout << "Merged Vector: ";
    cout << "[";
    for (int i = 0; i < merged_fractions.size(); i++){
        if (merged_fractions[i] == merged_fractions.back()){
            merged_fractions[i].print();
            break;
        }
        merged_fractions[i].print(); cout << ",";
    }
    cout << "]" << "\n";
    
}