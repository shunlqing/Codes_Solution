/**
 * 反转链表
*/

#include <iostream>
#include <cassert>
#include "List.h"
using namespace std;

ListNode* ReverseList(ListNode* pHead)
{
    if(pHead == nullptr)
        return nullptr;
    
    ListNode* t = pHead;
    pHead = nullptr;

    while(t != nullptr)
    {
        ListNode* pNode = t;
        t = t->next;

        //注意这里没有头结点
        if(pHead == nullptr)
        {
            pHead = pNode;
            pNode->next = nullptr;
        }
        else 
        {
            pNode->next = pHead; 
            pHead = pNode;
        }
    }

    return pHead;
}

/**
 * 递归写法
*/
ListNode* ReverseListRecur(ListNode* pHead)
{
    if(pHead == nullptr)
        return nullptr;
    
    if(pHead->next == nullptr)
        return pHead;

    ListNode* newHead = ReverseListRecur(pHead->next);
    pHead->next->next = pHead;
    pHead->next = nullptr;

    return newHead;
}

int main()
{
    std::vector<int> vec = {1,2,3,4,5,6,7,8};
    ListNode* p = CreateList(vec);
    ShowList(p);
    ListNode* pRet = ReverseList(p);
    ShowList(pRet);

    ListNode* pRet1 = ReverseList(nullptr);
    assert(pRet1 == nullptr);

    ListNode* pNode = new ListNode();
    pNode->next = nullptr;
    pNode->val = 1;
    ListNode* pRet2 = ReverseList(pNode);
    assert(pRet2 = pNode);

    //for recur
    std::vector<int> vec1 = {1,2,3,4,5,6,7,8};
    ListNode* p1 = CreateList(vec);
    ShowList(p1);
    ListNode* pRet3 = ReverseList(p1);
    ShowList(pRet3);

    ListNode* pRet4 = ReverseList(nullptr);
    assert(pRet4 == nullptr);

    ListNode* pNode1 = new ListNode();
    pNode1->next = nullptr;
    pNode1->val = 1;
    ListNode* pRet5 = ReverseList(pNode1);
    assert(pRet5 = pNode1);
}
