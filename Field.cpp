#include <iostream>
#include "Field.h"
using namespace std;

Field::Field(const vector<vector<int>> & element)
{
    matirx = element;
    int rows = element.size();
    int cols = element[0].size();

    precompSum = element;

    // Precomputing for the rest of the 2D vector 
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            // do if there is only one element
            if(i == 0 && j == 0)
                    precompSum[i][j] = matirx[i][j];
            // computing the first row
            else if(i == 0)
                    precompSum[i][j] = matirx[i][j] + precompSum[i][j-1]; 
            // computing the first column
            else if(j == 0)
                    precompSum[i][j] = matirx[i][j] + precompSum[i-1][j];
   
            else  // actually still feel mess if prof did not explain previous
                    precompSum[i][j] = matirx[i][j] + precompSum[i-1][j] + precompSum[i][j-1] - precompSum[i-1][j-1];  
         }
    }
    
}

Field::Field(vector<vector<int>> && element)
{
    matirx = element;
    int rows = element.size();
    int cols = element[0].size();
    
    precompSum = element;

    // Precomputing for the rest of the 2D vector 
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            // do if there is only one element
            if(i == 0 && j == 0)
                    precompSum[i][j] = matirx[i][j];
            // computing the first row
            else if(i == 0)
                    precompSum[i][j] = matirx[i][j] + precompSum[i][j-1]; 
            // computing the first column
            else if(j == 0)
                    precompSum[i][j] = matirx[i][j] + precompSum[i-1][j];
   
            else  // actually still feel mess if prof did not explain previous
                    precompSum[i][j] = matirx[i][j] + precompSum[i-1][j] + precompSum[i][j-1] - precompSum[i-1][j-1];  
         }
    }
    
}

 /**@returns the sum of all elements in the rectangle defined by the points (x1,y1) and (x2,y2). **/
 //need to do the precomputing in the constructors
int Field::Weight(int x1, int y1, int x2, int y2)
{
     if((0 <= x1 < rows) && (0 <= x2 < rows) && (0 <= y1 < cols) && (0 <= y2 < cols))
     {
        // find the new range i, j for computing small matirx
        int rows1 = min(y1, y2);
        int rows2 = max(y1, y2);
        int cols1 = min(x1, x2);
        int cols2 = max(x1, x2);
         
        for(int i=rows1; i<=rows2; i++)
        {
            for(int j=cols1; j<=cols2; j++)
            {
                ////think about how to use precompu
        
      
     }
     else 
        throw out_of_range("Index is out of range");  // do if coordinates go beyond the array boundaries
}

//This method computes the cost of the cheapest path from top-left corner of the field to the bottom-right corner.
//The only possible moves are right and down.
int Field::PathCost()
{
    if (matirx.empty()) return 0;

    int rows = matirx.size();
    int cols = matirx[0].size();

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == 0 && j == 0) continue;
            if (i == 0) 
                matirx[i][j] += matirx[i][j - 1];
            else if (j == 0)
                matirx[i][j] += matirx[i - 1][j];
            else
                matirx[i][j] += min(matirx[i][j - 1], matirx[i - 1][j]);
        }
    }
    
    return matirx[rows - 1][cols - 1];    
}
    
