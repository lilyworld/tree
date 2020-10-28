
#include<iostream>
#include<string>
using namespace std;

class KeywordsInFile
{
  pubilc:
    KeywordsInFile(); // default constructor
    KeywordsInFile(filename_with_keywords, filename_with_text);
    bool KeywordFound(string keyword);
    int KeywordInLine(string keyword, int line_number);
    int TotalOccurrences(string keyword);
    void operator<<(KeywordsInFile obj);
  
  private:
    
