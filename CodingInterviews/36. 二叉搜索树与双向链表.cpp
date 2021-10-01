/*
    剑指 Offer 36. 二叉搜索树与双向链表
    输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。
    要求不能创建任何新的节点，只能调整树中节点指针的指向。
    难度：中等
    https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/
*/

/*
    DFS.
    二叉搜索树的中序遍历为递增序列.
    将二叉搜索树 转换成一个 “排序的循环双向链表” ，其中包含三个要素:
        > 排序链表
        > 双向链表: 设前驱节点 pre 和当前节点 cur.
          pre->right = cur && cur->left = pre;
        > 循环链表： 设链表头节点 head 和尾节点 tail,
          head->left = tail && tail->right = head;
*/

#include <iostream>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution
{
public:
    Node *head, *tail;
    Node *treeToDoublyList(Node *root)
    {
        if (!root)
            return nullptr;
        inorder(root);
        // 构建循环链表
        // 中序遍历完成后，head 指向头节点， tail 指向尾节
        head->left = tail;
        tail->right = head;
        return head;
    }

    void inorder(Node *root)
    {
        if (!root)
            return;

        // left
        inorder(root->left);

        // mid
        if (!tail)
        {
            // 代表正在访问链表头节点
            head = root;
        }
        else
        {
            // 修改双向节点引用
            tail->right = root;
            root->left = tail;
        }
        // 更新 tail
        tail = root;

        // right
        inorder(root->right);
    }
};