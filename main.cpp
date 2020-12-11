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
#include <fstream> //save the time execution of each program
#include <chrono> //measures the time of a function
using namespace std::chrono;
//following functions meausres the execution time of algorithms
//developed here, by saving a csv file whose entries contain the
//comparative times in sequential-paralllel per size record
void timeit_sum();
void timeit_sub(); 
void timeit_mul();
void timeit_inv();


int main(){
    //Measuring execution time
    /*timeit_sum();
    timeit_sub();
    timeit_mul();
    timeit_inv();*/

    //*************Following example is modificable and important************
    //the example is made, because there is an error that couldn't
    //be fixed when we initialize a matrix with dimensions greater than 4
    //with varibales. If we enter the values by hand, it works correctly.
    //In this case, I entered two 6x6 matrices, but you can modify it to see that
    //logic of algorithms is correct.

    //creating matrices
    Matrix *M1 = new Matrix(6,6);
    Matrix *M2 = new Matrix(6,6);
    //filling matrix randomly
    M1->random_matrix();
    M2->random_matrix();

    srand(time(NULL));
    cout<<"------------Example matrix 1-----------\n";
    M1->print();
    cout<<"------------Example matrix 2-----------\n";
    M2->print();
    cout<<"------------Sum (Sequential)-----------\n";
    (*M1 + *M2)->print();
    cout<<"------------Sum (Parallel)-----------\n";
    parallel_sum(M1,M2)->print();
    cout<<"------------Subtraction (Sequential)-----------\n";
    (*M1 - *M2)->print();
    cout<<"------------Subtraction (Parallel)-----------\n";
    parallel_sub(M1,M2)->print();
    cout<<"------------Multiplicaction (Sequential)-----------\n";
    (*M1 * *M2)->print();
    cout<<"------------Multiplicaction (Parallel)-----------\n";
    parallel_mul(M1,M2)->print();
    cout<<"------------Inverse of Matrix 1 (Sequential)-----------\n";
    M1->inverse()->print();
    cout<<"------------Inverse of Matrix 1 (Parallel)-----------\n";
    parallel_inv(M1)->print();
    

    delete M1, M2;



    
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
            cout << "---------Sum (Sequential)---------\n";
            (*M1 + *M2)->print();
            cout << "---------Sum (Parallel)---------\n";
            parallel_sum(M1,M2)->print();
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
            cout << "---------Subtraction (Sequential)---------\n";
            (*M1 - *M2)->print();
            cout << "---------Subtraction (Parallel)---------\n";
            parallel_sub(M1,M2)->print();

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
            cout << "---------Multiplication (Sequential)---------\n";
            ((*M1) * (*M2))->print();
            cout << "---------Multiplication (Parallel)---------\n";
            parallel_mul(M1,M2)->print();
            

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
            cout << "---------Inverse (Sequential)---------\n";
            if(M->inverse() != NULL){
                M->inverse()->print();
            }else{
                cout << "Inverse cannot be computed :c\n\n";
            }        

            cout << "---------Inverse (Parallel)---------\n";
            parallel_inv(M)->print();

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
    

    return 0;
}


void timeit_sum(){
    ofstream sum_records;

    int sizes[50] = {50,100,150,200,250,300,350,400,450,500,550,600,650,700,750,800,850,900,950,1000,1050,1100,1150,1200,1250,1300,1350,1400,1450,1500,1550,1600,1650,1700,1750,1800,1850,1900,1950,2000,2050,2100,2150,2200,2250,2300,2400,2500,3000,5000};
    sum_records.open ("sum_records.csv");
    sum_records<<"size, seq_time, par_time\n";
    for (int i = 0; i < 50; i++) {
        
        int r = rand()%100;
        Matrix *M1 = new Matrix(sizes[i],sizes[i]);
        Matrix *M2 = new Matrix(sizes[i],sizes[i]);
        sum_records<<sizes[i]<<",";
        srand(time(NULL));
        M1->random_matrix();
        M2->random_matrix();

        // Get starting timepoint 
        auto start1 = high_resolution_clock::now(); 
        (*M1 + *M2);
        auto stop1 = high_resolution_clock::now(); 
        auto duration1 = duration_cast<microseconds>(stop1 - start1);
        double time1 = duration1.count();
        sum_records<<time1<<",";


        // Get starting timepoint 
        auto start2 = high_resolution_clock::now(); 
        parallel_sum(M1,M2);
        auto stop2 = high_resolution_clock::now(); 
        auto duration2 = duration_cast<microseconds>(stop2 - start2);
        double time2 = duration2.count();
        sum_records<<time2<<"\n";
        
        
        delete M1, M2;
    }
}

