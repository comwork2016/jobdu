/**
给定一个长度为n的数列[w1,w2...wn]，从数列中选取k个数值，要求是k个数值的距离不超过d。
问：怎样选取k个数，使这k个数的乘积最大。

  每个输入包含 1 个测试用例。每个测试数据的第一行包含一个整数 n (1 <= n <= 50)，表示学生的个数，接下来的一行，包含 n 个整数，按顺序表示每个学生的能力值 ai（-50 <= ai <= 50）。接下来的一行包含两个整数，k 和 d (1 <= k <= 10, 1 <= d <= 50)。
  
    思路：
	cost[i][j]：表示选中第i个数作为结果的k个数中的第j个乘数的乘积的值。
	则：cost[i][j] = w[i]*max{cost[i-d][j-1],cost[i-d+1][j-1].....,cost[i-1][j-1]}
	
	  path[i][j]：表示选中第i个数作为结果的k个数中的第j个乘数的前一个乘数。
*/
#include <stdio.h>
#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

//typedf long long _int64;必须使用64位数据，否则会导致溢出

/**
动态规划方法求解最大乘积
*/
_int64 GetMaxMultiplier(int* weight,int n,int k,int d,int* muls)
{
	int i;
    //初始化状态函数 正数和负数最大值
    _int64** cost = new _int64*[n];
	_int64** costn = new _int64*[n];
    //保存乘数信息
    int** path = new int*[n];
	int** pathn = new int*[n];
    for(i=0;i<n;i++)
    {
        cost[i] = new _int64[k];
        costn[i] = new _int64[k];
        path[i] = new int[k];
        pathn[i] = new int[k];
    }
    //从第一个数开始计算乘积数值，并保存
    for(i=0;i<n;i++)
    {
		//将第i个数作为第0个乘数的乘积为weight[i]
		if(weight[i] >= 0)
		{
			cost[i][0] = weight[i];
			costn[i][0] = 0;
		}
		else
		{
			cost[i][0] = 0;
			costn[i][0] = weight[i];
		}
        for(int j=1;j<=i&&j<k;j++) //第i个数不能作为大于i和k的乘数
        {
            //寻找前面d个距离之内，第j-1个乘数的最大值
            _int64 maxMul = 0;
			_int64 maxMuln = 0;
            int lastPath = -1;
			int lastPathn = -1;
            //寻找前j-1个乘数的积的最大值
            for(int m=1;m<=d;m++)
            {
                if(i-m>=0 && i-m >= j-1)
                {
                    if(maxMul < cost[i-m][j-1]) //寻找正数最大值
                    {
                        maxMul = cost[i-m][j-1];
                        lastPath = i-m;
                    }
					if(maxMuln > costn[i-m][j-1])//寻找负数最大值
					{
                        maxMuln = costn[i-m][j-1];
                        lastPathn = -(i-m);
					}
                }
            }
			if(weight[i] >=0)
			{
				cost[i][j] = weight[i] * maxMul;
				path[i][j] = lastPath;
				costn[i][j] = weight[i] * maxMuln;
				pathn[i][j] = lastPathn;
			}else
			{
				cost[i][j] = weight[i] * maxMuln;
				path[i][j] = lastPathn;
				costn[i][j] = weight[i] * maxMul;
				pathn[i][j] = lastPath;
			}
        }
    }
	
    //寻找cost[i][k-1]的最大值
    _int64 maxMultiplier = 0;
    int maxLastPath = k-1;
    for(i=k-1;i<n;i++)
    {
		if(cost[i][k-1] > maxMultiplier)
		{
			maxMultiplier = cost[i][k-1];
			maxLastPath = i;
		}
	}
	
	//保存最大的乘数信息
	stack<int> s;
	int m = k-1;
	for(m=k-1;m>=0;m--)
	{
		if(maxLastPath >=0)
		{
			s.push(maxLastPath);
			maxLastPath = path[maxLastPath][m];	
		}else
		{
			s.push(-maxLastPath);
			maxLastPath = pathn[-maxLastPath][m];
		}
	}
	
	i=0;
	while(!s.empty())
	{
		muls[i++] = s.top();
		s.pop();
	}
	
	for(i=0;i<n;i++)
	{
		delete[] cost[i];
		delete[] costn[i];
		delete[] path[i];
		delete[] pathn[i];
	}
	delete[] cost;
	delete[] costn;
	delete[] path;
	delete[] pathn;
	return maxMultiplier;
}

void PrintResult(_int64 maxMultiplier, int k, int* weight, int* muls)
{
	int i=0;
	for(i=0;i<k-1;i++)
	{
		cout<<weight[muls[i]]<<" * ";
	}
	printf("%d = %I64d\n",weight[muls[k-1]],maxMultiplier);
}

int main()
{
    int n=0;
    int k=0;
    int d=0;
    while(cin>>n)
    {
        int* weight = new int[n];
		int i;
        for(i=0;i<n;i++)
        {
            cin>>weight[i];
        }
		cin>>k>>d;
        int* muls = new int[k];
        _int64 maxMultiplier = GetMaxMultiplier(weight,n,k,d,muls);
		printf("%I64d\n",maxMultiplier);
        PrintResult(maxMultiplier, k, weight, muls);
        delete[] weight;
    }
	return 0;
}
