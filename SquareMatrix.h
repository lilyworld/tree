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
	   bool operator==(const SquareMatrix<T>& rhs)const; // Matrices A and B are considered equal if their sizes are equal and all elements of A match the corresponding elements of B.
	   SquareMatrix operator+ (const SquareMatrix<T>& rhs)const; //The result of addition of two square matrices A and B
	   void resize(int new_size);  // Restroys all previous content of the matrix and releases all memory. Then it allocates new memory. New elements are not specified (can have any value)
	   const T& at(int row, int column) const;  // Returns a reference to the element in the given row and column
	   int size()const;   // Returns the current size of the matrix
	   
     private:
	   int size_;
	   T** array_;
};

/** Default Constructor**/
template<class T>
SquareMatrix<T>::SquareMatrix()
{
	size_ = 0;
	array_ = nullptr;
}

/** Destructor **/
template<class T>
SquareMatrix<T>::~SquareMatrix(){}

/** copy constructor **/
template<class T>
SquareMatrix<T>::SquareMatrix(const SquareMatrix<T>& rhs)
{	
	size_ = 0;
	array_ = nullptr;

	*this = rhs;
}

/** move constructor **/
template<class T>
SquareMatrix<T>::SquareMatrix(SquareMatrix<T>&& rhs) : array_{rhs.array_}
{
	rhs.array_ = nullptr;
}

/** copy assignment**/
template<class T>
SquareMatrix<T>& SquareMatrix<T>::operator=(const SquareMatrix<T>& rhs)
{	
	size_ = rhs.size_;
	array_ = new T*[size_];
	for(int i=0; i < size_; i++)
	{
		array_[i] = new T[size_];
	}

	// copy the elewnts
	for (int i=0; i < size_; i++)
	{
		for (int j=0; j < size_; j++)
		{
			array_[i][j] = rhs.array_[i][j];
		}
	} 
	
}

/** Move assignment **/
template<class T>
SquareMatrix<T>& SquareMatrix<T>::operator= (SquareMatrix<T> && rhs)
{
	size_ = rhs.size_;
	array_ = rhs.array_;

	// distroy the contents of rhs, and release memory
	rhs.size_ = 0;
	rhs.array_ = nullptr;
	
	return *this;
}

/**@return true if SquareMatrix A is equal to SquareMatrix B, otherwise is false**/
template<class T>
bool SquareMatrix<T>::operator==(const SquareMatrix<T>& rhs) const
{
	if(size_ != rhs.size_)
	{
		return false;
	}
	for(int i=0; i<size_; i++)
	{
		for(int j=0; j<size_; j++)
		{
			if(array_[i][j] != rhs.array_[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

/**@return third SquareMatrix which is the sum of SquareMatrix A and SquareMatrix B**/
template<class T>
SquareMatrix<T> SquareMatrix<T>:: operator+ (const SquareMatrix<T>& rhs) const
{
	SquareMatrix<T> result(*this);
	if(operator==(rhs))
	{   
		for (int i = 0; i < size_; i++)
		{
			for (int j = 0; j < size_; j++)
			{
				result.array_[i][j] += rhs.array_[i][j];
			}
		}
	}
	return result;
}

/**This function destroys all previous content of the matrix and releases all memory.
 Then it allocates new memory. New elements are not specified (can have any value).**/
template<class T>
void SquareMatrix<T>::resize(const int new_size)
{
	T** tem = new T*[new_size];
	for(int i=0; i<new_size; i++)
	{
		tem[i]= new T[new_size];
	}
	for(int i=0; i<size_; i++)
	{
		for(int j=0; j<size_; j++)
		{
			tem[i][j] = array_[i][j];
		}
	}
	if(array_ != NULL)
	{
		for (int i = 0; i < size_; i++)
		{
			delete[] array_[i]; //This destroys all previous content of the matrix
		}
		delete[] array_;  //release memory
	}
	array_ = tem;
	size_ = new_size;

}

/**@ returns a reference to the element in the given row and column**/
//If the suggested row or column doesn't exist, throw the std::out_of_range exception.
template<class T>
const T& SquareMatrix<T>::at(int row, int col) const
{
	if(row > size_ || col > size_)
	{
		cout<< "out_of_range exception" << endl;
	}
	else
	{
		return array_[row][col];
	}
}

/**@return the current size of square matrix**/
/**the size 10 means that the matrix is 10X10 elements large. **/
template<class T>
int SquareMatrix<T>::size() const
{
	return size_;  
}

#endif
