/*
判断整数序列是不是二元查找树的后序遍历结果
*/

#include <iostream>

using namespace std;

int helper(int* arr,int s,int e)
{
	if(e == s)
	{
		return 1;
	}
	int i = e - 1;
	while(i>=s && arr[i]>arr[e])
	{
		i--;
	}
	if(!helper(arr,i+1,e-1))
	{
		return 0;
	}
	while(arr[e] < arr[i] && i>=s)
	{
		i--;
	}
	return helper(arr,s,i);

}

int main()
{
	int arr[7]={5,7,6,9,11,10,8};
	cout<<helper(arr,0,6)<<endl;
	return 0;
}