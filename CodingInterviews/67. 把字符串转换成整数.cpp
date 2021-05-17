/*
    剑指 Offer 67. 把字符串转换成整数
    写一个函数 StrToInt，实现把字符串转换成整数这个功能。不能使用 atoi 或者其他类似的库函数。
    难度：中等
    https://leetcode-cn.com/problems/ba-zi-fu-chuan-zhuan-huan-cheng-zheng-shu-lcof/
*/

#include <iostream>
#include <string>
#include <limits.h>
#include <cctype> // isdigit

using namespace std;

/*  
    考虑情况：
     * 1. 首部空格
     * 2. 正负号
     * 3. 数字后的字母等其他元素
     * 4. 不满足直接返回0
     * 
     * isdigit() -> 判断是否是十进制数字
     */

class Solution
{
public:
    int strToInt(string str)
    {
        int i = 0, flag = 1;
        long res = 0;
        // 删掉首部空格
        while (i < str.size() && str[i] == ' ')
            i++;
        if (str[i] == '-')
            flag = -1;
        // 考虑 -+1 情况
        if (str[i] == '-' || str[i] == '+')
            i++;

        for (; i < str.length() && isdigit(str[i]); ++i)
        {
            res = res * 10 + (str[i] - '0');
            if (res >= INT_MAX && flag == 1)
                return INT_MAX;
            if (res > INT_MAX && flag == -1)
                return INT_MIN;
        }
        return res * flag;
    }
};

int main()
{
    cout << "***********************************************" << endl;
    cout << "剑指 Offer 67. 把字符串转换成整数" << endl;
    cout << "不能使用 atoi 或者其他类似的库函数。" << endl;
    cout << "***********************************************" << endl;
    string word;
    cout << "输入一个字符串: ";
    getline(cin, word);
    int res = Solution().strToInt(word);
    cout << "该字符串的整数形式: " << res << endl;
    cout << "***********************************************" << endl;
    return 0;
}