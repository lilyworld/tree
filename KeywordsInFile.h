#ifndef KEYWORDSINFILE_H
#define	KEYWORDSINFILE_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>

class KeywordsInFile
{
  public:
    KeywordsInFile() = delete; // default constructor
   
    /** Parameterized constructor
     @param filename_with_keywords: is a name of a plain text file that contains the list of keywords.
     @param filename_with_text: is a name of a plain text file that contains the text where the keywords must be found.  **/
    KeywordsInFile(const std::string& filename_with_keywords, const std::string& filename_with_text);
  
    /**@returns true if the specified keyword was found in the text. Returns false otherwise. **/
    bool KeywordFound(std::string keyword);
  
    /**@returns the number of times the specified keyword was seen in  the specified line of the text. **/
    int KeywordInLine(std::string keyword, int line_number);
  
    /**@returns the total number of the occurrences of the given keyword in the text. **/
    int TotalOccurrences(std::string keyword);
  
    /** that allows you to use object of your class with cout. **/
    std::ostream &operator << (std::ostream &output, KeywordsInFile &obj);
  
 private:
    std::vector<std::string> keywords;  // 'keywords' will store all keywords in filename_with_keywords
    std::unordered_map<std::string, int> countOfKeyword;  // 'countOfKeyword' will keep count of all keywords.
    std::vector<std::string> text;    // store words in text
    
  
};
  
#endif

