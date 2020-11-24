// https://leetcode.com/problems/palindrome-linked-list/

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
    bool isPalindrome(ListNode* head);
    ListNode *findMid(ListNode* head);
    ListNode* reverseList(ListNode* head);
};

ListNode*
Solution::findMid(ListNode* head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    
    ListNode* slowPtr = head;
    ListNode* fastPtr = head->next;
    ListNode* temp = nullptr;
    
    while(fastPtr != nullptr && fastPtr->next != nullptr)
    {
        fastPtr = fastPtr->next->next;
        temp = slowPtr;
        slowPtr = slowPtr->next;
    }
    // special remove the odd
    if (fastPtr == nullptr)
    {
        temp->next = slowPtr->next;
        slowPtr = temp;
    }
    
    return slowPtr;
}

ListNode*
Solution::reverseList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *first;
    ListNode *second;
    ListNode *third;

    first = head;
    second = first->next;
    third = second->next;

    first->next = nullptr;
    second->next = first;

    while (third != nullptr)
    {
        first = second;
        second = third;
        third = third->next;
        second->next = first;
    }
    return second;
}

bool 
Solution::isPalindrome(ListNode* head)
{
    if (head == nullptr || head->next == nullptr)
        return true;
    
    ListNode *mid = findMid(head);
    ListNode *temp = mid;
    mid = mid->next;
    temp->next = nullptr;
    temp = reverseList(head);
    
    while (mid != nullptr)
    {
        if (temp->val != mid->val)
            return false;
        
        mid = mid->next;
        temp = temp->next;
    }
    return true;
}
