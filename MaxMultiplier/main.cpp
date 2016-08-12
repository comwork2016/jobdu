/**
����һ������Ϊn������[w1,w2...wn]����������ѡȡk����ֵ��Ҫ����k����ֵ�ľ��벻����d��
�ʣ�����ѡȡk������ʹ��k�����ĳ˻����

  ÿ��������� 1 ������������ÿ���������ݵĵ�һ�а���һ������ n (1 <= n <= 50)����ʾѧ���ĸ�������������һ�У����� n ����������˳���ʾÿ��ѧ��������ֵ ai��-50 <= ai <= 50������������һ�а�������������k �� d (1 <= k <= 10, 1 <= d <= 50)��
  
    ˼·��
	cost[i][j]����ʾѡ�е�i������Ϊ�����k�����еĵ�j�������ĳ˻���ֵ��
	��cost[i][j] = w[i]*max{cost[i-d][j-1],cost[i-d+1][j-1].....,cost[i-1][j-1]}
	
	  path[i][j]����ʾѡ�е�i������Ϊ�����k�����еĵ�j��������ǰһ��������
*/
#include <stdio.h>
#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

//typedf long long _int64;����ʹ��64λ���ݣ�����ᵼ�����

/**
��̬�滮����������˻�
*/
_int64 GetMaxMultiplier(int* weight,int n,int k,int d,int* muls)
{
	int i;
    //��ʼ��״̬���� �����͸������ֵ
    _int64** cost = new _int64*[n];
	_int64** costn = new _int64*[n];
    //���������Ϣ
    int** path = new int*[n];
	int** pathn = new int*[n];
    for(i=0;i<n;i++)
    {
        cost[i] = new _int64[k];
        costn[i] = new _int64[k];
        path[i] = new int[k];
        pathn[i] = new int[k];
    }
    //�ӵ�һ������ʼ����˻���ֵ��������
    for(i=0;i<n;i++)
    {
		//����i������Ϊ��0�������ĳ˻�Ϊweight[i]
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
        for(int j=1;j<=i&&j<k;j++) //��i����������Ϊ����i��k�ĳ���
        {
            //Ѱ��ǰ��d������֮�ڣ���j-1�����������ֵ
            _int64 maxMul = 0;
			_int64 maxMuln = 0;
            int lastPath = -1;
			int lastPathn = -1;
            //Ѱ��ǰj-1�������Ļ������ֵ
            for(int m=1;m<=d;m++)
            {
                if(i-m>=0 && i-m >= j-1)
                {
                    if(maxMul < cost[i-m][j-1]) //Ѱ���������ֵ
                    {
                        maxMul = cost[i-m][j-1];
                        lastPath = i-m;
                    }
					if(maxMuln > costn[i-m][j-1])//Ѱ�Ҹ������ֵ
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
	
    //Ѱ��cost[i][k-1]�����ֵ
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
	
	//�������ĳ�����Ϣ
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
