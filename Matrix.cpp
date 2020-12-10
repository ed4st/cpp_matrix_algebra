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

void Matrix::set_Aij(int i, int j, double val){
    this->_A[i][j] = val;
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
void* parallel_inv(void *_inv_args);
Matrix* parallel_inv(Matrix *M);


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



struct MulArguments{
	int sup_row; //inferior limit of rows of submatrix
	int inf_row; //superior limit of rows of submatrix
    //int sup_col; //inferior limit of columns of submatrix
	//int inf_col; //superior limit of columns of submatrix
    Matrix* M1; //matrix to sum
    Matrix* M2; //matrix to sum
    Matrix* result; //matrix to sum
};

void* parallel_mul(void *mul_args){
    MulArguments *_mul_args = (MulArguments*) mul_args;

    //iterate over rows of current submatrix
    double ** matrixAux = _mul_args->result->get_A();

    for (int k = _mul_args->inf_row; k < _mul_args->sup_row; k++) {
        for (int i = 0; i < _mul_args->M2->get_ncols(); i++) {
            int sum = 0;
            for (int j = 0; j < _mul_args->M1->get_nrows(); j++) {
                sum += _mul_args->M1->get_A()[k][j]*_mul_args->M2->get_A()[j][i];
            }
            matrixAux[k][i] = sum;
        }
    }
    _mul_args->result->set_A(matrixAux);
    return NULL;
}



//Overloading parallel_sum function
Matrix* parallel_mul(Matrix *M1, Matrix *M2){
    int nrows = M1->get_nrows();
    int ncols= M2->get_ncols();

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
		pthread_create(&thr[i],&attr, parallel_mul, &sum_args[i]);
	}

    for(int i=0;i<NTHREADS;i++){
		pthread_join(thr[i], NULL);
	}


    delete [] thr;
	delete [] sum_args;
    return result;
}




struct InverseArguments{
	int sup_row; //inferior limit of rows of submatrix
	int inf_row; //superior limit of rows of submatrix
    //int sup_col; //inferior limit of columns of submatrix
	//int inf_col; //superior limit of columns of submatrix
    Matrix* M; //matrix to sum
    Matrix* I; //Inverse
    Matrix* E; //extended 2n x 2n matrix
};

void* parallel_inv(void *inv_args){
    InverseArguments *_inv_args = (InverseArguments*) inv_args;

    //iterate over rows of current submatrix
    double ** matrixAux = _inv_args->I->get_A();

    int i = 0, j = 0, k = 0, n = 0;
        double **mat = _inv_args->E->get_A();
        double d = 0.0;
        
        n = _inv_args->M->get_ncols();
        
        // Extending the size of the matrix
        /*mat = new double*[2*n];
        for (i = 0; i < 2*n; ++i)
        {
            mat[i] = new double[2*n]();
        }
        */
        //Copying the left side of extended matrix (this)
        pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
        for(i = _inv_args->inf_row; i < _inv_args->sup_row; ++i)
        {
            for(j = 0; j < n; ++j)
            {
                pthread_mutex_lock(&mutex);
                _inv_args->E->set_Aij(i,j,_inv_args->M->get_A()[i][j]);
                pthread_mutex_unlock(&mutex);
                //mat[i][j] = _inv_args->M->get_A()[i][j];
            }
        }
        // Aumented identity matrix
        for(i = _inv_args->inf_row; i < _inv_args->sup_row; ++i)
        {
            for(j = 0; j < 2*n; ++j)
            {
                if(j == (i+n))
                {
                    pthread_mutex_lock(&mutex);
                    _inv_args->E->set_Aij(i,j,1);
                    pthread_mutex_unlock(&mutex);
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
                matrixAux[i][j-n] =  mat[i][j];
            }
        }
        _inv_args->I->set_A(matrixAux);
    return NULL;
}



//Overloading parallel_sum function
Matrix* parallel_inv(Matrix *M){
    int nrows = M->get_nrows();
    int ncols= M->get_ncols();

    Matrix *result = new Matrix(nrows,ncols);
    //following matrix is initialized with zeroes entries, so
    //it's easier to get access to this one in each thread
    result->zero_matrix();
    //we also create an extended martix to copy values
    Matrix * E = new Matrix(2*ncols, 2*ncols);
    E->zero_matrix();

    //initializing NTHREADS threads
    pthread_t *thr = new pthread_t[NTHREADS];
    
    InverseArguments *inv_args = new InverseArguments[NTHREADS];

    int subint = floor(ncols/NTHREADS);

	for(int i = 0; i < NTHREADS; i++){
		if(i == NTHREADS-1){
			inv_args[i].sup_row = ncols;
		    inv_args[i].inf_row = subint*i;	
		}else{
			inv_args[i].inf_row = subint*i;
			inv_args[i].sup_row = subint*(i+1);
		}
        inv_args[i].M = M;
        inv_args[i].E = E;
        inv_args[i].I= result;
        result = M->inverse();
		pthread_attr_t attr;
		pthread_attr_init(&attr);
		pthread_create(&thr[i],&attr, parallel_inv, &inv_args[i]);
	}

    for(int i=0;i<NTHREADS;i++){
		pthread_join(thr[i], NULL);
	}
    

    delete [] thr;
	delete [] inv_args;
    return result;
}

