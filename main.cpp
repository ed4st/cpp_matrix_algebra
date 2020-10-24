#include "Matrix.h"

int main(){
    Matrix m1(3,3); //static

    m1.random_matrix();
    m1.print();
    cout << "max number of the matrix 1: " << m1.max() <<"\n";

    Matrix *m2; // dinamic
    m2 = new Matrix(10,10);

    m2->random_matrix();
    m2->print();
    cout << "max number of the matrix 2: " << m2->max() <<"\n";



    delete m2;
    return 0;
}
//compilación por terminal