/**
 * 按中序遍历找出二叉树的下一个节点
*/

struct BinaryTreeNode {
    int val;
    BinaryTreeNode *pLeft;
    BinaryTreeNode *pRight;
    BinaryTreeNode *pParent;
};

BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
    if(pNode == nullptr)
        return nullptr;

    if(pNode->pRight != nullptr) {
        BinaryTreeNode* t = pNode->pRight;
        while(t->pLeft) {
            t = t->pLeft;
        }
        return t;
    } else if(pNode->pParent != nullptr) {
        BinaryTreeNode* pCur = pNode;
        BinaryTreeNode* pPar = pNode->pParent;
        while(pCur == pPar->pRight) {
            pCur = pPar;
            pPar = pPar->pParent;
            if(pPar == nullptr)
                return nullptr;
        }
        return pPar;
    }
}