#include<iostream>
#include"KeywordsInFile.h"
#include"KeywordsInFile.cpp"

using namespace std;

int main(void) {
   // 'text_file' will take user input for text file.
   // 'keywords_file' wwill take user input for keyword file.
   string text_file, keywords_file;
   cout << "Enter the file name of file containing keywords: ";
   cin >> keywords_file;
   cout << "Enter the file name of simple text file: ";
   cin >> text_file;

   // Creating object and initializing its instance variables.
   KeywordsInFile object(keywords_file, text_file);

   // Printing output for object.
   cout << object;
   return 0;
}
