#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k, int numOperations)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<int> vals;
        vector<int> freq;
        for (int i = 0; i < n;)
        {
            int j = i;
            while (j < n && nums[j] == nums[i])
                j++;
            vals.push_back(nums[i]);
            freq.push_back(j - i);
            i = j;
        }
        
        /*
     int l = 0, r = 0;
     int max_ans = 1;
     int ans = 0;
     for (int l = 0; l < nums.size() - 1; l++)
     {
         // edge case lowerbound = end()
         int firs_greater_than_2k_idx = lower_bound(nums.begin() + l, nums.end(), l + 2 * k) - nums.begin();
         if (firs_greater_than_2k_idx >= numOperations)
             return numOperations;
         numOperations -= firs_greater_than_2k_idx + 1 - l;
         ans = firs_greater_than_2k_idx - l + 1;
         r = firs_greater_than_2k_idx + 1;
         while (int diff = nums[r] - nums[l] / k >= 1)
         {
             ans += diff;
             numOperations -= diff;
         }
         max_ans = max(ans, max_ans);
     }
     return max_ans; */
    }
};