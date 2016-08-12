/**
给定一个字符串s，你可以从中删除一些字符，使得剩下的串是一个回文串。如何删除才能使得回文串最长呢？
思路：求原字符串和其反串的最大公共子串的长度，然后用原字符串的长度减去这个最大公共子串的长度就得到了最小编辑长度。
*/
#include <iostream>
#include <string>

using namespace std;

int lcs(string str1,string str2)
{
	int length1 = str1.length();
	int length2 = str2.length();
	int** ppn_lcs;
    ppn_lcs = new int*[length1];//save lcs length of str1[0,i] and str2[0,j]
	int i=0;
	int j=0;
    for(i=0; i<length1; i++)
    {
        ppn_lcs[i] = new int[length2];
        for(int j=0; j<length2; j++)
        {
            ppn_lcs[i][j] = 0;
        }
    }
	for(i=0;i<length1;i++)
	{
		for(j=0;j<length2;j++)
		{
			if(i==0 || j==0)
			{
				if(str1[i] == str2[j])
				{
					ppn_lcs[i][j] = 1;
				}else
				{
					if(i>0)
					{
						ppn_lcs[i][j] = ppn_lcs[i-1][j];
					}
					if(j>0)
					{
						ppn_lcs[i][j] = ppn_lcs[i][j-1];
					}
				}
			}else
			{
				if(str1[i] == str2[j])//两个字符相等，则最大长度在左方和上方+1
				{
					ppn_lcs[i][j] = ppn_lcs[i-1][j-1] +1;
				}
				else if(ppn_lcs[i][j-1] > ppn_lcs[i-1][j])
				{
					ppn_lcs[i][j] = ppn_lcs[i][j-1];
				}
				else
				{
					ppn_lcs[i][j] = ppn_lcs[i-1][j];
				}
			}
		}
	}
	return ppn_lcs[length1-1][length2-1];
}

int main()
{
	string str;
	while(cin>>str)
	{
		string str_Reversed;
		int i=0;
		int length = str.length();
		for(i=0;i<length;i++)//得到反串
		{
			str_Reversed.append(1,str[length-1-i]);
		}
		cout<<(length - lcs(str,str_Reversed))<<endl;
	}
	return 0;
}

