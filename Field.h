#ifndef FIELD_H
#define	FIELD_H
#include <iostream>
#include <vector>

class Field
{
  public:
    Field(const vector<vector<int>> & element);
    Field(vector<vector<int>> && element);
    int Weight(int x1, int y1, int x2, int y2);
    
    //This method computes the cost of the cheapest path from top-left corner of the field to the bottom-right corner.
    //The only possible moves are right and down.
    int PathCost();
    
 };

#endif


