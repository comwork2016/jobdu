/**
有n个数，两两组成二元组，差最小的有多少对呢？差最大呢？
*/
#pragma warning(disable:4097)
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n=0;
	while(cin>>n)
	{
		int i=0;
		int temp = 0;
		vector<int> vec_nums;
		for(i=0;i<n;i++)
		{
			cin>>temp;
			vec_nums.push_back(temp);
		}
		//快速排序
		sort(vec_nums.begin(),vec_nums.end());
		int min = vec_nums[0];
		int minCount = 1;
		int max = vec_nums[n-1];
		int maxCount = 0;
		int j=1;
		int minMinus = INT_MAX;
		int minMinusCount = 0;
		for(j=1;j<n;j++)
		{
			if(vec_nums[j] == min)
			{
				minCount++;
			}
			if(vec_nums[j] == max)
			{
				maxCount++;
			}
			if(vec_nums[j] - vec_nums[j-1] < minMinus)
			{
				minMinus = vec_nums[j] - vec_nums[j-1];
				minMinusCount = 1;
			}else if(vec_nums[j] - vec_nums[j-1] == minMinus)
			{
				minMinusCount++;
			}
			if(minMinus == 0)//如果多个值相等，则可以组合
			{
				for(i=j-2;i>=0 && vec_nums[i] == vec_nums[j];i--)
				{
					minMinusCount++;
				}
			}
		}
		cout<<minMinusCount<<" "<<(maxCount*minCount)<<endl;
	}
	return 0;
}