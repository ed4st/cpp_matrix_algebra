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
    _A = new double *[nrows];
    for (int i = 0; i < nrows; i++)
    {
        _A[i] = new double[ncols];
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
    if(_A !=NULL){
        for (int i = 0; i < _nrows; i++)
        {
            for (int j = 0; j < _ncols; j++)
            {
                cout << _A[i][j] << "\t";
            }
            cout << endl;
        }
    }       
}


Matrix* Matrix::traspose(){
    Matrix *S = new Matrix(_ncols, _nrows);
    for (int i = 0; i < _nrows; i++)
    {
        for (int j = 0; j < _ncols; j++)
        {
            S->_A[j][i] = _A[i][j];
        }            
    }
    return S;    
}

Matrix* Matrix::inverse(){
    if(_ncols != _nrows){
        cout << "Matrix is not square.\n";
        return NULL;
    }
    else
    {
        //first, we set precision to get 2 floating point values
        
        //following matrix is the aumented identity matrix
        Matrix *I = new Matrix(_nrows, _ncols);

        

        return I;
    }
    
}


//---------------------operators overloading-------------
Matrix* Matrix::operator+(Matrix const &M){

    Matrix *S = new Matrix(_nrows, _ncols); //S is the result of the sum

    // first, we verify if the dimension of two matrices are equal
    if((_ncols == M._ncols) && (_nrows == M._nrows)){
        for (int i = 0; i < _nrows; i++)
        {
            for (int j = 0; j < _ncols; j++)
            {
                S->_A[i][j] = _A[i][j] + M._A[i][j];
            }
                
        }
    }
    else
    {
        cout<<"Dimension of matrices are different.\n";
        S->_A = NULL;
    }
    return S;
}

Matrix* Matrix::operator-(Matrix const &M){
    Matrix *S = new Matrix(_nrows, _ncols); //S is the result of the subtraction
    
    // first, we verify if the dimension of two matrices are equal
    if((_ncols == M._ncols) && (_nrows == M._nrows)){
        for (int i = 0; i < _nrows; i++)
        {
            for (int j = 0; j < _ncols; j++)
            {
                S->_A[i][j] = _A[i][j] - M._A[i][j];
            }
                
        }
    }
    else
    {
        cout<<"Dimension of matrices are different.\n";
        S->_A = NULL;
    }
    return S;
}


Matrix* Matrix::operator*(Matrix const &M){
    Matrix *S = new Matrix(_nrows, M._ncols); //S is the result of the multiplication
    
    // first, we verify if the dimension is right
    if(this->_ncols == M._nrows){
        for (int i = 0; i < _nrows; i++)
        {
            for (int j = 0; j < M._ncols; j++)
            {
                //definig the sum as usual column-row product 
                double sum =0;
                for (int k = 0; k < _ncols; k++)
                {
                    sum += _A[i][k]*M._A[k][j];
                }
                
                S->_A[i][j] = sum;
            }
                
        }
    }
    else
    {
        cout<<"Number of columns and number of rows doesn't match.\n";
        S->_A = NULL;
    }
    return S;
}

