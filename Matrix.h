#pragma once 
#include <iostream>

using namespace std;

class Matrix{
    private:
        //------------Attributtes--------------------------
        int _nrows;
        int _ncols;
        int **_A; //matrix A
    public:
        //-----------getters and setters-----------------
        int get_nrows();
        void set_nrows(int nrows);
        
        int get_ncols();
        void set_ncols(int ncols);
        //----------constructors and destructors
        Matrix(int nrows, int ncols);
        ~Matrix();     
        //-----------Methods-----------------------------
        void random_matrix();
        void print();
        int max();
        //---------operators overloading-----------------
        // folowwing operator can be used as
        // Matrix *m3 = *m1 + *m2; 
        //whenever m1, m2 are dinamic
        Matrix* operator + (Matrix const &M); // sum of matrices
        
        
}; 
