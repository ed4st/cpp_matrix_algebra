/*
*    Author: Edgar Baquero
*
*    Matrix algebra: This code is made with final purpose of 
*                    compute basic matrix algebra via cpp
*                    implementation.
*
*    If you are on a Linux OS based system, you can compile and run via
*    following command in terminal:
*    >> g++ *.cpp -o exe && ./exe
*
*/

#include "Matrix.h"
#include "Matrix.cpp"
#include <cmath>
#include <iostream>
#include <pthread.h>


int main(){
    
    int nrows, ncols;
    nrows = 2;
    ncols = 2;
    //creating matrices
    Matrix *M1 = new Matrix(nrows,ncols);
    Matrix *M2 = new Matrix(nrows,ncols);
    

    //filling matrix randomly
    //srand(time(NULL));
    M1->random_matrix();
    M2->random_matrix();


    M1->print();
    /*M2->print();
    cout <<"suma:\n";
    (*M1 + *M2)->print();    
    parallel_sum(M1,M2)->print();
    cout <<"Resta:\n";
    (*M1 - *M2)->print();    
    parallel_sub(M1,M2)->print();
    cout <<"Multiplicacion:\n";
    (*M1 * *M2)->print();    
    parallel_mul(M1,M2)->print();*/

    M1->inverse()->print();
    parallel_inv(M1)->print();

    delete M1, M2;



    /*
    // Menu
    int option = 0;
    do
    {
        cout << "Enter one of the following options:\n";

        cout << "   1. Sum two matrices.\n";
        cout << "   2. Subtract two matrices.\n";
        cout << "   3. Product of two matrices.\n";
        cout << "   4. Traspose a matrix.\n";
        cout << "   5. Inverse of a matrix.\n";
        cout << "   6. Exit.\n";
        cout << ">> ";
        cin >> option;
        cout << endl;
        switch (option)
        {
        case 1:
        {
            int m1, n1, m2, n2;
            cout << "Enter the number of rows of matrix 1: ";
            cin >> m1;
            cout << endl;
            cout << "Enter the number of columns of matrix 1: ";
            cin >> n1;
            cout << endl;
            cout << "Enter the number of rows of matrix 2: ";
            cin >> m2;
            cout << endl;
            cout << "Enter the number of columns of matrix 2: ";
            cin >> n2;
            cout << endl;

            //creating matrices
            Matrix *M1 = new Matrix(m1,n1);
            Matrix *M2 = new Matrix(m2,n2);
            
            //filling matrix randomly
            srand(time(NULL));
            M1->random_matrix();
            M2->random_matrix();

            cout << "*********Following matrices are randomly generated*********\n";
            cout << "---------Matrix 1---------\n";
            M1->print();
            cout << "---------Matrix 2---------\n";
            M2->print();
            cout << "---------Sum---------\n";
            (*M1 + *M2)->print();

            delete M1,M2;
            break;
        }
        case 2:
        {
            int m1, n1, m2, n2;
            cout << "Enter the number of rows of matrix 1: ";
            cin >> m1;
            cout << endl;
            cout << "Enter the number of columns of matrix 1: ";
            cin >> n1;
            cout << endl;
            cout << "Enter the number of rows of matrix 2: ";
            cin >> m2;
            cout << endl;
            cout << "Enter the number of columns of matrix 2: ";
            cin >> n2;
            cout << endl;

            //creating matrices
            Matrix *M1 = new Matrix(m1,n1);
            Matrix *M2 = new Matrix(m2,n2);
            
            //filling matrix randomly
            srand(time(NULL));
            M1->random_matrix();
            M2->random_matrix();

            cout << "*********Following matrices are randomly generated*********\n";
            cout << "---------Matrix 1---------\n";
            M1->print();
            cout << "---------Matrix 2---------\n";
            M2->print();
            cout << "---------Subtraction---------\n";
            (*M1 - *M2)->print();

            delete M1,M2;
            break;
        }
        case 3:
        {
            int m1, n1, m2, n2;
            cout << "Enter the number of rows of matrix 1: ";
            cin >> m1;
            cout << endl;
            cout << "Enter the number of columns of matrix 1: ";
            cin >> n1;
            cout << endl;
            cout << "Enter the number of rows of matrix 2: ";
            cin >> m2;
            cout << endl;
            cout << "Enter the number of columns of matrix 2: ";
            cin >> n2;
            cout << endl;

            //creating matrices
            Matrix *M1 = new Matrix(m1,n1);
            Matrix *M2 = new Matrix(m2,n2);
            
            //filling matrix randomly
            srand(time(NULL));
            M1->random_matrix();
            M2->random_matrix();

            cout << "*********Following matrices are randomly generated*********\n";
            cout << "---------Matrix 1---------\n";
            M1->print();
            cout << "---------Matrix 2---------\n";
            M2->print();
            cout << "---------Multiplication---------\n";
            ((*M1) * (*M2))->print();
            

            delete M1,M2;
            break;
        }
        case 4:
        {
            int m1, n1;
            cout << "Enter the number of rows of matrix: ";
            cin >> m1;
            cout << endl;
            cout << "Enter the number of columns of matrix: ";
            cin >> n1;
            cout << endl;

            //creating matrix
            Matrix *M = new Matrix(m1,n1);
            
            //filling matrix randomly
            srand(time(NULL));
            M->random_matrix();

            cout << "*********Following matrix is randomly generated*********\n";
            cout << "---------Matrix---------\n";
            M->print();
            cout << "---------Traspose---------\n";
            M->traspose()->print();
            
            delete M;
            break;
        }
        case 5:
        {
            int m1, n1;
            cout << "Enter the number of rows of matrix: ";
            cin >> m1;
            cout << endl;
            cout << "Enter the number of columns of matrix: ";
            cin >> n1;
            cout << endl;

            //creating matrix
            Matrix *M = new Matrix(m1,n1);
            
            //filling matrix randomly
            srand(time(NULL));
            M->random_matrix();

            cout << "*********Following matrix is randomly generated*********\n";
            cout << "---------Matrix---------\n";
            M->print();
            cout << "---------Inverse---------\n";
            if(M->inverse() != NULL){
                M->inverse()->print();
            }else{
                cout << "Inverse cannot be computed :c\n\n";
            }        

            delete M;
            break;
        }
        case 6:
        {
            cout << "Bye c:\n";
            break;
        }
        default:
        {
            option = 6;
            cout<<"An error occurred. Key not detected, try again.\n";
            break;
        }
        }
    } while (option != 6);
    
    */    

    return 0;
}
