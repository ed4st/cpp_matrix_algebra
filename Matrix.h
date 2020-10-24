#pragma once 
#include <iostream>

using namespace std;

class Matrix{
    private:
        int _nrows;
        int _ncols;
        int **_A; //matrix A
    public:
        //-----------getters and setters-----------------
        int get_nrows();
        void set_nrows(int nrows);
        
        int get_ncols();
        void set_ncols(int ncols);
        
        Matrix(int nrows, int ncols); // constructor
        ~Matrix();     
        void random_matrix();
        void print();
        int max();
}; 
