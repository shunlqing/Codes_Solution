/**
 * 从尾到头打印链表
*/

#include <cstdio>
#include <stack>

struct ListNode
{
    int val;
    ListNode* next;
};

/**
 * 打印操作，一般是不会改变数据结构的。。。常识
 * 
 * 思路1:使用栈结构
 * 思路2：递归
*/

void PrintListReversingly_Iteratively(ListNode* pHead)
{
    std::stack<ListNode*> st; //使用ListNode*或int的栈

    ListNode* p = pHead;
    while(p != nullptr) {
        st.push(p);
        p = p->next;
    }

    while(!st.empty()) {
        p = st.top();
        printf("%d\t", p->val);
        st.pop();
    }
}

void PrintListReversingly_Recursively(ListNode* pHead)
{
    if(pHead == nullptr)
        return;

    PrintListReversingly_Recursively(pHead->next);
    printf("%d\t", pHead->val);
}