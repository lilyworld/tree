#include "try.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


KeywordsInFile::KeywordsInFile(const string& filename_with_keywords, const string& filename_with_text)
{
    ifstream fin(filename_with_keywords);
    if (fin.fail())
    {
	  cerr << "File cannot be opened for reading." << endl;
	  exit(1);
    }

    std::string line;
    while(fin.is_open() && getline(fin, line))
    {     
       for(int i=0; i<line.size(); i++)
       {
       	  string temp = "";
          if((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z'))
          {
            temp += line[i];
            i++;
          }
          else
	  {
            keywords.push_back(temp);
	    temp =" ";
          }
  
   	}
    }
    fin.close();     

    ifstream file(filename_with_text);
    if (file.fail())
    {
	 cerr << "File cannot be opened for reading." << endl;
	 exit(1);
    }
    std::string words;
    while(file.is_open() && getline(file, words)) 
    {
        for(int i=0; i<words.size(); i++)
        {
       	  string temp = "";
          if((words[i] >= 'a' && words[i] <= 'z') || (words[i] >= 'A' && words[i] <= 'Z'))
          {
           temp += words[i];
           i++;
          }
          else
	  {
            text.push_back(temp);
	    temp = " ";
          }
      
    }
     unordered_map<string, int> xxx;
     for(auto i: text)
     {
	   if(countOfKeyWord.find(i) == countOfKeyWord.end())
	   {
	       countOfKeyWord[i] = 1;
	   }
	   // Incrementing count of words found in line.
	   else
	   {
	       countOfKeyWord[i] += 1;
	   }
	   // temp will count occurrence of each word in a particular line.
	   if(xxx.find(i) == xxx.end())
	   {
	       xxx[i] = 1;
	   }
	   else
	   {
	       xxx[i] += 1;
	   }
     }

       //wordsInLine.push_back(xxx);
    }
    file.close();
   
}

bool KeywordsInFile::KeywordFound(string keyword)
{
     /**@return true if there exist keyword, otherwise return false **/
     return countOfKeyword[keyword] >= 1;
}

int KeywordsInFile::KeywordInLine(string keyword, int line_number)
{
       int count = 0;
        for(int i=0; i<text[line_number-1].size(); i++)
        {
            while(text[line_number-1].find(keyword))
	    {
            	count++;
	    }
        }
        return count;
}

int KeywordsInFile::TotalOccurrences(string keyword)
{
	return countOfKeyword[keyword];
};

void KeywordsInFile::operator<<(KeywordsInFile obj)
{
	unordered_map<string, int> :: iterator itr;
	cout<<"keywords in filename_with_keywords "<<endl;
        for(int i=0; i<obj.keywords.size();i++)
        {
            cout<<keywords[i]<<" ";
        }
        cout<<endl;
        cout<<"words in filename_with_text " <<endl;
        for(int i=0; i<obj.text.size(); i++)
        {
            cout<<text[i]<<" ";
        }
        cout<<endl;
}

int main()
{
     // 'text_file' will take user input for text file.
   // 'keywords_file' wwill take user input for keyword file.
   string text_file, keywords_file;
   cout << "Enter the file name of file containing keywords: ";
   cin >> keywords_file;
   cout << "Enter the file name of simple text file: ";
   cin >> text_file;
	
    KeywordsInFile file(keywords_file, text_file);

    //should return 0
    std::cout << "KEYWORDFOUND()" << std::endl;
    std::cout << file.KeywordFound("night") <<std::endl;

    //should return 6
    std::cout << "TOTALOCCURENCES()" << std::endl;
    std::cout << file.TotalOccurrences("lazy") << std::endl;


   // cout<<file;

    //should print 3 for line 3 (4 in total text file)
    std::cout << file.KeywordInLine("lol", 3) << std::endl;
}
