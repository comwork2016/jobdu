#include <iostream>
#include <vector>

/**
    N个数组成的排列，共有K个顺序对，
    输出给定部分序列的所有符合条件的序列
*/

using namespace std;

int getK(int index,int arr[],int n)
{
    int k=0;
    int* mark = new int[n+1];
    for(int i=1; i<n+1; i++)
    {
        mark[i] = 0;
    }
    for(int i=0; i<index+1; i++)
    {
        mark[arr[i]] = 1;
        for(int j=arr[i]+1; j<n+1; j++)
        {
            if(mark[j]==0)
            {
                k++;
            }
        }
    }
    delete[] mark;
    return k;
}

void disp(int arr[],int n)
{
    for(int k=0; k<n; k++)
    {
        cout<<arr[k]<<" ";
    }
    cout<<endl;
}

void backtrack(int cur,int n,int k,int arr[],int mark[],int& count)
{
    if(cur==n && getK(cur,arr,n)==k)
    {
        count++;
        //disp(arr,n);
    }
    else
    {
        if(arr[cur]!=0)//是用户自己输入的值
        {
            backtrack(cur+1,n,k,arr,mark,count);
        }
        else
        {
            for(int i=1; i<n+1; i++)
            {
                if(mark[i]==0)
                {
                    arr[cur] = i;
                    mark[i] = 1;
                    if(getK(cur,arr,n) <= k)
                    {
                        backtrack(cur+1,n,k,arr,mark,count);
                    }
                    mark[i] = 0;
                    arr[cur] = 0;
                }
            }
        }
    }
}

int main()
{
    int n,k;
    while(cin >> n >> k)
    {
        int* mark = new int[n+1];
        for(int i=0; i<n+1; i++)
        {
            mark[i] = 0;
        }
        int* arr = new int[n];
        for(int i=0; i<n; i++)
        {
            int temp;
            cin>>temp;
            arr[i] = temp;
            if(temp!=0)
            {
                mark[temp] = 1;
            }
        }
        int count = 0;
        backtrack(0,n,k,arr,mark,count);
        cout<<count<<endl;
        delete[] arr;
        delete[] mark;
    }
    return 0;
}
