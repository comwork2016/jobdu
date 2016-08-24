#include <stdio.h>

int main()
{
    int i,k,m,n,num[50],*p;
    printf("input number of person:n=");
    scanf("%d",&n);
	
    printf("input number of the quit:m=");
    scanf("\n%d",&m);
	
	p=num;
    for(i=0;i<n;i++)
	{
        *(p+i)=i+1;
	}
    i=0;   //报数
    k=0;   //此处为3
	//    m=0;   //m为退出人数
    while(m<n-1)
    {
        if(*(p+i)!=0)
		{
			k++;
		}
        if(k==3)
        {
			printf("%d quit\n",*(p+i));
            *(p+i)=0;    //退出，对应的数组元素置为0
            k=0;
            m++;
        }
		i++;
		if(i==n){
			i=0;
		}
	}
	while(*p==0){
		p++;
	}
	printf("The last one is NO.%d\n",*p);
	return 0;
}