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
    i=0;   //����
    k=0;   //�˴�Ϊ3
	//    m=0;   //mΪ�˳�����
    while(m<n-1)
    {
        if(*(p+i)!=0)
		{
			k++;
		}
        if(k==3)
        {
			printf("%d quit\n",*(p+i));
            *(p+i)=0;    //�˳�����Ӧ������Ԫ����Ϊ0
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