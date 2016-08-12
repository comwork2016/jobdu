/**
第i名狂战士的魔法可以克制的天之驱逐者的集合为Si(Si中的每个元素属于[0,5])。
S0={01},S1={23}，代表编号为0的狂战士的魔法可以克制编号为0和编号为1的天之驱逐者，编号为1的狂战士的魔法可以克制编号为2和编号为3的天之驱逐者，共有四种方案：02,03,12,13。
02---代表第一个狂战士负责编号为0的驱逐者，第二个狂战士负责编号为2的驱逐者；
03---代表第一个狂战士负责编号为0的驱逐者，第二个狂战士负责编号为3的驱逐者；
12---代表第一个狂战士负责编号为1的驱逐者，第二个狂战士负责编号为2的驱逐者;
13---代表第一个狂战士负责编号为1的驱逐者，第二个狂战士负责编号为3的驱逐者;
S0={01},S1={01}，代表编号为0的狂战士的魔法可以克制编号为0和编号为1的天之驱逐者，编号为1的狂战士的魔法可以克制编号为0和编号为1的天之驱逐者，共有两种方案：01,10。

*/

#pragma warning(disable: 4786)

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int planCount(vector<string> vec)
{
	if(vec.size() == 1)//只有一个狂战士时，返回集合中元素的个数
	{
		string str = vec[0];
		return str.length();
	}
	string str = vec[0];//第一个狂战士集合中的元素
	int len1 = str.length();
	int count = 0;
	for(int i=0;i<len1;i++)
	{
		//对于第一个狂战士中的每一个元素，在剩下的集合中去掉该元素
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