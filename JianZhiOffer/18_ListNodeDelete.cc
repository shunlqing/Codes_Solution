/**
 * 删除链表节点
*/

/**
 * 题目1：在O(1)时间内删除链表节点
 * 
 * 给点链表的头指针和欲删除的节点指针。
 * 
 * 注意点：
 *  链表有头结点。
 *  要删除的节点是不是尾节点。
 *  链表是不是为空。
 * 
 * 思路：
 *  交换与下一个节点的值
 *  如果多个节点，要删除的节点恰好的尾节点，那么就要遍历一遍，但是这样总体时间复杂度还是O(1)
*/

struct ListNode {
    int val;
    ListNode *next;
};

void DeleteNode(ListNode** pHead, ListNode* pToDelete)
{
    if(!pHead || !pToDelete)
        return;

    if(pToDelete->next != nullptr) { // 要删除的节点不是尾节点
        ListNode *pNext = pToDelete->next;
        pToDelete->val = pNext->val;
        pToDelete->next = pNext->next;

        delete pNext;
        pNext = nullptr;
    } else if(*pHead = pToDelete) { // 只有一个节点
        *pHead = nullptr;
        delete pToDelete;
        pToDelete = nullptr;
    } else { // 链表有福讴歌节点，删除尾节点
        ListNode* pNode = *pHead;
        while(pNode->next != pToDelete) {
            pNode = pNode->next;
        }

        pNode->next = nullptr;
        delete pToDelete;
        pToDelete = nullptr;
    }
}
