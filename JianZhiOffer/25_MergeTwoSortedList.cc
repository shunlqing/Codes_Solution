/**
 * 合并两个有序的链表
*/

#include <iostream>
#include "List.h"
using namespace std;

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    if(pHead1 == nullptr)
        return pHead2;
    if(pHead2 == nullptr)
        return pHead1;
    
    ListNode *t1 = pHead1, *t2 = pHead2;
    pHead1 = nullptr;
    pHead2 = nullptr;
    ListNode *newHead = nullptr, *p = nullptr;
    while(t1 != nullptr && t2 != nullptr)
    {
        ListNode* tmp;
        if(t1->val < t2->val)
        {
            tmp = t1;
            t1 = t1->next;
        }
        else 
        {
            tmp = t2;
            t2 = t2->next;
        }

        tmp->next = nullptr;
        if(newHead == nullptr)
        {
            newHead = tmp;
            p = tmp;
        }
        else
        {
            p->next = tmp;
            p = tmp;
        }
    }

    if(t1 != nullptr)
        p->next = t1;

    if(t2 != nullptr)
        p->next = t2;

    return newHead;
}

int main()
{
    std::vector<int> vec1 = {1, 3, 4, 5, 9, 10};
    std::vector<int> vec2 = {2, 3, 4, 4, 5, 5};
    ListNode* pHead1 = CreateList(vec1);
    ListNode* pHead2 = CreateList(vec2);
    ListNode* ret = Merge(pHead1, pHead2);
    ShowList(ret);
    
    ListNode* pHead3 = nullptr;
    ret = Merge(pHead1, pHead2);
    ShowList(ret);

    ListNode* pHead4 = new ListNode();
    pHead4->val = 0;
    pHead4->next = nullptr;
    ListNode* pHead5 = new ListNode();
    pHead5->val = 1;
    pHead5->next = nullptr;
    ret = Merge(pHead5, pHead4);
    ShowList(ret);
}

