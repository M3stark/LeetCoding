/*
    剑指 Offer 50. 第一个只出现一次的字符
    在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。
    难度：简单
    https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/
*/

#include <iostream>
#include <vector>
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
        vector<int> dict(26, 0);

        for (const char ch : s)
        {
            dict[ch - 'a']++;
        }

        for (const char ch : s)
        {
            if (dict[ch - 'a'] == 1)
            {
                return ch;
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