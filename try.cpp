#include  "try.h"
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
        vector<string> temp = Words(line);
    	for(auto i : temp)
	{
		keywords[i]++;
	}
     } 
    fin.close();     

    ifstream fin(filename_with_text);
    if (fin.fail())
    {
	 cerr << "File cannot be opened for reading." << endl;
	 exit(1);
    }
    std::string words;
    while(fin.is_open() && getline(fin, words)) 
    {
        vector<string> str = Words(words);
        unordered_map<string, int> temp;
        for(auto i: str)
	{
	   // If word is not present, intialize its count with '0'.
	   if(numOfKeyWord.find(i) == numOfKeyWord.end())
	   {
	       numOfKeyWord[i] = 0;
	   }
	   // Incrementing count of words found in line.
	   else
	   {
	       numOfKeyWord[i] ++;
	   }
	   // temp will count occurrence of each word in a particular line.
	   if(temp.find(i) == temp.end())
	   {
	       temp[i] = 0;
	   }
	   else
	   {
	       temp[i] ++;
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
