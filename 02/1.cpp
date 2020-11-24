#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include "LL.hpp"

using namespace std;

void
createLL(LL<int> &list)
{
	list.push_back(10);
    list.push_back(11);
    list.push_back(12);
    list.push_back(13);
    list.push_back(21);
    list.push_back(31);
    list.push_back(10);
    list.push_back(20);
}

void
deleteDuplicate(LL<int> &list)
{
    if (list._header == nullptr || list._header->_next == nullptr)
        return;
    
    Node<int> *temp = list._header;
    map<int, int> mp;
    while (temp != nullptr)
    {
        mp[temp->_data]++;
        temp = temp->_next;
    }

    Node<int> *newHead = nullptr;
    Node<int> *newTemp = nullptr;
    temp = list._header;

    while (temp != nullptr)
    {
        map<int, int>::iterator it = mp.find(temp->_data);
        if (it->second == 1)
        {
            if (newHead == nullptr)
            {
                newHead = temp;
                newTemp = newHead;
            }
            else
            {
               newTemp->_next = temp;
               newTemp = newTemp->_next;
            }
        }
        temp = temp->_next;
    }
    if (newTemp != nullptr)
    {
        newTemp->_next = nullptr;
    }
    list._header = newHead;
}

int
main()
{
    LL<int> list;
    createLL(list);
    list.print_LL();
    deleteDuplicate(list);
    list.print_LL();
    return 0;
}