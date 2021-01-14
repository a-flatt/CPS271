#include <iostream>
using namespace std;

template <typename Data>
class Fraction {

    Data d_num, d_den;

    public:
        
        Fraction () {};
        Fraction (Data lhs, Data rhs): d_num(lhs), d_den(rhs) {}

        Fraction operator+ (Fraction const &f2) {            
            Fraction<Data> f_ans;
            f_ans.d_num = d_num * f2.d_den + f2.d_num * d_den;
            f_ans.d_den = d_den * f2.d_den;
            return f_ans;
        }

        Fraction operator- (Fraction const &f2) {
            Fraction<Data> f_ans;
            f_ans.d_num = d_num * f2.d_den - f2.d_num * d_den;
            f_ans.d_den = d_den * f2.d_den;
            return f_ans;
        }

        Fraction operator/ (Fraction const &f2) {
            Fraction<Data> f_ans;
            f_ans.d_num = d_num * f2.d_den;
            f_ans.d_den = d_den * f2.d_num;
            return f_ans;
        }

        Fraction operator* (Fraction const &f2) {
            Fraction<Data> f_ans;
            f_ans.d_num = d_num * f2.d_num;
            f_ans.d_den = d_den * f2.d_den;
            return f_ans;
        }

        void print () {
            cout << d_num << "/" << d_den << endl;
        }
};

template <>
class Fraction <char> {

    char c_num, c_den;

    public:

        Fraction () {};
        Fraction (char lhs, char rhs): c_num(lhs), c_den(rhs) {}

        Fraction operator+ (Fraction const &f2) {    
            int i_num = c_num - '0';
            int f2_c_num = f2.c_num - '0';
            int i_den = c_den - '0';
            int f2_c_den = f2.c_den - '0';

            int d_num_ans = i_num * f2_c_den + f2_c_num * i_den;
            int d_den_ans = i_den * f2_c_den;
            Fraction<char> f_ans (d_num_ans + '0', d_den_ans + '0');
            return f_ans;
        }

        Fraction operator- (Fraction const &f2) {
            int i_num = c_num - '0';
            int f2_c_num = f2.c_num - '0';
            int i_den = c_den - '0';
            int f2_c_den = f2.c_den - '0';

            int d_num_ans = i_num * f2_c_den - f2_c_num * i_den;
            int d_den_ans = i_den * f2_c_den;
            Fraction<char> f_ans (d_num_ans + '0', d_den_ans + '0');
            return f_ans;;
        }

        Fraction operator/ (Fraction const &f2) {
            int i_num = c_num - '0';
            int f2_c_num = f2.c_num - '0';
            int i_den = c_den - '0';
            int f2_c_den = f2.c_den - '0';

            int d_num_ans = i_num * f2_c_den;
            int d_den_ans = i_den * f2_c_num;
            Fraction<char> f_ans (d_num_ans + '0', d_den_ans + '0');
            return f_ans;
        }

        Fraction operator* (Fraction const &f2) {
            int i_num = c_num - '0';
            int f2_c_num = f2.c_num - '0';
            int i_den = c_den - '0';
            int f2_c_den = f2.c_den - '0';

            int d_num_ans = i_num * f2_c_num;
            int d_den_ans = i_den * f2_c_den;
            Fraction<char> f_ans (d_num_ans + '0', d_den_ans + '0');
            return f_ans;
        }

        void print () {
            cout << c_num << "/" << c_den << endl;
        }
};



