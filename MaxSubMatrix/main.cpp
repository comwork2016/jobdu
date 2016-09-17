#include <iostream>
using namespace std;

int maxSubArray(int a[],int n)
{
    int b=0,sum=a[0];
    for(int i=0; i<n; i++)
    {
        if(b>0)
            b+=a[i];
        else
            b=a[i];
        if(b>sum)
            sum=b;
    }
    return sum;
}

int maxSubMatrix(int **matrix,int n,int m)
{
    int max = 0;
    int sum = -1001;
    int *b = new int[m];
    int i=0;
    for(i=0; i<n; i++)
    {
        int k=0;
        for(k=0; k<m; k++) //初始化b[]
        {
            b[k]=0;
        }
        int j=0;
        for(j=i; j<n; j++) //把第i行到第j行相加,对每一次相加求出最大值
        {
            for(k=0; k<m; k++)
            {
                b[k]+=matrix[j][k];
            }
            max=maxSubArray(b,k);
            if(max>sum)
            {
                sum=max;
            }
        }
    }
    delete b;
    return sum;
}

int main()
{
    int Array[4][4] = {0,-2,-7,0,9,2,-6,2,-4,1,-4,1,-1,8,0,-2};
    int n = 4;
    int m = 4;
    int** matrix;
    matrix = new int*[n];
    for(int i=0;i<n;i++)
    {
        matrix[i] = new int[m];
        for(int j=0;j<m;j++)
        {
            matrix[i][j] = Array[i][j];
        }
    }
    cout<<maxSubMatrix(matrix,n,m)<<endl;
    for(int i=0;i<n;i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}
