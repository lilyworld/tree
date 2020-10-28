#include<KeywordsInFile.h>
class KeywordsInFile
{
    public:
    vector<string> Keywords;
    unordered_map<string,int> store;
    vector<vector<string>> v;
    KeywordsInFile(const char *file filename_with_keywords,const char *filename_with_text)
    {
        int i;
        fstream newfile;
      
        newfile.open(filename_with_keywords,ios::in);
        if (newfile.is_open())
        {
            string tp;
            while(getline(newfile, tp))
            {
                string s="";
                for(i=0;i<tp.length();i++)
                {
                    if((tp[i]>='a'&&tp[i]<='z')||(tp[i]>'A'&&tp[i]<='Z'))
                    {
                        s+=string(1,tp[i]);
                    }
                    else
                    {
                        Keywords.push_back(s);
                        s="";
                    }
                }
            }
        }
        newfile.close();
      
        newfile.open(filename_with_text,ios::in);
        if(newfile.is_open())
        {
            string tp;
            while(getline(newfile, tp))
            {
                vector<string> v1;
                string s="";
                for(i=0;i<tp.length();i++)
                {
                    if((tp[i]>='a'&&tp[i]<='z')||(tp[i]>'A'&&tp[i]<='Z'))
                    {
                        s+=string(1,tp[i]);
                    }
                    else
                    {
                        v1.push_back(s);
                        store[s]+=1;
                        s="";
                    }
                }
                v.push_back(v1);
            }
        }
      
    }
    bool KeywordFound(string str)
    {
        if(stored[str]>=1)
        return true;
        return false;
    }
    int KeywordInLine(string str,int line)
    {
        int i,count;
        count=0;
        for(i=0;i<v[line].size();i++)
        {
            if(v[line][i]==str)
            count+=1;
        }
        return count;
    }
    int TotalOccurrences(string str)
    {
        return stored[str];
    }
    void operator<<(KeywordsInFile obj)
    {
        int i;
        cout<<"keywords in "<<filename_with_keywords<<endl;
        for(i=0;i<keywords.size();i++)
        {
            cout<<keywords[i]<<" ";
        }
        cout<<endl;
        cout<<"words in "<<filename_with_text<<endl;
        for(it=stored.begin();it!=stored.end();it++)
        {
            cout<<it->first<<" ";
        }
        cout<<endl;
    }
};
