/**
����һ���ַ���s������Դ���ɾ��һЩ�ַ���ʹ��ʣ�µĴ���һ�����Ĵ������ɾ������ʹ�û��Ĵ���أ�
˼·����ԭ�ַ������䷴������󹫹��Ӵ��ĳ��ȣ�Ȼ����ԭ�ַ����ĳ��ȼ�ȥ�����󹫹��Ӵ��ĳ��Ⱦ͵õ�����С�༭���ȡ�
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
				if(str1[i] == str2[j])//�����ַ���ȣ�����󳤶����󷽺��Ϸ�+1
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
		for(i=0;i<length;i++)//�õ�����
		{
			str_Reversed.append(1,str[length-1-i]);
		}
		cout<<(length - lcs(str,str_Reversed))<<endl;
	}
	return 0;
}

