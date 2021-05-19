/*
    301. 删除无效的括号
    给你一个由若干括号和字母组成的字符串 s ，删除最小数量的无效括号，使得输入的字符串有效。
    返回所有可能的结果。答案可以按 任意顺序 返回。
    难度：困难
    https://leetcode-cn.com/problems/remove-invalid-parentheses/

    示例 2:
    输入: "(a)())()"
    输出: ["(a)()()", "(a())()"]
*/

#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

/*
    解题思路
       深度遍历思想：对源字符串中的每一个括号都考虑删除和不删除两种情况，最后对遍历得到的字符串判断是否有效，最后保存到set中进行去重。

    剪枝思路：
    1. 在遍历前先求出可删除的左括号数目 el、可删除的右括号数目 er，将二者作为遍历参数，当 el < 0 || er < 0 时，提前终止。
    2. 将判断字符串有效的过程放到深度遍历过程中，一旦当前得到的结果字符串无效，提前终止。
       具体实现是，记录当前结果字符串中错误的 '(' 和 ')' 的数量 cntl 和 cntr，如果遍历过程中出现 cntr > cntl，则当前结果字符串无效，提前终止。
    3. 遍历结束时，当 cntl == 0 && cntr == 0，则结果字符串有效，记录结果。
*/

class Solution
{
public:
    unordered_set<string> sets;

    /*
    * @param s: 源字符串
    * @param index: 当前源字符串索引
    * @param str: 记录结果
    * @param el: 当前可以删除的'('的数量
    * @param er: 当前可以删除的')'的数量
    * @param cntl: 记录当前str中错误的'('的数量
    * @param cntr: 记录当前str中错误的')'的数量
    */
    void dfs(string &s, int index, string &str, int el, int er, int cntl, int cntr)
    {
        // 剪枝
        if (cntr > cntl || el < 0 || er < 0)
            return;
        // 结束条件
        if (index == s.length())
        {
            if (cntl == 0 && cntr == 0)
            {
                sets.insert(str);
            }
            return;
        }

        // 当前字符不是括号，直接跳过
        if (s[index] != '(' && s[index] != ')')
        {
            str += s[index];
            dfs(s, index + 1, str, el, er, cntl, cntr);
            str.erase(str.length() - 1, 1);
        }
        else
        {
            // 不删除当前括号，需要记录当前str中错误的左右括号的数量
            str += s[index];
            int cl = cntl, cr = cntr;
            if (s[index] == '(')
                cl++;
            else
            {
                if (cl == 0)
                    cr++;
                else
                    cl--;
            }
            dfs(s, index + 1, str, el, er, cl, cr);
            str.erase(str.length() - 1, 1);

            // 删除当前括号，修改可删除的左右括号数量
            if (s[index] == '(')
                --el;
            else
                --er;
            dfs(s, index + 1, str, el, er, cntl, cntr);
        }
    }

    vector<string> removeInvalidParentheses(string s)
    {
        vector<string> res;

        int el = 0; // 最少要删除l个左括号
        int er = 0; // 最少要删除r个右括号

        for (const char ch : s)
        {
            el += (ch == '(');
            if (el == 0)
            { // 落单的左括号，必须删除！
                er += (ch == ')');
            }
            else
            { // 左括号、右括号匹配
                el -= (ch == ')');
            }
        }

        string str = "";
        dfs(s, 0, str, el, er, 0, 0);

        for (auto it = sets.begin(); it != sets.end(); ++it)
        {
            res.push_back(*it);
        }

        return res;
    }
};
