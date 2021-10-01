/*
    剑指 Offer 19. 正则表达式匹配
    请实现一个函数用来匹配包含'. '和'*'的正则表达式。
    模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。
    在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，
    但与"aa.a"和"ab*a"均不匹配。
    难度：困难
    https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;



// 方法1:  DFS
/*
class Solution
{
public:
    bool isMatch(string s, string p) {
        // p 为空
        if(p.empty()) {
            return s.empty();
        }

        // 首元素是否一致
        bool firstMatch = !s.empty() && (s[0] == p[0] || p[0] == '.');

        // 下一个字符是 '*'
        if (p.size() > 1 && p[1] == '*') // 保证 p[1] 取得到
        {   
            // s = 'bb',    p = 'a*bb'
            // s = 'aabb',  p = 'a*bb'
            return (bool)(isMatch(s, p.substr(2)) || firstMatch && isMatch(s.substr(1), p));
        }
        else {
            return bool( firstMatch && isMatch(s.substr(1), p.substr(1)));
        }
    }

};
*/

// 方法2: 动态规划

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int sLen = s.length(), pLen = p.length();
        // dp
        vector<vector<bool> > dp(sLen + 1, vector<bool>(pLen + 1, false));
        // base case
        dp[0][0] = true;
        // init
        for (int i = 1; i <= pLen; ++i)
        {
            if (p[i - 1] == '*')
                dp[0][i] = dp[0][i - 2]; // 判断初始匹配位置
        }

        for (int i = 1; i <= sLen; ++i)
        {
            for (int j = 1; j <= pLen; ++j)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                {
                    // s = 'b', p = 'a*'
                    if (p[j - 2] != s[i - 1] && p[j - 2] != '.')
                        dp[i][j] = dp[i][j - 2];
                    else //
                         // p[j - 2] == s[i - 1]  | s = 'b', p = 'b*' | 匹配0次
                         // p[j - 2] == '.' | s = 'abb', p = 'a.*'  ｜ 匹配多次
                        dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
                }
                else
                    dp[i][j] = false;
            }
        }
        return dp[sLen][pLen];
    }
};
