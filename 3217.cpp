#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        sort(nums.begin(), nums.end());
        ListNode *temp = head;
        ListNode *prev;
        ListNode dummy(-1, head);
        prev = &dummy;
        while (temp)
        {
            if (binary_search(nums.begin(), nums.end(), temp->val))
            {
                prev->next = temp->next;
                temp = temp->next;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
        return dummy.next;
    }
};