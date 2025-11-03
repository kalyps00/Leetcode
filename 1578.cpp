#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int result = 0;
        int last_max = neededTime[0];
        for (int i = 1; i < colors.length(); i++)
        {
            if (colors[i] == colors[i - 1])
            {
                result += min(neededTime[i], last_max);
                last_max = max(neededTime[i], last_max);
            }
            else
            {
                last_max = neededTime[i];
            }
        }

        return result;
    }
};