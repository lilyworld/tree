#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<string> Words(string str) {
   vector<string> word;
   int i = 0;
   while(i < str.size()) {
       string temp = "";
       while(i < str.size() && (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
       {
           temp += str[i];
           i++;
       }
       if(temp != "") {
           word.push_back(temp);
       }
       i++;
   }
   return word;
}


class KeywordsInFile {
public:
   // Instance varibales.
   // 'countOfKeyWord' will keep count of all keywords.
   unordered_map<string, int> countOfKeyWord;
   // 'wordsInLine' will keep count of words in a particular line.
   vector<unordered_map<string, int> > wordsInLine;
   // 'keywords' will store all keywords in 'keywords_file.txt' file.
   unordered_map<string, bool> keywords;
   // 'words' will contain all words present in text file.
   unordered_set<string> words;
   // 'key' will contain all keywords present in keywords file.
   unordered_set<string> key;

   // Constructor, reads files and builds instacne variables.
   KeywordsInFile(string filename_with_keywords, string filename_with_text) {
       ifstream file;
       // Opens keywords file
       file.open(filename_with_keywords);
       if(file.is_open()) {
           string str;
           regex r ("[^a-zA-Z]");
           // Reading file line by line.
           // using regular expression to fetch all keywords.
           while(getline(file, str)) {
               // Breaking string 'str' into words.
               vector<string> strings = Words(str);
               for(auto var: strings) {
                   keywords[var] = true;
                   key.insert(var);
               }
           }
           file.close();
       }
       // Opening text file and reading it line by line.
       int line = 0;
       file.open(filename_with_text);
       if(file.is_open()) {
           string str;
           regex r ("[^a-zA-Z]");
           // Again using regular expression for fetching words
           while(getline(file, str)) {
               // Breaking strig 'str' into words.
               vector<string> strings = Words(str);
               unordered_map<string, int> temp;
               for(auto var: strings) {
                   // If word is not present, intialize its count with '0'.
                   if(countOfKeyWord.find(var) == countOfKeyWord.end()) {
                       countOfKeyWord[var] = 1;
                   }
                   // Incrementing count of words found in line.
                   else {
                       countOfKeyWord[var] += 1;
                   }
                   // temp will count occurrence of each word in a particular line.
                   if(temp.find(var) == temp.end()) {
                       temp[var] = 1;
                   }
                   else {
                       temp[var] += 1;
                   }
                   words.insert(var);
               }
              
               wordsInLine.push_back(temp);
           }
           // cout << line << '\n';
           file.close();
       }
   }

   // This checks 'words' keyword is present in text file or not.
   bool KeywordFound(string word) {
       return (countOfKeyWord.find(word) != countOfKeyWord.end());
   }

   // This function returs count of 'word' in a particular line.
   int KeywordInLine(string word, int line) {
       // If file is not having lesser number of lines, return -1;
       if(line > wordsInLine.size()) {
           return -1;
       }
       // If word is not present in that line return 0.
       else if(wordsInLine[line-1].find(word) == wordsInLine[line-1].end()) {
           return 0;
       }
       return wordsInLine[line-1][word];
   }

   // This function returns total count of a 'word' in text file.
   int TotalOccurrences(string word) {
       if(countOfKeyWord.find(word) == countOfKeyWord.end()) {
           return 0;
       }
       return countOfKeyWord[word];
   }

   // Operator overloading.
   friend ostream & operator << (ostream &out, KeywordsInFile &object);
};

ostream & operator << (ostream &out, KeywordsInFile &object)
{
   // Printing words in text file
out << "\nWords present in text file: \n";
unordered_set<string> :: iterator itr;
for(itr = object.words.begin(); itr != object.words.end(); ++itr) {
   cout << *itr << ", ";
}
cout << "\n\n";

// Printing words in keyword file.
out << "Key-Words present in keywords text file: \n";
for(itr = object.key.begin(); itr != object.key.end(); ++itr) {
   cout << *itr << ", ";
}
cout << "\n\n";

// Priting keywords in text file.
out << "Key-Words present in text file: \n";
for(itr = object.words.begin(); itr != object.words.end(); ++itr) {
   if(object.keywords[*itr]){
       cout << *itr << ", ";
   }
}
cout << "\n\n";
return out;
}

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
