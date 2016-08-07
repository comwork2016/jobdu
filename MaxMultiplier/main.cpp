/**
    给定一个长度为n的数列[w1,w2...wn]，从数列中选取k个数值，要求是k个数值的距离不超过d。
    问：怎样选取k个数，使这k个数的乘积最大。

    思路：
        cost[i][j]：表示选中第i个数作为结果的k个数中的第j个乘数的乘积的值。
        则：cost[i][j] = w[i]*max{cost[i-d][j-1],cost[i-d+1][j-1].....,cost[i-1][j-1]}

        path[i][j]：表示选中第i个数作为结果的k个数中的第j个乘数的前一个乘数。
*/
#include <iostream>
#include <stack>

using namespace std;

/**
    动态规划方法求解最大乘积
*/
int GetMaxMultiplier(int* weight,int n,int k,int d,int* muls)
{
	int i;
    //初始化状态函数
    int** cost = new int*[n];
    //保存乘数信息
    int** path = new int*[n];
    for(i=0;i<n;i++)
    {
        cost[i] = new int[k];
        path[i] = new int[k];
    }
    //从第一个数开始计算乘积数值，并保存
    for(i=0;i<n;i++)
    {
        cost[i][0] = weight[i];//将第i个数作为第0个乘数的乘积为weight[i]
        for(int j=1;j<=i&&j<k;j++) //第i个数不能作为大于i和k的乘数
        {
            //寻找前面d个距离之内，第j-1个乘数的最大值
            int maxMul = 0;
            int lastPath = 0;
            //寻找前j-1个乘数的积的最大值
            for(int m=1;m<=d;m++)
            {
                if(i-m>=0 && i-m >= j-1)
                {
                    if(maxMul < cost[i-m][j-1])
                    {
                        maxMul = cost[i-m][j-1];
                        lastPath = i-m;
                    }
                }
            }
            cost[i][j] = weight[i] * maxMul;
            path[i][j] = lastPath;
        }
    }

    //寻找cost[i][k-1]的最大值
    int maxMultiplier = 0;
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
    s.push(maxLastPath);
    int m = k-1;
    while(m>0)
    {
        s.push(path[maxLastPath][m]);
        maxLastPath = path[maxLastPath][m];
        m--;
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
        delete[] path[i];
    }
    delete[] cost;
    delete[] path;
    return maxMultiplier;
}

void PrintResult(int maxMultiplier, int k, int* weight, int* muls)
{
	cout<<"max multiplier: ";
	cout<<"max multiplier: ";
	int i=0;
	for(i=0;i<k-1;i++)
	{
		cout<<weight[muls[i]]<<" * ";
	}
	cout<<weight[muls[k-1]]<<" = "<<maxMultiplier<<endl;
}

int main()
{
    int n=0;
    int k=0;
    int d=0;
    cout<<"Input n,k,d: ";
    while(cin>>n>>k>>d)
    {
        cout<<"Weights of numbers:";
        int* weight = new int[n];
		int i;
        for(i=0;i<n;i++)
        {
            cin>>weight[i];
        }
        int* muls = new int[k];
        int maxMultiplier = GetMaxMultiplier(weight,n,k,d,muls);
        PrintResult(maxMultiplier, k, weight, muls);
        
        delete[] weight;
        cout<<endl<<"Input n,k,d: ";
    }
    return 0;
}
