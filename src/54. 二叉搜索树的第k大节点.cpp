/*
    剑指 Offer 54. 二叉搜索树的第k大节点
    给定一棵二叉搜索树，请找出其中第k大的节点。
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

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int res = 0, cnt = 0;
    int kthLargest(TreeNode *root, int k)
    {
        dfs(root, k);
        return res;
    }

    void dfs(TreeNode *root, int k)
    {
        if (root == nullptr)
            return;
        dfs(root->right, k);
        cnt++;
        if (cnt == k)
        {
            res = root->val;
            return;
        }
        dfs(root->left, k);
    }
};

int main()
{
    /* to be done. */
}