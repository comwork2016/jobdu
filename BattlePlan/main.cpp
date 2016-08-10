/**
��i����սʿ��ħ�����Կ��Ƶ���֮�����ߵļ���ΪSi(Si�е�ÿ��Ԫ������[0,5])��
S0={01},S1={23}��������Ϊ0�Ŀ�սʿ��ħ�����Կ��Ʊ��Ϊ0�ͱ��Ϊ1����֮�����ߣ����Ϊ1�Ŀ�սʿ��ħ�����Կ��Ʊ��Ϊ2�ͱ��Ϊ3����֮�����ߣ��������ַ�����02,03,12,13��
02---�����һ����սʿ������Ϊ0�������ߣ��ڶ�����սʿ������Ϊ2�������ߣ�
03---�����һ����սʿ������Ϊ0�������ߣ��ڶ�����սʿ������Ϊ3�������ߣ�
12---�����һ����սʿ������Ϊ1�������ߣ��ڶ�����սʿ������Ϊ2��������;
13---�����һ����սʿ������Ϊ1�������ߣ��ڶ�����սʿ������Ϊ3��������;
S0={01},S1={01}��������Ϊ0�Ŀ�սʿ��ħ�����Կ��Ʊ��Ϊ0�ͱ��Ϊ1����֮�����ߣ����Ϊ1�Ŀ�սʿ��ħ�����Կ��Ʊ��Ϊ0�ͱ��Ϊ1����֮�����ߣ��������ַ�����01,10��

*/

#pragma warning(disable: 4786)

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int planCount(vector<string> vec)
{
	if(vec.size() == 1)//ֻ��һ����սʿʱ�����ؼ�����Ԫ�صĸ���
	{
		string str = vec[0];
		return str.length();
	}
	string str = vec[0];//��һ����սʿ�����е�Ԫ��
	int len1 = str.length();
	int count = 0;
	for(int i=0;i<len1;i++)
	{
		//���ڵ�һ����սʿ�е�ÿһ��Ԫ�أ���ʣ�µļ�����ȥ����Ԫ��
		char plan = str[i];
		vector<string> vec_Next;
		for(int j=1;j<vec.size();j++)
		{
			string str_Next = vec[j];
			size_t st = str_Next.find(plan);
			if( st != string::npos)
			{
				str_Next = str_Next.erase(st,1);
			}
			vec_Next.push_back(str_Next);
		}
		int count_Next = planCount(vec_Next);
		count = count+count_Next;
	}
	return count;
}

int main()
{
	int n;
	while(cin>>n)
	{
		string str;
		vector<string> vec;
		for(int i=0;i<n;i++)
		{
			cin>>str;
			vec.push_back(str);
		}
		cout<<planCount(vec)<<endl;
	}
	return 0;
}