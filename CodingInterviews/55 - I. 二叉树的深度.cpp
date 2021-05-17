/*
    剑指 Offer 55 - I. 二叉树的深度
    输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。

    例如：
    给定二叉树 [3,9,20,null,null,15,7]，
    ----------------------------------------------------------------------------------------------------------
        3
       / \
      9  20
        /  \
       15  7
    ----------------------------------------------------------------------------------------------------------
    返回它的最大深度 3 。

    难度：简单
    https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof/
*/

#include <iostream>
using namespace std;

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
    int getDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);
        return max(leftDepth, rightDepth) + 1;
    }
    int maxDepth(TreeNode *root)
    {
        return getDepth(root);
    }
};

int main()
{
    /* to be done. */
}