#include <iostream>
#include "Field.h"
using namespace std;

Field::Field(const vector<vector<int>> & element);
Field::Field(vector<vector<int>> && element);
int Field::Weight(int x1, int y1, int x2, int y2);

//This method computes the cost of the cheapest path from top-left corner of the field to the bottom-right corner.
//The only possible moves are right and down.
int Field::PathCost()
{
    //see a see
     int minPathSum(vector<vector<int>>& grid) {
      if (grid.empty()) return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<int>> memo= grid;
        
        for (int i = 1; i < rows; i++) {
           memo[i][0] +=memo[i-1][0];
        }
        
        for (int j = 1; j < cols; j++) {
           memo[0][j] +=memo[0][j-1];
        }
        
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
               memo[i][j] += min(memo[i-1][j], memo[i][j-1]);
            }
        }
        
        return memo[rows-1][cols-1];
    }
}
    