void timeit_sub(){
    ofstream sum_records;

    int sizes[50] = {50,100,150,200,250,300,350,400,450,500,550,600,650,700,750,800,850,900,950,1000,1050,1100,1150,1200,1250,1300,1350,1400,1450,1500,1550,1600,1650,1700,1750,1800,1850,1900,1950,2000,2050,2100,2150,2200,2250,2300,2400,2500,3000,5000};
    sum_records.open ("sub_records.csv");
    sum_records<<"size, seq_time, par_time\n";
    for (int i = 0; i < 50; i++) {
        
        int r = rand()%100;
        Matrix *M1 = new Matrix(sizes[i],sizes[i]);
        Matrix *M2 = new Matrix(sizes[i],sizes[i]);
        sum_records<<sizes[i]<<",";
        srand(time(NULL));
        M1->random_matrix();
        M2->random_matrix();

        // Get starting timepoint 
        auto start1 = high_resolution_clock::now(); 
        (*M1 - *M2);
        auto stop1 = high_resolution_clock::now(); 
        auto duration1 = duration_cast<microseconds>(stop1 - start1);
        double time1 = duration1.count();
        sum_records<<time1<<",";


        // Get starting timepoint 
        auto start2 = high_resolution_clock::now(); 
        parallel_sub(M1,M2);
        auto stop2 = high_resolution_clock::now(); 
        auto duration2 = duration_cast<microseconds>(stop2 - start2);
        double time2 = duration2.count();
        sum_records<<time2<<"\n";
        
        
        delete M1, M2;
    }
}


void timeit_mul(){
    ofstream sum_records;

    int sizes[50] = {10 , 20 , 30 , 40 , 50 , 60 , 70 , 80 , 90 , 100 , 110 , 120 , 130 , 140 , 150 , 160 , 170 , 180 , 190 , 200 , 210 , 220 , 230 , 240 , 250 , 260 , 270 , 280 , 290 , 300 , 310 , 320 , 330 , 340 , 350 , 360 , 370 , 380 , 390 , 400 , 410 , 420 , 430 , 440 , 450 , 460 , 470 , 480 , 490, 500};
    sum_records.open ("mul_records.csv");
    sum_records<<"size, seq_time, par_time\n";
    for (int i = 0; i < 50; i++) {
        
        int r = rand()%100;
        Matrix *M1 = new Matrix(sizes[i],sizes[i]);
        Matrix *M2 = new Matrix(sizes[i],sizes[i]);
        sum_records<<sizes[i]<<",";
        srand(time(NULL));
        M1->random_matrix();
        M2->random_matrix();

        // Get starting timepoint 
        auto start1 = high_resolution_clock::now(); 
        (*M1 * *M2);
        auto stop1 = high_resolution_clock::now(); 
        auto duration1 = duration_cast<microseconds>(stop1 - start1);
        double time1 = duration1.count();
        sum_records<<time1<<",";


        // Get starting timepoint 
        auto start2 = high_resolution_clock::now(); 
        parallel_mul(M1,M2);
        auto stop2 = high_resolution_clock::now(); 
        auto duration2 = duration_cast<microseconds>(stop2 - start2);
        double time2 = duration2.count();
        sum_records<<time2<<"\n";
        
        
        delete M1, M2;
    }
}



void timeit_inv(){
    ofstream sum_records;

    int sizes[50] = {10 , 20 , 30 , 40 , 50 , 60 , 70 , 80 , 90 , 100 , 110 , 120 , 130 , 140 , 150 , 160 , 170 , 180 , 190 , 200 , 210 , 220 , 230 , 240 , 250 , 260 , 270 , 280 , 290 , 300 , 310 , 320 , 330 , 340 , 350 , 360 , 370 , 380 , 390 , 400 , 410 , 420 , 430 , 440 , 450 , 460 , 470 , 480 , 490, 500};
    sum_records.open ("inv_records.csv");
    sum_records<<"size, seq_time, par_time\n";
    for (int i = 0; i < 50; i++) {
        
        Matrix *M = new Matrix(sizes[i],sizes[i]);
        sum_records<<sizes[i]<<",";
        srand(time(NULL));
        M->random_matrix();

        // Get starting timepoint 
        auto start1 = high_resolution_clock::now(); 
        M->inverse();
        auto stop1 = high_resolution_clock::now(); 
        auto duration1 = duration_cast<microseconds>(stop1 - start1);
        double time1 = duration1.count();
        sum_records<<time1<<",";


        // Get starting timepoint 
        auto start2 = high_resolution_clock::now(); 
        parallel_inv(M);
        auto stop2 = high_resolution_clock::now(); 
        auto duration2 = duration_cast<microseconds>(stop2 - start2);
        double time2 = duration2.count();
        sum_records<<time2<<"\n";
        
        
        delete M;
    }
}
