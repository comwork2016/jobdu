#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string mergeText(vector<string>& words,int n_Blank,bool last=false)
    {
        int length = words.size()-1;
        int avg = 0;
        int rest = 0;
        if(length > 0)
        {
            avg = n_Blank / length;
            rest = n_Blank % length;
        }
        string result;
        for(int i=0; i<length; i++)
        {
            result = result.append(words[i]);
            if(last)//最后一行，只需要添加一个空格
            {
                result.append(" ");
            }
            else//其他行需要平均分配空格
            {
                if(i<rest)
                {
                    for(int j=0; j<avg+1; j++)
                    {
                        result.append(" ");
                    }
                }
                else
                {
                    for(int j=0; j<avg; j++)
                    {
                        result.append(" ");
                    }
                }
            }
        }
        result.append(words[length]);
        if(!last && length==0)
        {
            for(int i=0;i<n_Blank;i++)
            {
                result.append(" ");
            }
        }
        if(last)
        {
            for(int i=n_Blank-length;i>0;i--)
            {
                 result.append(" ");
            }
        }
        return result;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth)
    {
        vector<string> result;
        vector<string> tmp;
        int length=0;
        int blanks=0;
        for(int i=0; i<words.size(); i++)
        {
            string str = words[i];
            if(length + blanks + str.length() <= maxWidth)
            {
                length = length + str.length();
                tmp.push_back(str);
                if(length + blanks == maxWidth)
                {
                    blanks = maxWidth - length;
                    string res = mergeText(tmp,blanks);
                    result.push_back(res);
                    length = 0;
                    blanks = 0;
                    tmp.clear();
                }
                else
                {
                    blanks++;
                }
            }
            else // 长度超过最大值
            {
                blanks = maxWidth - length;
                string res = mergeText(tmp,blanks);
                result.push_back(res);
                tmp.clear();
                length = 0;
                blanks = 0;
                i--;
            }
        }
        //处理最后一行
        if(tmp.size()>0)
        {
            blanks = maxWidth - length;
            string res = mergeText(tmp,blanks,true);
            result.push_back(res);
        }
        return result;
    }
};

int main()
{
    Solution* s = new Solution();
    vector<string> words;
    words.push_back("Listen");
    words.push_back("to");
    words.push_back("many,");
    words.push_back("speak");
    words.push_back("to");
    words.push_back("a");
    words.push_back("few.");
    vector<string> result = s->fullJustify(words,6);
    for(int i=0; i<result.size(); i++)
    {
        cout<<"\"" <<result[i]<<"\""<<endl;
    }
    delete s;
}
