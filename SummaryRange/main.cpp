/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        vector<string> vec;
        int len = nums.size();
        if(len == 0)
        {
            return vec;
        }
        int start = nums[0];
        int end = nums[0];
        for(int i=1; i<len; i++)
        {
            if(nums[i] == nums[i-1] + 1)
            {
                end = nums[i];
            }
            else
            {
                if(end>start)
                {
                    stringstream ss;
                    ss<<start<<"->"<<end;
                    vec.push_back(ss.str());
                }
                else
                {
                    stringstream ss;
                    ss<<start;
                    vec.push_back(ss.str());
                }
                start = nums[i];
                end = nums[i];
            }
        }
        if(end>start)
        {
            stringstream ss;
            ss<<start<<"->"<<end;
            vec.push_back(ss.str());
        }
        else
        {
            stringstream ss;
            ss<<start;
            vec.push_back(ss.str());
        }
        return vec;
    }
};

int main()
{
    Solution* s = new Solution();
    vector<int> vec;
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(7);
    vector<string> vec_result = s->summaryRanges(vec);
    for(int i=0;i<vec_result.size();i++)
    {
        cout<<vec_result[i]<<endl;
    }
    delete s;
    return 0;
}
