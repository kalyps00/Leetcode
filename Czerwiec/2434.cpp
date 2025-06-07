#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
    char maks(vector<int> frequency)
    {
        for (int i = 0; i < frequency.size(); i++)
        {
            if (frequency[i] > 0)
                return i + 'a';
        }
        return 'a';
    }
    string
    robotWithString(string s)
    {
        stack<char> t;
        vector<int> frequency(26);
        for (auto x : s)
        {
            frequency[x - 'a']++;
        }
        string ans = "";
        int pos = 0;
        char c = 'a';
        for (char c : s)
        {
            t.push(c);
            frequency[c - 'a']--;
            while (!t.empty() && t.top() <= maks(frequency))
            {
                ans += t.top();
                t.pop();
            }
        }
        while (!t.empty())
        {
            ans += t.top();
            t.pop();
        }
        return ans;
    }
};