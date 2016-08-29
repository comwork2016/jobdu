#include <iostream>

using namespace std;

void shuffle(int* poker,int n)
{
    int prehalf = 0;
    int posthalf = n;
    int* tmp = new int[2*n];
    for(int i=0;i<2*n;i=i+2)
    {
        tmp[i] = poker[prehalf];
        tmp[i+1] = poker[posthalf];
        prehalf++;
        posthalf++;
    }
    for(int i=0;i<2*n;i++)
    {
        poker[i] = tmp[i];
    }
    delete tmp;
}

void print(int poker[],int n)
{
    for(int i=0;i<2*n-1;i++)
    {
        cout<<poker[i]<<" ";
    }
    cout<<poker[2*n-1]<<endl;
}

int main()
{
    int count;
    cin>>count;
    for(int i=0;i<count;i++)
    {
        int n,k;
        cin>>n>>k;
        int* poker = new int[2*n];
        for(int j=0;j<2*n;j++)
        {
            cin>>poker[j];
        }
        for(int j=0;j<k;j++)
        {
            shuffle(poker,n);
        }
        print(poker,n);
        delete[] poker;
    }
    return 0;
}
