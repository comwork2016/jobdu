#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        vector<char> vec_head;
        vector<char> vec_tail;
		for(int i=0;i<n;i++)
		{
			string str;
			cin >> str;
			char head = str[0];
			char tail = str[str.length() - 1];
			//在尾列表中查找头字符
			vector<char>::iterator it_tail = find(vec_tail.begin(),vec_tail.end(),head);
			if(it_tail == vec_tail.end() )//没有找到
			{
				vec_head.push_back(head);
			}else//删除该字符
			{
				vec_tail.erase(it_tail);
			}
			vector<char>::iterator it_head = find(vec_head.begin(),vec_head.end(),tail);
			if(it_head == vec_head.end() )//没有找到
			{
				vec_tail.push_back(tail);
			}else//删除该字符
			{
				vec_head.erase(it_head);
			}
		}
		if(vec_head.size() == 1 && vec_tail.size() == 1)
		{
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
    }
	return 0;
}