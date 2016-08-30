#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        int maxIndex=0;
        pos.push_back(nums[0]);
        neg.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>0)//正数
            {
                if(pos[i-1]>0)//保存正数乘积
                {
                    pos.push_back(pos[i-1]*nums[i]);
                    if(pos[i-1]*nums[i] > pos[maxIndex])
                    {
                        maxIndex = i;
                    }
                }else
                {
                    pos.push_back(nums[i]);
                    if(nums[i] > pos[maxIndex])
                    {
                        maxIndex = i;
                    }
                }
                if(neg[i-1]<0)//保存负数乘积
                {
                    neg.push_back(neg[i-1]*nums[i]);
                }else
                {
                    neg.push_back(nums[i-1]);
                }
            }else //当前数为负数
            {
                if(neg[i-1]<0)//保存正数乘积
                {
                    pos.push_back(neg[i-1]*nums[i]);
                    if(neg[i-1]*nums[i] > pos[maxIndex])
                    {
                        maxIndex = i;
                    }
                }else
                {
                    pos.push_back(nums[i]);
                }
                if(pos[i-1]>0)//保存负数乘积
                {
                    neg.push_back(pos[i-1]*nums[i]);
                }else
                {
                    neg.push_back(nums[i]);
                }
            }
        }
        return pos[maxIndex];
    }
};

int main()
{
    Solution* s = new Solution();
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(-2);
    nums.push_back(4);
    nums.push_back(-2);
    cout << s->maxProduct(nums) << endl;
    delete s;
    return 0;
}
