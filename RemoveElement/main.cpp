#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = nums.size();
        int restlength = length;
        int begin=0;
        int end = length-1;
        while(begin <= end)
        {
            while(nums[end]==val && end>=0)
            {
                end--;
                restlength--;
            }
            while(nums[begin]!=val && begin<length)
            {
                begin++;
            }
            if(begin <= end)
            {
                nums[begin] = nums[end];
                restlength--;
                begin++;
                end--;
            }
        }
        return restlength;
    }
};

int main()
{
    Solution* s = new Solution();
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    cout<<s->removeElement(nums,3)<<endl;
    delete s;
    return 0;
}
