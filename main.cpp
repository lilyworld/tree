#include <iostream>
#include "AudioProcessor.h"
#include "AudioProcessor.cpp"
using namespace std;

int main()
{
    AudioProcessor  processor;

    vector<short> input{1, 2, 5, 6, -4, 4, -2, -5, 10, 0, -4}; 
    vector<short> output;  
    short y=5;
    int x=4;

    output=processor.CutOutSilence(input, y, x);
    /**for(int i=0; i<compressedAudio.size(); i++)
    {
        cout << compressedAudio[i]<< ", ";
    }**/
    //couinput = { 1, 2, 5, 6, -4, 4, -2, -5, 10, 0, -4 };
    vector<short> expected = { 1, 2, 5, 6, 10, 0, -4 };
    if (output != expected)
        std::cout << "bad CutOutSilence! failed on input 3." << std::endl;
    return 0;

}
