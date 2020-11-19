#include <iostream>
#include "Field.h"
using namespace std;

Field::Field(const vector<vector<int>> & element);
Field::Field(vector<vector<int>> && element);
int Field::Weight(int x1, int y1, int x2, int y2);

//This method computes the cost of the cheapest path from top-left corner of the field to the bottom-right corner.
//The only possible moves are right and down.
int Field::PathCost();
    
