/**
��һ���ַ����Ĵ�д��ĸ�ŵ��ַ����ĺ��棬�����ַ������λ�ò��䣬�Ҳ����������Ŀռ䡣
	AkleBiCeilD
	kleieilABCD
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	while(cin>>str)
	{
		int lowercase = 0;
		while(lowercase<str.length())
		{
			while(lowercase < str.length() && str[lowercase]<='Z')//�ҵ���һ��Сд��ĸ���ڵ�λ��
			{
				lowercase++;
			}
			if(lowercase >= str.length())
			{
				break;
			}
			//��Сд��ĸ��ǰ��Ĵ�д��ĸ��λ
			while(lowercase-1 >=0 && str[lowercase-1]<='Z')//ֱ������Сд��ĸֹͣ
			{
				char temp = str[lowercase];
				str[lowercase] = str[lowercase-1];
				str[lowercase-1] = temp;
				lowercase--;
			}
			lowercase++;
		}
		cout<<str<<endl;
	}
	return 0;
}