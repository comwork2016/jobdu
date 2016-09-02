/*
Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."
*/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
    int hIndex(vector<int>& citations)
    {
        map<int,int> map_cit;
        int maxResult = 0;
        int n = citations.size();
        for(int i=0; i<=n; i++)
        {
            map_cit[i] = 0;
        }
        for(int i=0; i<n; i++)
        {
            int num = citations[i];
            for(map<int,int>::iterator it = map_cit.begin(); it!=map_cit.end();)
            {
                if(it->first <= num)
                {
                    map_cit[it->first] = map_cit[it->first] + 1;
                    if(map_cit[it->first] >= it->first)
                    {
                        if(it->first > maxResult)
                        {
                            maxResult = it->first;
                        }
                        it = map_cit.erase(it);
                    }else
                    {
                        it++;
                    }
                }
                else
                {
                    it++;
                }
            }
        }
        return maxResult;
    }
};

int main()
{
    vector<int> vec;
    vec.push_back(1);
    //vec.push_back(1);
    Solution* s = new Solution();
    cout << s->hIndex(vec)<< endl;
    delete s;
    return 0;
}
