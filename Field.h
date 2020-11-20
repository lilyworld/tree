#ifndef FIELD_H
#define	FIELD_H
#include <iostream>
#include <vector>

class Field
{
  public:
    Field(const std::vector<std::vector<int>> & element);
    Field(std::vector<std::vector<int>> && element);
  
    /**@returns the sum of all elements in the rectangle defined by the points (x1,y1) and (x2,y2). **/
    //need to do the precomputing in the constructors
    int Weight(int x1, int y1, int x2, int y2);
    
    //This method computes the cost of the cheapest path from top-left corner of the field to the bottom-right corner.
    //The only possible moves are right and down.
    int PathCost();
  
  private:
    int rows, cols;  //numbers of rows and coloums.
    std::vector<std::vector<int>> matirx;   // store the 2-D matirx, work for pathcost()
    std::vector<std::vector<int>> precompSum;  // store the precomputing sum, work for weight()
    
 };

#endif


