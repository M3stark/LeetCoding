/*
    79. 单词搜索
    给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
    单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
    难度：中等
    链接：https://leetcode-cn.com/problems/word-search
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char> > &board, string word)
    {
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                if (dfs(board, word, i, j, 0))
                    return true;
            }   
        }
        return false;
    }

    bool dfs(vector<vector<char> > &board, string& word, int i, int j, int len) {
        if(word.size() == 0) return true;
        if(i >= board.size() || i < 0 || j >= board[0].size() || j < 0 || 
           board[i][j] != word[len] || len > word.size()) {
            return false;
        }

        if(len == word.size() - 1) return true;
        char tmp = board[i][j];
        board[i][j] = '0';
        bool res = dfs(board, word, i + 1, j, len + 1) ||
                   dfs(board, word, i, j + 1, len + 1) ||
                   dfs(board, word, i - 1, j, len + 1) ||
                   dfs(board, word, i, j - 1, len + 1);
        board[i][j] = tmp;
        return res;
    }
};