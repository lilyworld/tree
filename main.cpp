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

    // INPUT 2
    input = { 1, 2, 5, 6, -4, 4, 10, 0, -2, -5, -4};
    expected = { 6, -4, 4, 10 };
    output = aProc.CutOutSilence(input, 5, 3);

    if (output != expected)
        std::cout << "bad CutOutSilence! failed on input 2." << std::endl;

    // INPUT 3
    input = { 1, 2, 5, 6, -4, 4, -2, -5, 10, 0, -4 };
    expected = { 1, 2, 5, 6, 10, 0, -4 };
    output = aProc.CutOutSilence(input, 5, 4);

    if (output != expected)
        std::cout << "bad CutOutSilence! failed on input 3." << std::endl;
}

int main()
{

    TestCutOutSilence();
    return 0;

}
