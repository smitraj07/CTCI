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
   /* list.push_back(12);
    list.push_back(13);
    list.push_back(21);
    list.push_back(31);
    list.push_back(10);
    list.push_back(20);*/
}

void
deleteMiddle(LL<int> &list)
{
    if (list._header == nullptr || list._header->_next == nullptr)
        return;

    Node<int> *fastPtr = list._header->_next;
    Node<int> *slowPtr = list._header;
    Node<int> *prevPtr = nullptr;

    while (fastPtr != nullptr && fastPtr->_next != nullptr)
    {
        fastPtr = fastPtr->_next->_next;
        prevPtr = slowPtr;
        slowPtr = slowPtr->_next;
    }
    if (fastPtr != nullptr)  // fastPtr->next == nullptr will not work... think?
    {
        prevPtr = slowPtr;
        slowPtr = slowPtr->_next;
    }
    prevPtr->_next = slowPtr->_next;
    slowPtr->_next = nullptr;
}

int 
main()
{
    LL<int> list;
    createLL(list);
    list.print_LL();
    deleteMiddle(list);
    list.print_LL();
    return 0;
}