/*
    剑指 Offer 46. 把数字翻译成字符串
    给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，
    1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。
    一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。
    难度：中等
    https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int translateNum(int num)
    {
        if (num < 10)
            return 1;
        string s = to_string(num);
        int len = s.length();
        vector<int> dp(len + 1);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= len; ++i)
        {
            // [10, 25, 和前面的数字组合翻译
            if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '5'))
            {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            // [1, 9] && [26, 99], 只翻译自己
            else
                dp[i] = dp[i - 1];
        }

        return dp[len];
    }
};