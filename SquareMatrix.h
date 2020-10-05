#ifndef SQUAREMATRIX_H
#define	SQUAREMATRIX_H
#include <iostream>
using namespace std;

template<class T>
class SquareMatrix
{
    public:
	   SquareMatrix();  // Default constructor
	   ~SquareMatrix();   //Destructor
	   SquareMatrix(const SquareMatrix<T> & rhs);  //Copy constructor
	   SquareMatrix(SquareMatrix<T> && rhs);   // Move constructor
	   SquareMatrix & operator= (const SquareMatrix<T> & rhs);  // Copy assignment
	   SquareMatrix & operator= (SquareMatrix<T> && rhs);   // Move assignment
	   bool operator==(const SquareMatrix& A, const SquareMatrix& B); // Matrices A and B are considered equal if their sizes are equal and all elements of A match the corresponding elements of B.
	   SquareMatrix operator+ (const SquareMatrix& A, const SquareMatrix& B); //The result of addition of two square matrices A and B
	   void resize(T* new_size);  // Restroys all previous content of the matrix and releases all memory. Then it allocates new memory. New elements are not specified (can have any value)
	   const T& at(int row, int column) const;  // Returns a reference to the element in the given row and column
	   int size() const;   // Returns the current size of the matrix
	   
     private:
	   int num_rows_, num_cols_;
	   T* array_;
};

/** Default Constructor**/
template<class T>
SquareMatrix<T>::SquareMatrix()
{
	num_rows_ = 0;
	num_cols_ = 0;
	array_ = nullptr;
}

/** Destructor **/
template<class T>
SquareMatrix<T>::~SquareMatrix(){};

/** copy constructor **/
template<class T>
SquareMatrix<T>::SquareMatrix(const SquareMatrix<T>& rhs)
{	
	num_rows_ = 0;
	num_cols_ = 0;
	array_ = nullptr;

	*this = rhs;
}

/** move constructor **/
template<class T>
SquareMatrix<T>::SquareMatrix(SquareMatrix<T>&& rhs) : array_{rhs.array_}
{
	/**Initialize the new *this
	num_rows_ = 0;
	num_cols_ = 0;
	array_ = nullptr;

	// Shallow copy of other
	*this = std::move(other); **/
	rhs.array_ = nullptr;
}

/** copy assignment**/
template<class T>
SquareMatrix<T>::operator=(const SquareMatrix<T>& rhs)
{	
	// Get dimensions
	/**num_rows_ = rhs.num_rows_;
	num_cols_ = rhs.num_cols_;

	// (Re)Initialize Array
	array_ = new T*[num_rows_];
	for (int i=0; i < num_rows_; i++)
	{
		array_[i] = new T[num_cols_];
	}

	// Fill Array
	for (int i=0; i < num_rows_; i++)
	{
		for (int j=0; j < num_cols_; j++)
		{
			array_[i][j] = rhs.array_[i][j];
		}
	} **/
	if(this != &rhs)
	{	
		SquareMatirx copy = rhs;
		swap(*this, copy);
	}
	return *this;
}

/** Move assignment **/
template<class T>
SquareMatrix<T>::SquareMatrix & operator= (SquareMatrix<T> && rhs)
{
	num_rows_ = rhs.num_rows_;
	num_cols_ = rhs.num_cols_;
	array_ = rhs.array_;

	// distroy the contents of rhs, and release memory
	rhs.num_rows_ = 0;
	rhs.num_cols_ = 0;
	rhs.array_ = nullptr;
	
	return *this;
}

/**@return true if SquareMatrix A is equal to SquareMatrix B, otherwise is false**/
template<class T>
bool operator==(const SquareMatrix& A, const SquareMatrix& B)
{
	return (A.num_rows_ == B.num_rows_) && (A.num_cols_ == B.num_cols_) && (A[i][j] == B[i][j]);
}

/**@return third SquareMatrix which is the sum of SquareMatrix A and SquareMatrix B**/
SquareMatrix operator+ (const SquareMatrix& A, const SquareMatrix& B)
{
	SquareMatrix& S;
	if(operator==(const SquareMatrix& A, const SquareMatrix& B))
	{
		SquareMatrix& S = SquareMatrix& A + SquareMatrix& B;
	}
	return SquareMatrix& S;
}

/**This function destroys all previous content of the matrix and releases all memory.
 Then it allocates new memory. New elements are not specified (can have any value).**/
void resize(const T& new_size)
{
	for (int i = 0; i < num_rows_; i++)
	{
		delete[] array_[i]; //This destroys all previous content of the matrix
	}

	delete[] array_;  //release memory
	array_ = nullptr;
	num_rows_ = 0;
	num_cols_ = 0;	

	break;
}

/**@ returns a reference to the element in the given row and column**/
//If the suggested row or column doesn't exist, throw the std::out_of_range exception.
template<class T>
const T& at(int row, int col) const
{
	return array_[row][col];
}

/**@return the current size of square matrix**/
/**the size 10 means that the matrix is 10X10 elements large. **/
template<class T>
int size() const
{
	return num_rows_;  //because it is a Square matrix, either num_rows_ or num_cols_ is fine
}

#endif
