#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int result=0;
        bool neg = false;
        bool overflow = false;
        const int int_max  = ((unsigned int)1<<(sizeof(int)*8-1)) - 1;
        int start = 0;
        for(int i=0;i<str.length();i++)
        {
            int tmp = str[i] - '0';
            if(i== start && tmp == ' ' - '0')
            {
                start++;
                continue;
            }
            if(i==start && str[start]=='+')
            {
                continue;
            }else if(i==start && str[start]=='-')
            {
                neg = true;
            }else
            {
                if(tmp < 0 || tmp > 9)
                {
                    break;
                }
                if(result > int_max/10 || result*10 > int_max - tmp)//Òç³öÁË
                {
                    overflow = true;
                    break;
                }
                result = result*10 + tmp;
                cout<<result<<endl;
            }
        }
        if(overflow)
        {
            cout<<"overflow"<<endl;
            if(neg == false)
            {
                result = ((unsigned int)1<<(sizeof(int)*8-1))-1;
            }else
            {
                result = ((unsigned int)1<<(sizeof(int)*8-1));
            }
        }
        else if(neg)
        {
            result = -result;
        }
        return result;
    }
};

int main()
{
    Solution* s = new Solution();
    string str;
    while(getline(cin,str))
    {
        cout << s->myAtoi(str) << endl;
    }
    delete s;
    return 0;
}
