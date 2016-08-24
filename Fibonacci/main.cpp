#include <iostream>

using namespace std;

void multipy(int A[], int B[], int _r[])
{
	_r[0] = A[0]*B[0] + A[1]*B[2];
	_r[1] = A[0]*B[1] + A[1]*B[3];
	_r[2] = A[2]*B[0] + A[3]*B[2];
	_r[3] = A[2]*B[1] + A[3]*B[3];
}

void power(int A[],int n,int _r[])
{
	if(n ==1)
	{
		memcpy(_r,A,4*sizeof(int));
		return;
	}
	int tmp[4];
	power(A,n>>1,_r);
	multipy(_r,_r,tmp);
	if(n & 1 == 1)
	{
		multipy(tmp,A,_r);
	}else
	{
		memcpy(_r,tmp,4*sizeof(int));
	}
}

int f(int n)
{
	int A[4] = {1,1,1,0};
	int result[4];
	power(A,n,result);
	return result[0];
}

int main()
{
	cout<<f(4)<<endl;
	return 0;
}