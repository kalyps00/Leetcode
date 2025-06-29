#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numSubseq(vector<int> &nums, int target)
    {
        long long mod = 1e9 + 7;
        int left = 0, right = nums.size() - 1;
        vector<long long> powers(nums.size());
        powers[0] = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            powers[i] = powers[i - 1] * 2 % mod;
        }
        long long ans = 0;
        sort(nums.begin(), nums.end());
        while (left <= right)
        {
            if (nums[left] + nums[right] <= target)
            {
                ans += powers[right - left] % mod;
                left++;
            }
            else
                right--;
        }
        return (ans + mod) % mod;
    }
};