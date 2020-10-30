#include "KeywordsInFile.h"
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
      
    }
     
     for(auto i: text)
     {
	   if(countOfKeyword.find(i) == countOfKeyword.end())
	   {
	       countOfKeyword[i] = 1;
	   }
	   // Incrementing count of words found in line.
	   else
	   {
	       countOfKeyword[i] += 1;
	   }
	   
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
      int count =0;
      for(int i=0; i<text[line_number-1].size(); i++)
      {
	    if(text[line_number].find(keyword))
	    {
		    count+=1;
	    }
      }
      return count;
}

int KeywordsInFile::TotalOccurrences(string keyword)
{
	return countOfKeyword[keyword];
}

ostream KeywordsInFile::operator<<(ostream &output, KeywordsInFile &obj)
{
	unordered_map<string, int> :: iterator itr;
	output<<"keywords in filename_with_keywords "<<endl;
	for(itr = obj.keyword.begin(); itr != obj.keyword.end(); ++itr)
	{
   		cout << *itr << ", ";
        }
        cout<<endl;
	
	// Priting keywords in text file.
	output << "Keywords present in text file: \n";
	for(itr = obj.text.begin(); itr != obj.text.end(); ++itr)
	{
   		if(obj.keywords[*itr])
		{
       		     cout << *itr << ", ";
		}
        }

        cout<<endl;
	return output;
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


    cout<<file;

    //should print 3 for line 3 (4 in total text file)
    std::cout << file.KeywordInLine("lol", 3) << std::endl;
}
