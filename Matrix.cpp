#include "Matrix.h"
//---------------getters and setters--------------
int Matrix::get_ncols(){
    return this->_ncols;
}

int Matrix::get_nrows(){
    return this->_nrows;
}

void Matrix::set_ncols(int ncols){
    this->_ncols = ncols;
}

void Matrix::set_nrows(int nrows){
    this->_nrows = nrows;
}

//----------------constructors and destructors---------
Matrix::Matrix(int nrows, int ncols){
    _nrows = nrows;
    _ncols = ncols;
    _A = new int *[nrows];
    for (int i = 0; i < nrows; i++)
    {
        _A[i] = new int[ncols];
    }
}
Matrix::~Matrix(){
    for (int i = 0; i < _nrows; i++)
    {
        delete [] _A[i];
    }
    delete[] _A;
}

//-----------------Methods------------------------------

//here we genetate a matrix with values between 0 and 99
void Matrix::random_matrix(){
    for (int i = 0; i < _nrows; i++)
    {
        for (int j = 0; j < _ncols; j++)
        {
            _A[i][j] = rand()%100;
        }    
    }                            
}
void Matrix::print(){
    for (int i = 0; i < _nrows; i++)
    {
        for (int j = 0; j < _ncols; j++)
        {
            cout << _A[i][j] << "\t";
        }
        cout << endl;
    }   
}

int Matrix::max(){
    int max = INT8_MIN;
    for (int i = 0; i < _nrows; i++)
    {
        for (int j = 0; j < _ncols; j++)
        {
            if(max <= _A[i][j]){
                max = _A[i][j];
            }
            
        }
    }
    return max;
}
//---------------------operators overloading-------------
Matrix* Matrix::operator+(Matrix const &M){
    Matrix *S = new Matrix(_nrows, _ncols); //S is the result of the sum
                                           //Dinamic
    for (int i = 0; i < _nrows; i++)
    {
        for (int j = 0; j < _ncols; j++)
        {
            S->_A[i][j] = _A[i][j] + M._A[i][j];
        }
            
    }
    return S;
}

// folowwing operator can be used as
// Matrix *m3 = *m1 + m2; 
// with m2 dinamic
/*Matrix* Matrix::operator+(Matrix *M){
    Matrix *S = new Matrix(_nrows, _ncols); //S is the result of the sum
                                           //Dinamic
    for (int i = 0; i < _nrows; i++)
    {
        for (int j = 0; j < _ncols; j++)
        {
            S->_A[i][j] = _A[i][j] + M->_A[i][j];
        }
            
    }
    return S;
}*/