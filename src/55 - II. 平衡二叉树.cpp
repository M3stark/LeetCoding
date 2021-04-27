/*
    剑指 Offer 55 - II. 平衡二叉树
    输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。

    例如：
    给定二叉树 [3,9,20,null,null,15,7]，
    ----------------------------------------------------------------------------------------------------------
        3
       / \
      9  20
        /  \
       15  7
    ----------------------------------------------------------------------------------------------------------
    返回 true 。

    难度：简单
    https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
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
        int l = getDepth(root->left);
        if (l == -1)
            return -1;
        int r = getDepth(root->right);
        if (r == -1)
            return -1;
        return abs(l - r) > 1 ? -1 : max(l, r) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        return getDepth(root) == -1 ? false : true;
    }
};

int main()
{
    /* to be done. */
}

