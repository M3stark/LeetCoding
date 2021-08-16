//
// Created by Mike on 2021/8/16.
//

/*
 * 101. 对称二叉树
 * 给定一个二叉树，检查它是否是镜像对称的。
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    /*
     * 递归法
     */
    bool camp(TreeNode* left, TreeNode* right) {
        if(!left && !right) {
            return true;
        } else if( (!left && right) || (left && !right) || left->val != right->val) {
            return false;
        }
        return camp(left->left, right->right) && camp(left->right, right->left);
    }
//    bool isSymmetric(TreeNode* root) {
//        if(!root) return true;
//        return camp(root->left, root->right);
//    }

    /*
     * 迭代法
     */
    bool helper(TreeNode* left, TreeNode* right) {
        queue<TreeNode*> que;
        que.push(left);
        que.push(right);

        while (!que.empty()) {
            TreeNode* p = que.front();
            que.pop();
            TreeNode* q = que.front();
            que.pop();

            if(!p && !q) continue;
            else if(!p || !q || p->val != q->val) return false;

            que.push(p->left);
            que.push(q->right);
            que.push(p->right);
            que.push(q->left);
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        return helper(root->left, root->right);
    }

};
