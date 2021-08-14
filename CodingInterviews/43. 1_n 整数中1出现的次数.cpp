/*
    剑指 Offer 43. 1～n 整数中 1 出现的次数
    输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。
    难度： 困难
    https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/
*/

#include <iostream>
using namespace std;

class Solution
{
public: 
    int countDigitOne(int n)
    {
        /*
            找规律
            * n的位数为k, 则该数字字符串为X(k)X(k-1)...X(1)
            * 令X(i) 前半部分 X(k)X(k-1)...X(i+1) 为 h
            * 令X(i)后半部分 X(i-1)X(i-2)...X(1) 为 l
            * i对应的位数为 10^(i-1)的基数为 base

            * 1. X(i) == 0 (cur)
                * 比如 210 中的 0， 则 h 有 1, 11, 21, 31, .. , 201 共21个， base是1
                * 意思就是前面的后退一个, 有1的次数： h * base
            
            * 2. X(i) = 2 ~ 9
                * 比如 212 中的 2， 则 h 有 1, 11, 21, 31, .. , 201, 211 共22个， base是1
                * (h+1) * base
            
            * 3. X(i) = 1
                * 要考虑 base 和 l， base 和 h      
                * 比如 312 中的 1， h = 3, l = 2, base = 10, X(i) = 1:
                    * 对于 l， 11， 12， 一共2个 (l个)
                    * 对于 h， 和情况1一样，一共 h * base (和301一样)
                    * 对于 X(i)， 就是1
                    * 加起来： l + h * base + 1
        */
        long base = 1;
        int res = 0;

        while (base <= n)
        {
            int low = n % base;
            int high = n / base;
            int cur = high % 10;
            high /= 10;

            if (cur < 1)
            {
                res += high * base;
            }
            else if (cur > 1)
            {
                res += ((high + 1) * base);
            }
            else
            {
                res += (high * base + low + 1);
            }
            base *= 10;
        }
        return res;
    }
};

int main()
{
    cout << "***********************************************" << endl;
    cout << "剑指 Offer 43. 1～n 整数中 1 出现的次数" << endl;
    cout << "***********************************************" << endl;
    int n;
    cout << "请输入整数n：";
    cin >> n;
    
    Solution a;
    int res = a.countDigitOne(n);
    cout << "1～n 整数中 1 出现的次数: " << res << endl;
    cout << "***********************************************" << endl;
    return 0;
}