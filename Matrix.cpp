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

double** Matrix::get_A(){
    return _A;
}

void Matrix::set_A(double** A){
    this->_A = A;
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
//here we genetate a matrix with 0 entries  
void Matrix::zero_matrix(){
    for (int i = 0; i < _nrows; i++)
    {
        for (int j = 0; j < _ncols; j++)
        {
            _A[i][j] = 0.0;
        }    
    }                            
}

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
        cout << endl;
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
        cout << "Matrix is not square.\n\n";
        return NULL;
    }
    else
    {
        //first, we set precision to get 2 floating point values
        
        //following matrix is the aumented identity matrix
        Matrix *I = new Matrix(_nrows, _ncols);

        int i = 0, j = 0, k = 0, n = 0;
        double **mat = NULL;
        double d = 0.0;
        
        n = this->_ncols;
        
        // Extending the size of the matrix
        mat = new double*[2*n];
        for (i = 0; i < 2*n; ++i)
        {
            mat[i] = new double[2*n]();
        }
        
        
        //Copying the left side of extended matrix (this)
        for(i = 0; i < n; ++i)
        {
            for(j = 0; j < n; ++j)
            {
                mat[i][j] = this->_A[i][j];
            }
        }
        // Aumented identity matrix
        for(i = 0; i < n; ++i)
        {
            for(j = 0; j < 2*n; ++j)
            {
                if(j == (i+n))
                {
                    mat[i][j] = 1;
                }
            }
        }
        
        // Partial pivoting
        for(i = n; i > 1; --i)
        {
            if(mat[i-1][1] < mat[i][1])
            {
                for(j = 0; j < 2*n; ++j)
                {
                    d = mat[i][j];
                    mat[i][j] = mat[i-1][j];
                    mat[i-1][j] = d;
                }
            }
        }
        
        // Row reduced echelon form
        for(i = 0; i < n; ++i)
        {
            for(j = 0; j < 2*n; ++j)
            {
                if(j != i)
                {
                    d = mat[j][i] / mat[i][i];
                    for(k = 0; k < n*2; ++k)
                    {
                        mat[j][k] -= mat[i][k]*d;
                    }
                }
            }
        }
        // reducing to identity matrix
        for(i = 0; i < n; ++i)
        {
            d = mat[i][i];
            for(j = 0; j < 2*n; ++j)
            {
                mat[i][j] = mat[i][j]/d;
            }
        }
        
        // Copying the aumented to the inverse
        for(i=0; i < n; ++i)
        {
            for(j = n; j < 2*n; ++j)
            {
                I->_A[i][j-n] =  mat[i][j];
            }
        }
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
        cout<<"Dimension of matrices are different.\n\n";
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
        cout<<"Dimension of matrices are different.\n\n";
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
        cout<<"Number of columns and number of rows doesn't match.\n\n";
        S->_A = NULL;
    }
    return S;
}



//---------------------operators parallelized-------------
//parallelized sum implementations. The first one, makes it through 
//one thread. The second one, makes it through all threads
void* parallel_sum(void *sum_args);
Matrix* parallel_sum(Matrix *M1, Matrix *M2);

//parallelized subtraction implementations. The first one, makes it through 
//one thread. The second one, makes it through all threads
void* parallel_sub(void *sum_args);
Matrix* parallel_sub(Matrix *M1, Matrix *M2);

//parallelized multiplication implementations. The first one, makes it through 
//one thread. The second one, makes it through all threads
void* parallel_mul(void *mul_args);
Matrix* parallel_mul(Matrix *M1, Matrix *M2);

//parallelized inverse implementations. The first one, makes it through 
//one thread. The second one, makes it through all threads
void* parallel_inv(void *mul_args);
Matrix* parallel_inv(Matrix *M1, Matrix *M2);


struct SumArguments{
	//int sup_row; inferior limit of rows of submatrix
	//int inf_row; //superior limit of rows of submatrix
    int sup_col; //inferior limit of columns of submatrix
	int inf_col; //superior limit of columns of submatrix
    Matrix* M1; //matrix to sum
    Matrix* M2; //matrix to sum
    Matrix* result; //matrix to sum
};

