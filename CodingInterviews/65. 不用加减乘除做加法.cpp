/*
    剑指 Offer 65. 不用加减乘除做加法
    写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。
    难度：简单
    https://leetcode-cn.com/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/
*/

/*
    Notes:
        任何数 x 与 0 异或，结果为 x;
        任何数与自身异或，结果为 0;

    二进制：
    8 + 3 -> (1000) + (1101)
    =     -> (0101)        相加不进位  1000 ^ 1101 = 0101
          +  (10000)       相加进位    (1000 & 1101) << 1 = 10000
          ---------------------------------------------------------
    =        (10101)

*/

#include <iostream>

using namespace std;

class Solution
{
public:
    int add(int a, int b)
    {

        while (b) // 当没有进位的时候退出循环
        {
            int tmp = a ^ b;
            // C++ 不允许负数进行左移操作，故要加 unsigned int
            b = ((unsigned int)(a & b) << 1);
            a = tmp;
        }

        return a;
    }
};

int main()
{
    cout << "***********************************************" << endl;
    cout << "剑指 Offer 65. 不用加减乘除做加法" << endl;
    cout << "写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。" << endl;
    cout << "***********************************************" << endl;
    int a;
    int b;
    cout << "请输入a: ";
    cin >> a;
    cout << "请输入b: ";
    cin >> b;
    int res = Solution().add(a, b);
    cout << "a + b = " << res << endl;
    cout << "***********************************************" << endl;
    return 0;
}