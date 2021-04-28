/*
    剑指 Offer 58 - I. 翻转单词顺序
    输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。
    例如输入字符串"I am a student. "，则输出"student. a am I"。
    难度：简单
    链接：https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


class Solution
{
public:
    string reverseWords(string s)
    {
        string res;
        int i = 0;
        while (i < s.size())
        {
            while (i < s.size() && s[i] == ' ')
                i++;
            int j = i;
            while (j < s.size() && s[j] != ' ')
                j++;
            if (j > i)
            {
                string sub = s.substr(i, j - i);
                reverse(sub.begin(), sub.end());
                if (res.size())
                    res += ' ';
                res += sub;
            }
            i = j;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};



int main()
{
    cout << "***********************************************" << endl;
    cout << "58 - I. 翻转单词顺序" << endl;
    cout << "输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。" << endl;
    cout << "为简单起见，标点符号和普通字母一样处理。" << endl;
    cout << "***********************************************" << endl;
    string word;
    cout << "输入一个字符串: ";
    getline(cin, word);     // 输入包括空格
    cout << "***********************************************" << endl;
    string res = Solution().reverseWords(word);
    cout << "翻转单词顺序: '";
    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i];
    }
    cout << "'" << endl;
    cout << "***********************************************" << endl;

    return 0;
}