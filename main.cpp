#include <iostream>
#include "KeywordsInFile.h"
#include "KeywordsInFile.cpp"
using namespace std;

int main()
{
    string keyFile = "keyword.txt";
    string txtFile = "text_file.txt";
    KeywordsInFile file(keyFile, txtFile);

    //should return 0
    cout << "KEYWORDFOUND()" << endl;
    cout << file.KeywordFound("night") << endl;

    //should return 6
    cout << "TOTALOCCURENCES()" << endl;
    cout << file.TotalOccurences("lazy") << endl;

    //should print "keyword:occurences" for each keyword
    cout << "OS>>" << endl;
    cout << file << endl;

    //should print 3 for line 3 (4 in total text file)
    cout << file.KeywordInLine("lol", 3) << endl;
}
