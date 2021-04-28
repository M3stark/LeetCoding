/*
    剑指 Offer 58 - II. 左旋转字符串
    字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
    请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。
    难度：简单
    链接：https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof
*/

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string reverseLeftWords(string s, int n)
    {
        for (int i = 0; i < n; ++i)
        {
            s += s[i];
        }
        s.erase(0, n);
        return s;
    }
};

int main()
{
    cout << "***********************************************" << endl;
    cout << "58 - II. 左旋转字符串" << endl;
    cout << "字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。" << endl;
    cout << "***********************************************" << endl;
    string word;
    cout << "输入一个字符串: ";
    getline(cin, word); // 输入包括空格
    int n; 
    cout << "请输入一个数字: ";
    cin >> n;
    cout << "***********************************************" << endl;
    string res = Solution().reverseLeftWords(word, n);
    cout << "左旋转字符串: '";
    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i];
    }
    cout << "'" << endl;
    cout << "***********************************************" << endl;

    return 0;
}