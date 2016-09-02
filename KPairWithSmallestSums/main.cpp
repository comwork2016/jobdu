/*
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.
*/

/*
    left up in the matrix is the smallest
    when you save the sum before.
    and if k smallest is surely in the range of  0<=p1<=k && 0<=p2<=k && p1 + p2 = k && numbers in the vector saved before;
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
    struct SumIndex
    {
        int i1;
        int i2;
        int sum;
        SumIndex(int i1,int i2,int sum):i1(i1),i2(i2),sum(sum){}
    };

    class compSumIndex
    {
    public:
        bool operator()(SumIndex sumIndex1,SumIndex sumIndex2)
        {
            return sumIndex1.sum < sumIndex2.sum;
        }
    };

public:
/*
    SumIndex getSmallestNum(vector<SumIndex>& vec_sum)
    {
        if(vec_sum.size() ==0)
        {
            return SumIndex(-1,-1,-1);
        }
        SumIndex min = vec_sum[0];
        int minIndex = 0;
        for(int i=0;i<vec_sum.size();i++)
        {
            if(min.sum > vec_sum[i].sum)
            {
                min = vec_sum[i];
                minIndex = i;
            }
        }
        //delete min;
        vec_sum.erase(vec_sum.begin()+minIndex);
        return min;
    }
*/
    vector<pair<int, int> > kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int> > vec_SmallestSums;
        int len1 = nums1.size();
        int len2 = nums2.size();
        if(len1 == 0 || len2 ==0)
        {
            return vec_SmallestSums;
        }
        int p1 = 0;
        int p2 = 0;
        multiset<SumIndex,compSumIndex> set_sum;
        for(int ik=0;ik<k && ik<len1*len2; ik++)
        {
            for(int i=0;i<=ik && i<len1;i++)
            {
                //when i is clear and j = ik - i;
                int j = ik - i;
                if(j>= len2) // out of range
                {
                    continue;
                }
                //cout<<i<<","<<j<<"="<<ik<<endl;
                SumIndex sum(i,j,nums1[i]+nums2[j]);
                set_sum.insert(sum);
            }
            SumIndex min = *set_sum.begin();
            vec_SmallestSums.push_back(make_pair(nums1[min.i1],nums2[min.i2]));
            set_sum.erase(set_sum.begin());
        }
        return vec_SmallestSums;
    }
};

int main()
{
    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(1);
    nums1.push_back(2);
    vector<int> nums2;
    nums2.push_back(1);
    nums2.push_back(2);
    nums2.push_back(3);
    Solution* s = new Solution();
    vector<pair<int, int> > vec_SmallestSums = s->kSmallestPairs(nums1,nums2,10);
    for(int i=0;i<vec_SmallestSums.size();i++)
    {
        cout<<vec_SmallestSums[i].first<<","<<vec_SmallestSums[i].second<<endl;
    }

    delete s;
    return 0;
}
