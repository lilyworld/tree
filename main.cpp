#include <iostream>
#include "KeywordsInFile.h"

int main()
{
    string keyFile = "your\\dir\\goes\\here\\key.txt";
    string txtFile = "your\\dir\\goes\\here\\text.txt";
    KeywordsInFile file(keyFile, txtFile);

    //should return 0
    cout << "KEYWORDFOUND()" << endl;
    cout << file.KeywordFound("night") << endl;

    //should return 6
    cout << "TOTALOCCURENCES()" << endl;
    cout << file.totalOccurences("lazy") << endl;

    //should print "keyword:occurences" for each keyword
    cout << "OS>>" << endl;
    cout << file << endl;

    //should print 3 for line 3 (4 in total text file)
    cout << file.KeywordInLine("lol", 3) << endl;
}
