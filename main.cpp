#include <iostream>
#include "KeywordsInFile.h"
#include "KeywordsInFile.cpp"
using namespace std;

int main()
{
    std::string keyFile = "keyword.txt";
    std::string txtFile = "text_file.txt";
    KeywordsInFile file(keyFile, txtFile);

    //should return 0
    std::cout << "KEYWORDFOUND()" << std::endl;
    std::cout << file.KeywordFound("night") <<std::endl;

    //should return 6
    std::cout << "TOTALOCCURENCES()" << std::endl;
    std::cout << file.TotalOccurrences("lazy") << std::endl;

    //should print "keyword:occurences" for each keyword
    //std::cout << "OS>>" << std::endl;
    //std::cout << file << std::endl;

    //should print 3 for line 3 (4 in total text file)
    std::cout << file.KeywordInLine("lol", 3) << std::endl;
}
