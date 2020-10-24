#pragma once 
#include <iostream>

using namespace std;

class Matrix{
    private:
        int _nrows;
        int _ncols;
        int **_A; //matriz A
    public:
        Matrix(int nrows, int ncols); // constructor
        //Matriz(int nfilas, ncols, int **A);//constructor
                                           //con matriz
        ~Matrix();    
        void random_matrix();
        void print();
        int max();
}; 
