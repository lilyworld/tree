#include <iostream>
#include "Field.h"
#include "Field.cpp"
using namespace std;

int main()
{
    /**
    void printMatrix(const vector<vector<int>> &v)
    {
        for(int i = 0; i < v.size(); i++) {
            for(int j = 0; j < v[0].size(); j++) {
                cout << v[i][j] << " ";
            }
            cout << "\n";
        }
    }
    **/
    
    vector<vector<int>> v(5, vector<int> (6));
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 6; j++)
            v[i][j] = j + 1;
            
    // Prints the 2D vector 
    //printMatrix(v);
    
    
    // Invokes the first constructor
    Field field1 = Field(v);
    cout << "\nField 1 \n";
    cout << field1.Weight(1,2,4,0) << "\n";
    
    cout << "result is 1: " << field1.Weight(0,0,0,0) << "\n";
    cout << "result is 105: " <<field1.Weight(0,0,5,4) << "\n";
    cout <<"result is 5: " << field1.Weight(4,4,4,4) << "\n";
    cout <<"result is 25: " << field1.Weight(4,0,4,4) << "\n";
    cout <<"result is 24: " << field1.Weight(2,1,0,4) << "\n";
    cout <<"result is 21: " << field1.Weight(0,2,5,2) << "\n";
    cout <<"result is 36: " << field1.Weight(2,2,4,4) << "\n";
    
    cout << field1.PathCost() << "\n";
    
    Field field2 ({{2,2,2},{2,2,2},{2,2,2}});
    cout << "result is 10: " <<field2.PathCost() << "\n";
    
    return 0;

}
