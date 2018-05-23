/**
 * 二叉树的序列化与反序列化
*/
#include <iostream>
#include <deque>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* pLeft;
    TreeNode* pRight;
    TreeNode(int v) : val(v), pLeft(nullptr), pRight(nullptr) {}
};

void Serialize(TreeNode* pRoot, string& serVec)
{
    if(pRoot == nullptr)
    {
        serVec.push_back('$');
        return;
    } 

    serVec += to_string(pRoot->val);
    Serialize(pRoot->pLeft, serVec);
    Serialize(pRoot->pRight, serVec);
}


TreeNode* DeSerialize(string& serVec)
{
    if(serVec.size() <= 0)
        return nullptr;
    
    char val = serVec.front();
    serVec.erase(serVec.begin());

    if(val == '$')
    {
        return nullptr;
    }
    
    TreeNode* root = new TreeNode(val - '0');
    root->pLeft = DeSerialize(serVec);
    root->pRight = DeSerialize(serVec);

    return root;
}

int main()
{
    string str("124$$$35$$6$$");
    TreeNode* root = DeSerialize(str);

    string vec;
    Serialize(root, vec);
    cout << vec << endl;
}