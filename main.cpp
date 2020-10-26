#include "Matrix.h"

int main(){

    Matrix *m1 = new Matrix(2,2);
    Matrix *m2 = new Matrix(2,2);
    
    //generating random matrices
    srand(time(NULL));
    m1->random_matrix();
    m2->random_matrix();
    
    
    //printing matrices:

    cout << "-----------Matrix 1-----------\n";
    m1->print();

    cout << "-----------Matrix 2-----------\n";
    m2->print();

    //here we sum
    Matrix *m3 = *m1 + *m2;
    cout << "sum of matrices:\n";
    m3->print();
    
    //here we subtract m2 to m1
    m3 = *m1 - *m2;
    cout << "subtraction of matrices:\n";
    m3->print();
    
    m3 = (*m1) * (*m2);
    cout << "Multiplication of matrices:\n";
    m3->print();
    
    cout << "Traspose of matrix 2:\n";
    m2->traspose()->print();

    cout << "Inverse of matrix 2:\n";
    m2->inverse()->print();
    

    delete m2;

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
        cout << "   0. Exit.\n";
        cin >> option;
        switch (option)
        {
        case 1:
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
            M1->random_matrix();
            M2->random_matrix();

            cout << "*********Following matrices are randomly generated*********\n"
            cout << "---------Matrix 1---------\n"
            M1->print();
            cout << "---------Matrix 2---------\n"
            M2->print();
            cout << "---------Sum---------\n"
            (*M1 + *M2)->print();
            break;
        
        default:
            break;
        }


    } while (option != 0);
    
    

    return 0;
}
//compilación por terminal