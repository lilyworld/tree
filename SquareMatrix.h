#ifndef SquareMatrix.h
#define	SquareMatrix.h
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
	   resize(new_size);  // Restroys all previous content of the matrix and releases all memory. Then it allocates new memory. New elements are not specified (can have any value)
	   at(row, column);  // Returns a reference to the element in the given row and column
	   size();   // Returns the current size of the matrix
	   
	 private:
	   size_t num_rows_, num_cols_;?
}；

#endif
