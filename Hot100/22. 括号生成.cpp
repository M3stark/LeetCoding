/*
    22. 括号生成
    数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
    难度：中等
    https://leetcode-cn.com/problems/generate-parentheses/
*/

#include <iostream>
#include <vector>

using namespace std; // namespace std;



class Solution
{
public:
    vector<string> res;

    vector<string> generateParenthesis(int n)
    {
        string s = "";
        dfs(n, n, s);
        return res;
    }

    void dfs(int left, int right, string s) {
        if(left == 0 && right == 0) {
            res.push_back(s);
            return;
        }

        if(left > 0) dfs(left - 1, right, s + '(');
        if(right > 0 && left < right) dfs(left, right - 1, s + ')');
    }
};

int main()
{
    /*  To be done. */
}