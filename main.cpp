#include "Matrix.h"

int main(){

    Matrix *m1 = new Matrix(2,3);
    Matrix *m2 = new Matrix(3,4);
    
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
    

    delete m2;
    return 0;
}
//compilación por terminal