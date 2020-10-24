#include "Matrix.h"

int main(){
    Matrix m1(10,10); //static

    m1.random_matrix();
    m1.print();
    cout << "max number of the matrix 1: " << m1.max() <<"\n";

    Matrix *m2; // dinamic
    m2 = new Matrix(10,10);

    m2->random_matrix();
    m2->print();
    cout << "max number of the matrix 2: " << m2->max() <<"\n";


    Matrix *m3 = *m2 + *m2;
    cout << "sum of matrices:\n";
    m3->print();

    delete m2;
    return 0;
}
//compilación por terminal