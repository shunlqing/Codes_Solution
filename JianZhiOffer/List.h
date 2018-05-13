#ifndef LIST_H
#define LIST_H

#include <cstdlib>
#include <time.h>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
};

ListNode* CreateList(std::vector<int> &vec)
{
    ListNode *pHead = nullptr;
    int n = vec.size();    
    if(n <= 0)
        return pHead;

    int i = 0;
    ListNode *t = nullptr;
    while(i < n)
    {
        ListNode* tmp = new ListNode();
        tmp->val = vec[i];
        tmp->next = nullptr;
        if(t == nullptr && pHead == nullptr)
        {
            t = tmp;
            pHead = t;
        }
        else
        {
            t->next = tmp;
            t = tmp;
        }
        i++;
    }

    return pHead;
}

ListNode* CreateList(int n, int val)
{   
    ListNode* pHead = nullptr;
    std::vector<int> vec(n, val);
    pHead = CreateList(vec);

    return pHead;
}

void ShowList(ListNode* list)
{
    ListNode* p = list;
    while(p != nullptr)
    {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

void ShowListFirstKthNode(ListNode* list, int k)
{
    ListNode* p = list;
    int i = 0;
    while(i++ < k && p != nullptr)
    {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

ListNode* CreateListWithLoop()
{
    srand((unsigned int)time(0));
    int nodeSum = rand() % 30 + 20;
    int entryPos = rand() % (nodeSum - 1) + 1;
    
    std::vector<int> vec(nodeSum);
    int i = 1;
    for(auto &x : vec)
    {
        x = i;
        i++;
    }

    ListNode* pHead = CreateList(vec);
    ListNode* pEntry = pHead, *pEnd = pHead;
    int k = 1;
    while(k++ < entryPos && pEntry != nullptr)
    {
        pEntry = pEntry->next;
        pEnd = pEnd->next;
    }

    while(pEnd->next != nullptr)
    {
        pEnd = pEnd->next;
    }

    pEnd->next = pEntry;
    
    return pHead;
}


void LoopListCreateTest()
{
    ListNode* p = CreateListWithLoop();
    ListNode* q = p;
    int i = 0;
    while(i++ < 100 && q != nullptr)
    {
        std::cout << q->val << " ";
        q = q->next;
    }
}

#endif