// Leetcode:- https://leetcode.com/problems/partition-list/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x);
};

ListNode*
Solution::partition(ListNode* head, int x)
{
    ListNode *left = NULL;
    ListNode *leftTemp = NULL;
    ListNode *right = NULL;
    ListNode *rightTemp = NULL;
    
    while (head != NULL)
    {
        if (head->val < x)
        {
            if (left == NULL)
            {
                left = head;
                leftTemp = left;
                head = head->next;
                leftTemp->next = NULL;
            }
            else
            {
                leftTemp->next = head;
                head = head->next;
                leftTemp = leftTemp->next;
                leftTemp->next = NULL;
            }
        }
        else
        {
            if (right == NULL)
            {
                right = head;
                rightTemp = right;
                head = head->next;
                rightTemp->next = NULL;
            }
            else
            {
                rightTemp->next = head;
                head = head->next;
                rightTemp = rightTemp->next;
                rightTemp->next = NULL;
            }
        }
    }
    
    if (left != NULL)
    {
        leftTemp->next = right;
    }
    else
    {
        left = right;
    }
    
    return left;
}