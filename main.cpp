#include <iostream>
#include "AudioProcessor.h"
#include "AudioProcessor.cpp"
using namespace std;

int main()
{
    AudioProcessor  processor;

    vector<short> input{ 1, 2, 5, 6, -4, 4, 10, 0, -2, -5, -4}; 
    vector<short> output;  
    short y=5;
    int x=3;

    output=processor.CutOutSilence(input, y, x);
    vector<short> expected = {6, -4, 4, 10 };
    if (output != expected)
        cout << "bad CutOutSilence! failed on input 3." << endl;
    if(output == expected)
        cout << "correct!" << endl;
    
    return 0;

}
