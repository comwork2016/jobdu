#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int m,n;
    while(cin>>n>>m)
    {
        vector<int> vec;
        int count = 0;//缺页次数
        for(int i=0;i<m;i++)
        {
            int tmp;
            cin>>tmp;
            vector<int>::iterator it = find(vec.begin(),vec.end(),tmp);
            if(it == vec.end())//没有
            {
                count++;
                vec.push_back(tmp);
                if(vec.size() == n+1)//溢出了，需要出队
                {
                    vec.erase(vec.begin());
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
