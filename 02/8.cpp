// https://leetcode.com/problems/linked-list-cycle-ii/

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
    ListNode *detectCycle(ListNode *head) {
        
        if (head == NULL || head->next == NULL)
            return NULL;
        
        ListNode *slowPtr = head;
        ListNode *fastPtr = head->next;
        
        while (true)
        {
            if (fastPtr == NULL || fastPtr->next == NULL)
                break;
            if (fastPtr == slowPtr)
                break;
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
        }
        if (fastPtr == NULL || fastPtr->next == NULL)
        {
            return NULL;
        }
        else
        {
            fastPtr = fastPtr->next;
            slowPtr = head;
            
            while (slowPtr != fastPtr)
            {
                fastPtr = fastPtr->next;
                slowPtr = slowPtr->next;
            }
            
            return slowPtr;
        }
    }
};