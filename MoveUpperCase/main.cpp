/**
把一个字符串的大写字母放到字符串的后面，各个字符的相对位置不变，且不能申请额外的空间。
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
			while(lowercase < str.length() && str[lowercase]<='Z')//找到第一个小写字母所在的位置
			{
				lowercase++;
			}
			if(lowercase >= str.length())
			{
				break;
			}
			//将小写字母与前面的大写字母换位
			while(lowercase-1 >=0 && str[lowercase-1]<='Z')//直到遇到小写字母停止
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