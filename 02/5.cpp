// https://leetcode.com/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
    ListNode *
};

ListNode*
Solution::addTwoNumbers(ListNode* l1, ListNode* l2)
{
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;
    
    ListNode *newHead = nullptr;
    ListNode *newTemp = nullptr;
    int carry = 0;

    while (l1 != nullptr && l2 != nullptr)
    {
        ListNode *node = new ListNode();
        int add = l1->val + l2->val + carry;
        carry = add / 10;
        add = add % 10;
        node->val = add;

        if (newHead == nullptr)
        {
            newHead = node;
            newTemp = newHead;
        }
        else
        {
            newTemp->next = node;
            newTemp = newTemp->next;
        }
        l1 = l1->next;
        l2 = l2->next; 
    }

    if (l1 != nullptr && l2 == nullptr)
        l2  = l1;

    while (l2 != nullptr)
    {
        ListNode *node = new ListNode();
        int add = l2->val + carry;
        carry = add / 10;
        add = add % 10;
        node->val = add;

        newTemp->next = node;
        newTemp = newTemp->next;

        l2 = l2->next; 
    }

    if (carry != 0)
    {
        ListNode *node = new ListNode();
        node->val = carry;

        newTemp->next = node;
        newTemp = newTemp->next;
    }

    return newHead;
}



// Follow Up:- https://leetcode.com/problems/add-two-numbers-ii/


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
    ListNode* reverseList(ListNode* head);
};

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

ListNode*
Solution::addTwoNumbers(ListNode* l1, ListNode* l2)
{
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;
    
    l1 = this->reverseList(l1);
    l2 = this->reverseList(l2);
    ListNode *newHead = nullptr;
    ListNode *newTemp = nullptr;
    int carry = 0;

    while (l1 != nullptr && l2 != nullptr)
    {
        ListNode *node = new ListNode();
        int add = l1->val + l2->val + carry;
        carry = add / 10;
        add = add % 10;
        node->val = add;

        if (newHead == nullptr)
        {
            newHead = node;
            newTemp = newHead;
        }
        else
        {
            newTemp->next = node;
            newTemp = newTemp->next;
        }
        l1 = l1->next;
        l2 = l2->next; 
    }

    if (l1 != nullptr && l2 == nullptr)
        l2  = l1;

    while (l2 != nullptr)
    {
        ListNode *node = new ListNode();
        int add = l2->val + carry;
        carry = add / 10;
        add = add % 10;
        node->val = add;

        newTemp->next = node;
        newTemp = newTemp->next;

        l2 = l2->next; 
    }

    if (carry != 0)
    {
        ListNode *node = new ListNode();
        node->val = carry;

        newTemp->next = node;
        newTemp = newTemp->next;
    }

    newHead = this->reverseList(newHead);
    return newHead;
}
