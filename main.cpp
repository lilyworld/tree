#include <iostream>
#include "AudioProcessor.h"
#include "AudioProcessor.cpp"
using namespace std;

void TestCutOutSilence()
{
    AudioProcessor aProc;

    // INPUT 1
    std::vector<short> input{ 1, 2, 5, 6, 10, 0, -2, -5, -5, -8 };
    std::vector<short> expected{ 1, 2, 5, 6, 10, -8 };
    auto output{ aProc.CutOutSilence(input, 5, 4) };

    if (output != expected)
        std::cout << "bad CutOutSilence! failed on input 1." << std::endl;
    else
        cout << "correct!"<<endl;

    // INPUT 2
    vector<short> input2 = { 1, 2, 5, 6, -4, 4, 10, 0, -2, -5, -4};
    vector<short> expected2 = { 6, -4, 4, 10 };
    output2 = aProc.CutOutSilence(input2, 5, 3);

    if (output2 != expected2)
        std::cout << "bad CutOutSilence! failed on input 2." << std::endl;
     else
        cout << "correct!"<<endl;

    // INPUT 3
    vector<short> input3 = { 1, 2, 5, 6, -4, 4, -2, -5, 10, 0, -4 };
    vector<short> expected3 = { 1, 2, 5, 6, 10, 0, -4 };
    output3 = aProc.CutOutSilence(input3, 5, 4);

    if (output3 != expected3)
        std::cout << "bad CutOutSilence! failed on input 3." << std::endl;
     else
        cout << "correct!"<<endl;
}

int main()
{

    TestCutOutSilence();
    return 0;

}
