#include <iostream>

using namespace std;

int getMaxScore(int* scores,int begin,int end)
{
	if(begin > end)
	{
		int temp = begin;
		begin = end;
		end = temp;
	}
	int i=0;
	int max = -1;
	for(i=begin;i<=end;i++)
	{
		if(max<scores[i])
		{
			max = scores[i];
		}
	}
	return max;
}

int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		int* scores = new int[n];
		int i;
		for(i=0;i<n;i++)
		{
			cin>>scores[i];
		}
		for(i=0;i<m;i++)
		{
			char ch_operation;
			int istu,iscore;
			cin>>ch_operation;
			cin>>istu>>iscore;
			//索引值从1开始
			istu = istu - 1;
			if(ch_operation == 'Q')
			{
				iscore = iscore - 1;
				cout<<getMaxScore(scores,istu,iscore)<<endl;
			}else if(ch_operation == 'U')
			{
				//改变学生成绩的值
				scores[istu] = iscore;
			}
		}
		delete[] scores;
	}
	return 0;
}