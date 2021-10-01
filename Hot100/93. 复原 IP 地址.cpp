/*
    93. 复原 IP 地址
    给定一个只包含数字的字符串，用以表示一个 IP 地址，返回所有可能从 s 获得的 有效 IP 地址 。
    你可以按任何顺序返回答案。

    有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），
    整数之间用 '.' 分隔。

    例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、
    "192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。

    难度：中等
    https://leetcode-cn.com/problems/restore-ip-addresses/
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> res;

    void backtrack(string &s, int startIdx, int PointNum)
    {
        /*
         * @param s: 原字符串
         * @param startIdx: 搜索的起始位置
         * @param PointNum: 点的数量
        */

        if (PointNum == 3)
        { // 递归终止条件: PointNum = 3
            if (isValid(s, startIdx, s.length() - 1))
            {
                // 如果第四段子字符串合法，放进res中
                res.push_back(s);
            }
            return;
        }

        for (int i = startIdx; i < s.length(); ++i)
        {
            if (isValid(s, startIdx, i))
            {
                // [startIndex,i] 合法 -> 添加 '.'
                s.insert(s.begin() + i + 1, '.');
                PointNum++;
                backtrack(s, i + 2, PointNum);
                PointNum--;
                s.erase(s.begin() + i + 1);
            }
            else
                break;
        }
    }

    bool isValid(string &s, int start, int end)
    {
        // 越界
        if (start > end)
            return false;

        // 0开头的数字不合法
        if (s[start] == '0' && start != end)
            return false;
        int num = 0;
        for (int i = start; i <= end; ++i)
        {
            // 遇到非数字字符不合法
            if (s[i] > '9' || s[i] < '0')
            {
                return false;
            }
            // 段位如果大于255了不合法
            num = num * 10 + (s[i] - '0');
            if (num > 255)
                return false;
        }
        return true;
    }
    vector<string> restoreIpAddresses(string s)
    {
        res.clear();
        backtrack(s, 0, 0);
        return res;
    }
};


int main()
{
    /* */
}