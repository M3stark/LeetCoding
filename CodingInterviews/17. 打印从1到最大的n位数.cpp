/*
    剑指 Offer 17. 打印从1到最大的n位数
    输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。
    比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
    难度：简单
    https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/
*/

/*
    Note:
    其实本题挺难的。
    >   首先要考虑到当n很大的时候（比如100），打印出来的数很有可能是超过了INT_MAX的范围的...
        用字符串来表示每个数.
    >   然后考虑吧 ‘001’ 的情况，不写 '00' 而是直接写 '1'.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> output;
    vector<int> printNumbers(int n)
    {
        // if n = 3
        if (n <= 0)
            return output;
        string s(n, '0');
        while (!overflow(s))
            inputNum(s);
        return output;
    }

    bool overflow(string &s)
    {
        // 999 + 1 = 1000, 越界
        bool isOverflow = false;
        int carry = 0; // 进位
        for (int i = s.length() - 1; i >= 0; --i)
        {
            int current = s[i] - '0' + carry; // current表示当前这次的操作
            if (i == s.length() - 1)
                current++; // 如果i此时在个位，current执行 +1 操作
            if (current >= 10)
            {
                // 假如i已经在最大的那一位了，而current++之后>=10，说明循环到头了，即999 + 1 = 1000
                if (i == 0)
                {
                    isOverflow = true;
                }
                else
                {
                    // 只是普通进位，比如current从9变成10
                    carry = 1;
                    s[i] = current - 10 + '0';
                }
            }
            else
            {
                // 没有越界
                s[i] = current + '0';
                break;
            }
        }
        return isOverflow;
    }

    void inputNum(string s)
    {
        // 0 0 1
        // 本函数用于循环往output中添加符合传统阅读习惯的元素。比如001，我们会添加1而不是001。
        bool noZero = true; // 判断是否 拒绝添加的0，比如001前面的两个0
        string temp = "";
        for (int i = 0; i < s.length(); ++i)
        {
            if (noZero && s[i] != '0')
                noZero = false;
            if (!noZero)
                temp += s[i];
        }
        output.push_back(stoi(temp));
    }
};