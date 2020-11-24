// Leetcode: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n);
};

ListNode*
Solution::removeNthFromEnd(ListNode* head, int n)
{
    if (head == nullptr || n <= 0)
        return head;

    ListNode *ntemp = head;
    ListNode *newHead = nullptr;
    ListNode *temp;
    int count = 1;

    while (ntemp != nullptr && count < n)
    {
        count++;
        ntemp = ntemp->next;
    }
    if (ntemp != nullptr)
    {
        ntemp = ntemp->next;
        temp = head;
    }
    else
    {
        return head;
    }
    
    ListNode *prev = nullptr;
    while (ntemp != nullptr)
    {
        ntemp = ntemp->next;
        prev = temp;
        temp = temp->next;
    }
    if(prev != nullptr)
    {
        newHead = head;
        prev->next = temp->next;
    }
    else
    {
        newHead = head->next;
        head->next = nullptr;
    }
    
    return newHead;
}