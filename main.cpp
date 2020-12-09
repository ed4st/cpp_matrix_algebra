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
#include <pthread.h>

int main(){
    
    int nrows, ncols;
    nrows = 5;
    ncols = 6;
    //creating matrices
    Matrix *M1 = new Matrix(nrows,ncols);
    Matrix *M2 = new Matrix(nrows,ncols);
    Matrix *result = new Matrix(nrows,ncols);

    //filling matrix randomly
    srand(time(NULL));
    M1->random_matrix();
    M2->random_matrix();
    result->zero_matrix();
    
    
    pthread_t thr1, thr2;
    SumArguments arg1, arg2;
    
    arg1.inf_col = 0;
    arg1.sup_col = 2;
    arg1.M1 = M1;
    arg1.M2 = M2;
    arg1.result = result;

    arg2.inf_col = 3;
    arg2.sup_col = 5;
    arg2.M1 = M1;
    arg2.M2 = M2;
    arg2.result = result;

    M1->print();
    M2->print();
    result->print();

    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&thr1,&attr, parallel_sum, &arg1);
    pthread_attr_t attr2;
    pthread_attr_init(&attr2);
    pthread_create(&thr2,&attr2, parallel_sum, &arg2);
    pthread_join(thr1,NULL);
    pthread_join(thr2,NULL);
    
    result->print();
    //Building a NxN matrix whose entries are pthreads_t objects
    /*int N = sqrt(NTHREADS);
    pthread_t** thr = new pthread_t *[N];
    for (int i = 0; i < N; i++) {
        thr[i] = new pthread_t[N];
    }

	SumArguments ** sum_args = new SumArguments*[N];
    for (int i = 0; i < N; i++) {
        sum_args[i] = new SumArguments[N];
    }


	int col_subint = floor(ncols/(N));
    int row_subint = floor(nrows/(N));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if((i == N - 1) && (j == N - 1)){
                sum_args[i][j].sup_row = N;
                sum_args[i][j].sup_col = N;
                sum_args[i][j].inf_row = row_subint*i;
                sum_args[i][j].inf_col = col_subint*j;                
            }else if((i == N - 1) && (j < N - 1)){
                sum_args[i][j].sup_row = N;
                sum_args[i][j].sup_col = col_subint*(j + 1);
                sum_args[i][j].inf_row = row_subint*i;
                sum_args[i][j].inf_col = col_subint*j;                
            }else if((i < N - 1) && (j == N - 1)){
                sum_args[i][j].sup_row = row_subint*(i + 1);
                sum_args[i][j].sup_col = N;
                sum_args[i][j].inf_row = row_subint*i;
                sum_args[i][j].inf_col = col_subint*j;                
            }else {
                sum_args[i][j].sup_row = row_subint*(i + 1);
                sum_args[i][j].sup_col = col_subint*(j + 1);
                sum_args[i][j].inf_row = row_subint*i;
                sum_args[i][j].inf_col = col_subint*j;   
            }
            sum_args[i][j].M1 = M1;
            sum_args[i][j].M2 = M2;
            sum_args[i][j].result = result;

            pthread_attr_t attr;
            pthread_attr_init(&attr);
            pthread_create(&thr[i][j],&attr, parallel_sum, &sum_args[i][j]);
        }
	}

    
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            pthread_join(thr[i][j], NULL);
	    }
	}
    
    sum_args[0][0].M1->print();
    
    sum_args[0][0].M2->print();
    
    cout<<sum_args[0][1].inf_col;
    
    //sum_args[0][0].result->print();

    //deleting instancies
    
    for (int i = 0; i < N; i++) {
        delete [] thr[i];
    }
    delete [] thr;

    for (int i = 0; i < N; i++) {
        delete [] sum_args[i];
    }
    delete [] sum_args;*/



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
