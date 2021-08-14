/*
    剑指 Offer 48. 最长不含重复字符的子字符串
    请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
    https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/
*/


#include <iostream>
#include <string>

using namespace std;

/*
    滑动窗口
    时间复杂度：O(N^2)
    空间复杂度：O(1)
*/
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int start = 0, end = 0, len = 0, res = 0;
        if (s.length() == 0)
            return res;

        while (end < s.length())
        {
            char ch = s[end];

            for (int i = start; i < end; ++i)
            {
                if (s[i] == ch)
                {
                    start = i + 1;
                    len = end - start;
                    break;
                }
            }
            end++;
            len++;
            res = res > len ? res : len;
        }
        return res;
    }
};

/*
    优化的滑动窗口（哈希表）
    时间复杂度：O(N)
    空间复杂度：O(N)


class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // 哈希表记录每个字符的下一个索引
        map<char, int> mp;
        int res = 0, start = 0, end = 0;
        while (end < s.length())
        {
            if (mp.find(s[end]) != mp.end())
            {                                     // 尾指针指向的元素重复
                start = max(start, ++mp[s[end]]); // 头指针直接移动到窗口中重复元素的右侧
            }
            mp[s[end++]] = end;
            res = max(res, end - start);
        }
        return res;
    }
};

*/

int main() {
    cout << "***********************************************" << endl;
    cout << "剑指 Offer 48. 最长不含重复字符的子字符串" << endl;
    cout << "请从字符串中找出一个最长的不包含重复字符的子字符串, " << endl;
    cout << "计算该最长子字符串的长度。" << endl;
    cout << "***********************************************" << endl;
    string word;
    cout << "输入一个字符串: ";
    cin >> word;
    cout << "***********************************************" << endl;
    Solution a;

    int res = a.lengthOfLongestSubstring(word);
    cout << "长子字符串的长度：" << res << endl;
    cout << "***********************************************" << endl;
}