/**
 * 二叉树层次遍历
*/
#include <iostream>
#include <list>

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

void LevelOrder(TreeNode* pRoot)
{
    if(pRoot == nullptr)
        return;

    list<TreeNode*> li;
    li.push_back(pRoot);

    while(!li.empty())
    {
        TreeNode* t = li.front();
        li.erase(li.begin()); 
        cout << t->val << " ";
        if(t->pLeft)
            li.push_back(t->pLeft);
        if(t->pRight)
            li.push_back(t->pRight);    
    }

    return;
}

void LevelOrderByLine(TreeNode* pRoot)
{
    if(pRoot == nullptr)
        return;

    list<TreeNode*> li;
    li.push_back(pRoot);
    li.push_back(nullptr);

    while(!li.empty())
    {
        TreeNode* t = li.front();
        li.erase(li.begin()); 
        if(t == nullptr)
        {
            if(li.empty())
                break;
            li.push_back(nullptr);
            cout << endl;
            continue;            
        }            
        cout << t->val << " ";
        if(t->pLeft)
            li.push_back(t->pLeft);
        if(t->pRight)
            li.push_back(t->pRight);    
    }

    return;
}

int main()
{
    string str("124$$$35$$6$$");
    TreeNode* root = DeSerialize(str);
    LevelOrder(root);
    cout << endl;
    LevelOrderByLine(root);
}