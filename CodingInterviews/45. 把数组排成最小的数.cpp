/*
    剑指 Offer 45. 把数组排成最小的数
    输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
    难度：中等
    https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string minNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), [=](const int a, const int b) -> bool {
            string sa = to_string(a);
            string sb = to_string(b);
            return sa + sb < sb + sa;
        });

        string res = "";
        for (int num : nums)
            res += to_string(num);
        return res;
    }
};

template<typename T>
void fcin(vector<T> &v) {
    for(int i = 0; i < v.size(); ++i) {
        cin >> v[i];
    }
}

/*
    请使用 c++11编译本段代码
    g++ 45.\ 把数组排成最小的数.cpp -o 45.o -std=c++11
*/

int main()
{
    cout << "***********************************************" << endl;
    cout << "剑指 Offer 45. 把数组排成最小的数" << endl;
    cout << "***********************************************" << endl;
    int n;
    cout << "请输入数组大小：";
    cin >> n;
    vector<int> tmp(n);
    cout << "请输入一个数组: ";
    fcin(tmp);
    cout << "***********************************************" << endl;

    Solution a;
    string res = a.minNumber(tmp);
    cout << "数组排成最小的数: " << res << endl;
    return 0;
}