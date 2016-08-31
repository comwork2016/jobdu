#include <iostream>
#include <cmath>

using namespace std;

void printN(int start,int n)
{
    for(int i=0;i<n-1;i++)
    {
        cout<<start+i<<"*";
    }
    cout<<start+n-1<<endl;
}

void printOdd(int n)//ÆæÊý
{
    int start = 1;
    for(int i=0;i<=n/2;i++)
    {
        printN(start,n);
        start = start + n*2;
    }
    start = start - n*2;
    start = start - n;
    for(int i=n/2+1;i<n;i++)
    {
        printN(start,n);
        start = start - n*2;
    }
}

void printEven(int n)//Å¼Êý
{
    int start = 1;
    for(int i=0;i<n/2;i++)
    {
        printN(start,n);
        start = start + n*2;
    }
    start = start - n;
    for(int i=n/2;i<n;i++)
    {
        printN(start,n);
        start = start - n*2;
    }
}

void squarePatternPrint(int n)
{
    if(n%2)
    {
        printOdd(n);
    }else
    {
        printEven(n);
    }
}

int main()
{
    squarePatternPrint(4);
    cout<<endl;
    squarePatternPrint(5);
    return 0;
}
