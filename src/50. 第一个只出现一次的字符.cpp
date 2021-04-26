/*
    剑指 Offer 50. 第一个只出现一次的字符
    在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。
    难度：简单
    https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/
*/

#include <iostream>
#include <string>

using namespace std;

/*
    用int保存所有的字母出现的次数
*/

class Solution
{
public:
    char firstUniqChar(string s)
    {
        int a[26] = {};
        for (char ch : s)
            a[ch - 'a']++;

        for (char c : s)
        {
            if (a[c - 'a'] == 1)
            {
                return c;
                break;
            }
        }
        return ' ';
    }
};

/*
    请使用 C++11编译
    g++ 50.\ 第一个只出现一次的字符.cpp -o 50.o -std=c++11
*/

int main()
{
    cout << "***********************************************" << endl;
    cout << "剑指 Offer 50. 第一个只出现一次的字符" << endl;
    cout << "在字符串 s 中找出第一个只出现一次的字符。" << endl;
    cout << "如果没有，返回一个单空格。 s 只包含小写字母。" << endl;
    cout << "***********************************************" << endl;
    cout << "请输入一个字符串s：";
    string s;
    cin >> s;

    Solution a;
    char res = a.firstUniqChar(s);
    cout << "s中第一个只出现一次的字符: " << res << endl;
    cout << "***********************************************" << endl;
    return 0;
}