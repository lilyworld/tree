#include  "KeywordsInFile.h"
using namespace std;

KeywordsInFile::KeywordsInFile(const& string *filename_with_keywords, const& string *filename_with_text)
{
    ifstream fin(filename_with_keywords);
    if (fin.fail())
    {
	  cerr << "File cannot be opened for reading." << endl;
	  exit(1);
    }

    string line;
    while(fin.is_open() && getline(fin, line))
    {     
        vector<string> temp;
    	string str=" ";
    	for(int i=0; i<line.length(); i++)
    	{
		if((line[i]>='a' && line[i]<='z')||(line[i]>'A'&& line[i]<='Z'))
		{
	    	     str+=string(1,line[i]);
		}
		else
		{
		    Keywords.push_back(s);  
		    temp.push_back(str);
		    numOfKeyWord[str]+=1;
		    str=" ";
		}
   	}	

   	wordsInLine.push_back(temp);            
     } 

    fin.close();        
}

bool KeywordsInFile::KeywordFound(string keyword)
{
     /**@return true if there exist keyword, otherwise return false **/
     return numOfKeyWord[keyword] >= 1;
}

int KeywordsInFile::KeywordInLine(string keyword, int line_number)
{
      // If file is not having lesser number of lines, return -1;
      if(line_number > wordsInLine.size())
      {
   	  return -1;
      }
      // If keyword is not present in that line return 0.
      else if(wordsInLine[line_number-1].find(keyword) == wordsInLine[line_number-1].end())
      {
   	  return 0;
      }
      return wordsInLine[line_number-1][keyword];
}

int KeywordsInFile::TotalOccurrences(string keyword)
{
	return numOfKeyWord[keyword];
}

void KeywordsInFile::operator<<(KeywordsInFile obj)
{
	cout << "keywords in "<< filename_with_keywords << endl;
	for(int i=0; i<keywords.size(); i++)
	{
	    cout << keywords[i] << " ";   //list the keywords in keyword file
	}
	cout << endl;
	cout <<"keywords in "<< filename_with_text << endl;
	unordered_map<string, int> result;
	for(result=obj.numOfKeyWord.begin(); result!=obj.numOfKeyWord.end(); result++)
	{
	    cout<<result->first<<" " << result->second;   //print the keywords appear in text file and the times
	}
	cout << endl;
}
    
