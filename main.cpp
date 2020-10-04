#include "SquareMatrix.h"
#include <iostream>
using namespace std;

int main(){
    int val =3;
    SquareMatrix<int> a;
    SquareMatrix<int> b(move (a))；
    SquareMatrix<int> c(a);
    a=b=c;
    a=a;
    a=move(c);
    a.resize(val);
    b.resize(val);
    for(int i=0; i<val; i++)
    {
        for(int j=0; j<val; j++)
        {
            a.at(i, j)=1;
            b.at(i, j)=1;
            cout << a.at(i, j) << " " << b.at(i, j) << " ";
        }
        cout << endl;
    }
    if(a==b)
    {
        cout << "equal" << endl;
    }
    cout << a.size() << endl;
    return 0;
}
