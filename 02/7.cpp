// https://leetcode.com/problems/intersection-of-two-linked-lists/submissions/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
    int count(ListNode *head);
    ListNode *moveDiff(ListNode *head, int count);
};

int 
Solution::count(ListNode *head)
{
    if (head == NULL)
        return 0;
    
    int count = 1;
    
    while (head != NULL)
    {
        head = head->next;
        count++;
    }
    return count;
}

ListNode*
Solution::moveDiff(ListNode *head, int count)
{
    while (count != 0)
    {
        head = head->next;
        count--;
    }
    return head;
}

ListNode*
Solution::getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == NULL || headB == NULL)
        return NULL;
    
    int countA = this->count(headA);
    int countB = this->count(headB);
    int diff;
    
    if (countA > countB)
    {
        headA = this->moveDiff(headA, countA - countB);
    }
    else
    {
        headB = this->moveDiff(headB, countB - countA);
    }
    
    while (headA != NULL && headB != NULL)
    {
        if (headA == headB)
            return headA;
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}