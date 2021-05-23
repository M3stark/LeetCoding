/*
    剑指 Offer 37. 序列化二叉树
    请实现两个函数，分别用来序列化和反序列化二叉树。
    难度：困难
    https://leetcode-cn.com/problems/xu-lie-hua-er-cha-shu-lcof/

    示例: 
    你可以将以下二叉树：

         1
        / \
       2   3
      /     \
     4       5

    序列化为 "[1,2,3,null,null,4,5]"
*/

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string res = "";
        dfs1(root, res);
        return res;
    }

    void dfs1(TreeNode *root, string &res)
    {
        if (!root)
        {
            // #
            res += "# ";
            return;
        }

        res += to_string(root->val) + ",";
        dfs1(root->left, res);
        dfs1(root->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        int idx = 0;
        return dfs2(data, idx);
    }

    TreeNode *dfs2(string &data, int &idx)
    {
        // 空节点
        if (data[idx] == '#')
        {
            idx += 2;
            return nullptr;
        }

        // 非空节点
        int num = 0;
        int flag = 1; // 符号
        while (data[idx] != ',')
        {
            if (data[idx] == '-')
                flag = -1;
            else
                num = num * 10 + (data[idx] - '0');
            idx++;
        }

        num *= flag;
        idx++; // 下一个数

        auto root = new TreeNode(num);
        root->left = dfs2(data, idx);
        root->right = dfs2(data, idx);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));


int main()
{
    /*    */
}