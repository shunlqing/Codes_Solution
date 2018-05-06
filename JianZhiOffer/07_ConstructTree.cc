/**
 * 重建二叉树
 * 
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建二叉树
*/

struct BinaryTreeNode {
    int val;
    BinaryTreeNode* pLeft;
    BinaryTreeNode* pRight;
};

BinaryTreeNode* ConstructCore(
    int *startPreorder, int * endPreorder,
    int *startInorder, int *endInorder
)
{
    if(startPreorder == endPreorder) {
        BinaryTreeNode* node = new BinaryTreeNode();
        node->val = *startPreorder;
        node->pLeft = nullptr;
        node->pRight = nullptr;
        return node;
    }

    BinaryTreeNode* node = new BinaryTreeNode();
    node->val = *startPreorder;

    int* rootInorder = startInorder;
    while(rootInorder <= endInorder) {
        if(*rootInorder = *startPreorder)
            break;
        rootInorder++;
    }

    if(rootInorder == endInorder && *rootInorder != *endInorder)
        throw;

    BinaryTreeNode* node = new BinaryTreeNode();
    node->val = *startPreorder;

    int leftLength = rootInorder - startInorder;
    int  *leftPreOrderEnd = startPreorder + leftLength;

    if(leftLength > 0) {
        node->pLeft = ConstructCore(startPreorder + 1, leftPreOrderEnd, startInorder, rootInorder - 1);
    }

    if(leftLength < endPreorder - startPreorder) {
        node->pRight = ConstructCore(leftPreOrderEnd+1, endPreorder, rootInorder + 1, endInorder);
    }

    return node;
}

BinaryTreeNode* Construct(int *preorder, int* inorder, int length)
{
    if(preorder == nullptr || inorder == nullptr || length == 0)
        return nullptr;

    return ConstructCore(preorder, preorder + length -1, inorder, inorder+length-1);
}
