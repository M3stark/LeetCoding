/*
    剑指 Offer 44. 数字序列中某一位的数字
    数字以0123456789101112131415…的格式序列化到一个字符序列中。
    在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。
    请写一个函数，求任意第n位对应的数字。
    难度：中等
    https://leetcode-cn.com/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof/
*/

/*
    123456789           10 11 12 .. 98 99           100 101 ... 998 999
      9个数                     90个数                      900个数
      9*1位数字                 90*2位数字                   900*3位数字
*/

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int findNthDigit(int n)
    {
        if (n == 0)
            return 0;

        int digit = 1;  // 数位（个/十/百）
        long start = 1; // 该位的起始数（1/10/100）
        long count = 9; // 该数位一共有多少位数字   digit * (9 / 90 / 900)
        while (n > count)
        {
            // 找到n 对应的数位索引
            n -= count;
            digit++;
            start *= 10;
            count = digit * start * 9;
        }
        //  n 等于在当前数位里的第 n - 1 个索引
        long num = start + (n - 1) / digit; // 原始的n对应哪个数字
        int remainder = (n - 1) % digit;    // 余数，原始n对应这个数字的第几位

        string s_num = to_string(num);
        return int(s_num[remainder] - '0');
    }
};