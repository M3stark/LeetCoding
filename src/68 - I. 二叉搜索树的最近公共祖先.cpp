/*
    剑指 Offer 68 - I. 二叉搜索树的最近公共祖先
    给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
    ------------------------------------------------------------------------
    最近公共祖先的定义为：
    “对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，
    满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
    ------------------------------------------------------------------------
    eg. 下列二叉搜索数,节点2和节点8的最近公共祖先是 6;
                6
             /     \
            2       8
          /  \     /  \
         0    4   7    9
             / \
            3   5
*/

#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return root;
        // root 比 p, q都大，说明最近公共祖先在root左边
        if (root->val > p->val && root->val > q->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        // root 比 p, q都小，说明最近公共祖先在root右边
        else if (root->val < p->val && root->val < q->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        // root就是最近公共祖先
        else
            return root;
    }
};

int main()
{
    /*  This part is to be done.   */
}