void* parallel_sum(void *sum_args){
    SumArguments *_sum_args = (SumArguments*) sum_args;

    //iterate over rows of current submatrix
    double ** matrixAux = _sum_args->result->get_A();

    for(int i=0; i<_sum_args->M1->get_nrows(); i++){
        

        for (int j =_sum_args->inf_col; j<=_sum_args->sup_col;j++) {
             matrixAux[i][j] = _sum_args->M1->get_A()[i][j] + _sum_args->M2->get_A()[i][j];
        }
    }
    _sum_args->result->set_A(matrixAux);
    return NULL;
}



//Overloading parallel_sum function
Matrix* parallel_sum(Matrix *M1, Matrix *M2){
    int nrows = M1->get_nrows();
    int ncols= M1->get_ncols();

    Matrix *result = new Matrix(nrows,ncols);
    //following matrix is initialized with zeroes entries, so
    //it's easier to get access to this one in each thread
    result->zero_matrix();


    //initializing NTHREADS threads
    pthread_t *thr = new pthread_t[NTHREADS];
    SumArguments *sum_args = new SumArguments[NTHREADS];

    int subint = floor(ncols/NTHREADS);

	for(int i = 0; i < NTHREADS; i++){
		if(i == NTHREADS-1){
			sum_args[i].sup_col = ncols;
		    sum_args[i].inf_col = subint*i;	
		}else{
			sum_args[i].inf_col = subint*i;
			sum_args[i].sup_col = subint*(i+1);
		}
        sum_args[i].M1 = M1;
        sum_args[i].M2 = M2;
        sum_args[i].result= result;

		pthread_attr_t attr;
		pthread_attr_init(&attr);
		pthread_create(&thr[i],&attr, parallel_sum, &sum_args[i]);
	}

    for(int i=0;i<NTHREADS;i++){
		pthread_join(thr[i], NULL);
	}


    delete [] thr;
	delete [] sum_args;
    return result;
}


void* parallel_sub(void *sum_args){
    SumArguments *_sum_args = (SumArguments*) sum_args;

    //iterate over rows of current submatrix
    double ** matrixAux = _sum_args->result->get_A();

    for(int i=0; i<_sum_args->M1->get_nrows(); i++){
        

        for (int j =_sum_args->inf_col; j<=_sum_args->sup_col;j++) {
             matrixAux[i][j] = _sum_args->M1->get_A()[i][j] - _sum_args->M2->get_A()[i][j];
        }
    }
    _sum_args->result->set_A(matrixAux);
    return NULL;
}



//Overloading parallel_sum function
Matrix* parallel_sub(Matrix *M1, Matrix *M2){
    int nrows = M1->get_nrows();
    int ncols= M1->get_ncols();

    Matrix *result = new Matrix(nrows,ncols);
    //following matrix is initialized with zeroes entries, so
    //it's easier to get access to this one in each thread
    result->zero_matrix();


    //initializing NTHREADS threads
    pthread_t *thr = new pthread_t[NTHREADS];
    SumArguments *sum_args = new SumArguments[NTHREADS];

    int subint = floor(ncols/NTHREADS);

	for(int i = 0; i < NTHREADS; i++){
		if(i == NTHREADS-1){
			sum_args[i].sup_col = ncols;
		    sum_args[i].inf_col = subint*i;	
		}else{
			sum_args[i].inf_col = subint*i;
			sum_args[i].sup_col = subint*(i+1);
		}
        sum_args[i].M1 = M1;
        sum_args[i].M2 = M2;
        sum_args[i].result= result;

		pthread_attr_t attr;
		pthread_attr_init(&attr);
		pthread_create(&thr[i],&attr, parallel_sub, &sum_args[i]);
	}

    for(int i=0;i<NTHREADS;i++){
		pthread_join(thr[i], NULL);
	}


    delete [] thr;
	delete [] sum_args;
    return result;
}