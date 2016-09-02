#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

class Solution
{

public:

    void mergeNode(stack<string>& s,string node)
    {
        if(node == "#")
        {
            while(s.size()>=2 && s.top() == "#")
            {
                s.pop();
                s.pop();
            }
        }
        s.push(node);
    }

    bool isValidSerialization(string preorder)
    {
        stack<string> s;
        int i = 0;
        int len = preorder.length();
        size_t pos = preorder.find(',',i);
        string node = "";
        if(pos == string::npos)
        {
            pos = len;
            node = preorder;
        }
        while(pos<len)//split string
        {
            if(s.size()==1 && s.top()=="#")
            {
                return false;
            }
            node = preorder.substr(i,pos-i);
            mergeNode(s,node);
            i = pos+1;
            pos = preorder.find(',',i);
            if(pos == string::npos)//last node
            {
                node = preorder.substr(i);
                break;
            }
        }
        mergeNode(s,node);
        if(s.size()==1 && s.top()=="#")
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution* s = new Solution();
    string str = "#";
    cout << s->isValidSerialization(str) << endl;
    return 0;
}
