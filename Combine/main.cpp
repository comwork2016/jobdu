#include <iostream>
#include <string.h>

using namespace std;

void printSelected(int* selected,int n,int count)
{
	cout<<"condition "<<count<<":";
	for(int i=0;i<n;i++)
	{
		if(selected[i])
		{
			cout<<i<<" ";
		}
	}
	cout<<endl<<endl;
}

void helper(int cur,int n,int k,int* selected,int& count)
{
	if(k==0)
	{
		count++;
		printSelected(selected,n,count);
		return;
	}
	if(cur < n)
	{
		selected[cur] = 1;
		helper(cur+1,n,k-1,selected,count);// output this number
		selected[cur] = 0;
		helper(cur+1,n,k,selected,count); // don't output this number
	}
}

int main()
{
	int n,k;
	while(cin>>n>>k)
	{
		int count = 0;
		int* selected = new int[n];
		memset(selected,0,sizeof(int)*n);
		helper(0,n,k,selected,count);
		//cout<<count<<endl<<endl;
		delete[] selected;
	}
	return 0;
}