/**
    ����һ������Ϊn������[w1,w2...wn]����������ѡȡk����ֵ��Ҫ����k����ֵ�ľ��벻����d��
    �ʣ�����ѡȡk������ʹ��k�����ĳ˻����

    ˼·��
        cost[i][j]����ʾѡ�е�i������Ϊ�����k�����еĵ�j�������ĳ˻���ֵ��
        ��cost[i][j] = w[i]*max{cost[i-d][j-1],cost[i-d+1][j-1].....,cost[i-1][j-1]}

        path[i][j]����ʾѡ�е�i������Ϊ�����k�����еĵ�j��������ǰһ��������
*/
#include <iostream>
#include <stack>

using namespace std;

/**
    ��̬�滮����������˻�
*/
int GetMaxMultiplier(int* weight,int n,int k,int d,int* muls)
{
	int i;
    //��ʼ��״̬����
    int** cost = new int*[n];
    //���������Ϣ
    int** path = new int*[n];
    for(i=0;i<n;i++)
    {
        cost[i] = new int[k];
        path[i] = new int[k];
    }
    //�ӵ�һ������ʼ����˻���ֵ��������
    for(i=0;i<n;i++)
    {
        cost[i][0] = weight[i];//����i������Ϊ��0�������ĳ˻�Ϊweight[i]
        for(int j=1;j<=i&&j<k;j++) //��i����������Ϊ����i��k�ĳ���
        {
            //Ѱ��ǰ��d������֮�ڣ���j-1�����������ֵ
            int maxMul = 0;
            int lastPath = 0;
            //Ѱ��ǰj-1�������Ļ������ֵ
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

    //Ѱ��cost[i][k-1]�����ֵ
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

    //�������ĳ�����Ϣ
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
