/**
 * 链表中倒数第k个节点
*/

#include <iostream>
#include <cassert>
#include "List.h"
using namespace std;

/**
 * 注意点：
 *  1. 输入nullptr
 *  2. k = 0
 *  3. k大于链表长度
 *  
*/

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
    if(pListHead == nullptr || k <= 0)
    {
        return nullptr;
    }

    ListNode* pFast = pListHead, *pSlow = pListHead;
    int i = 0;
    while(i < k - 1 && pFast != nullptr)
    {
        pFast = pFast->next;
        i++;
    }
    
    if(pFast == nullptr)
        return nullptr;
    
    while(pFast->next != nullptr)
    {
        pFast = pFast->next;
        pSlow = pSlow->next;
    }
    return pSlow;
}

int main()
{
    std::vector<int> data = {1,2,4,5,6,7,8,9,0};
    ListNode* p1 = CreateList(data);
    assert(FindKthToTail(p1, 4) != nullptr && FindKthToTail(p1, 4)->val == 7);

    assert(FindKthToTail(p1, 0) == nullptr); //k = 0

    assert(FindKthToTail(p1, 11) == nullptr); // k > listsize

    std::cout << "test finished, all passed!" << endl;
}