#include "Matrix.h"

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

