/**
 * 链表中环的入口节点
*/

#include <iostream>
#include "List.h"
using namespace std;

/**
 * 首先需要检测链表是否存在环
*/

ListNode* MeetingNode(ListNode* pHead)
{
    if(pHead == nullptr)
        return nullptr;

    ListNode* pFast = pHead, *pSlow = pHead;
    
    pSlow = pFast->next;
    if(pSlow == nullptr)
        return nullptr;
    pFast = pSlow->next;
    while(pFast != nullptr && pSlow != nullptr)
    {
        if(pFast == pSlow)
            return pFast;

        pSlow = pSlow->next;
        pFast = pFast->next;
        if(pFast != nullptr)
            pFast = pFast->next;
    }

    return nullptr;
}

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
    ListNode* meetingNode = MeetingNode(pHead);
    if(meetingNode == nullptr)
        return nullptr;
    
    int nodesInLoop = 1;
    ListNode* pNode1 = meetingNode;
    while(pNode1->next != meetingNode)
    {
        pNode1 = pNode1->next;
        nodesInLoop++;
    }

    pNode1 = pHead;
    for(int i = 0; i < nodesInLoop; i++)
    {
        pNode1 = pNode1->next;
    }

    ListNode* pNode2 = pHead;
    while(pNode1 != pNode2)
    {
        pNode1 = pNode1->next;
        pNode2 = pNode2->next;
    }

    return pNode1;
}

int main()
{
    ListNode* pList = CreateListWithLoop();
    ShowListFirstKthNode(pList, 100);
    ListNode* entry = EntryNodeOfLoop(pList);
    if(entry)
        std::cout << entry->val << endl;
    else 
        std::cout << "nullptr" << endl;

    ListNode* pList1 = CreateList(10, 2);
    ShowList(pList1);
    entry = EntryNodeOfLoop(pList1);
    if(entry)
        std::cout << entry->val << endl;
    else 
        std::cout << "nullptr" << endl;
    
}

