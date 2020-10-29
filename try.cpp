#include "try.h"
#include <fstream>
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
       while(int i < line.length())
       {
       	  string temp = "";
          while(int i < line.size() && (line[i] >= 'a' && str[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z'))
          {
           temp += line[i];
           i++;
          }
          if(temp != "")
	  {
            keywords.push_back(temp);
          }
          i++;
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
        vector<string> file;
        while(int i < words.length())
        {
       	  string temp = "";
          while(int i < words.size() && (words[i] >= 'a' && str[i] <= 'z') || (words[i] >= 'A' && words[i] <= 'Z'))
          {
           temp += words[i];
           i++;
          }
          if(temp != "")
	  {
            file.push_back(temp);
	    countOfKeyword[temp]+=1;         
          }
          i++;
   	}

       text.push_back(file);
    }
    file.close();
   
}

bool KeywordsInFile::KeywordFound(string keyword)
{
     /**@return true if there exist keyword, otherwise return false **/
     return numOfKeyWord[keyword] >= 1;
}

int KeywordsInFile::KeywordInLine(string keyword, int line_number)
{
       int count = 0;
        for(int i=0; i<text[line].size();i++)
        {
            if(text[line][i]==keyword)
            count++;
        }
        return count;
}

int KeywordsInFile::TotalOccurrences(string keyword)
{
	return numOfKeyWord[keyword];
}
/**
void KeywordsInFile::operator<<(KeywordsInFile obj)
{
	unordered_map<string, int> :: iterator itr;
	cout<<"keywords in filename_with_keywords "<<endl;
        for(int i=0;i<obj.keywords.size();i++)
        {
            cout<<keywords[i]<<" ";
        }
        cout<<endl;
        cout<<"words in filename_with_text " <<endl;
        for(itr=obj.numOfKeyWord.begin(); itr!=obj.numOfKeyWord.end();itr++)
        {
            cout<<itr->first<<" " <<itr->second;
        }
        cout<<endl;
}
**/
