#pragma once 
#include <iostream>
#include <stdlib.h>     /* srand, rand */

using namespace std;

class Matrix{
    private:
        //------------Attributtes--------------------------
        int _nrows;
        int _ncols;
        double **_A; //matrix A
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
        Matrix * traspose();

        //inverse matrix returns NULL if it's not possible
        //to carry out inverse calculation
        Matrix * inverse();


        //---------operators overloading-----------------

        /*  following operator can be used as
            Matrix *m3 = *m1 + *m2; 
            whenever m1, m2 are dinamic*/
        Matrix* operator + (Matrix const &M); // sum of matrices

        /*  following operator can be used as
            Matrix *m3 = *m1 - *m2; 
            whenever m1, m2 are dinamic */
        Matrix* operator - (Matrix const &M); // subtraction of matrices
        
        /*  following operator can be used as
            Matrix *m3 = (*m1) * (*m2); 
            whenever m1, m2 are dinamic */
        Matrix* operator * (Matrix const &M); // subtraction of matrices
        
        
}; 
