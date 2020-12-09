#pragma once 
#include <pthread.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>

#include <iostream>
#include <stdlib.h>     /* srand, rand */

#define HAVE_STRUCT_TIMESPEC
#define NTHREADS 4 //Warning!!! Use a square number


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

        double **get_A();
        void set_A(double **_A);
        //----------constructors and destructors
        Matrix(int nrows, int ncols);
        ~Matrix();     

        //-----------Methods-----------------------------
        void zero_matrix();
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

        //---------operators parallelized-----------------

        /*  following operator computes sum of matrices by
            dividing matrix in NTHREADS blocks and adding them
            all together*/
        //void* parallel_sum(void *args);
        
}; 

