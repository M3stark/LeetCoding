/*
    剑指 Offer 39. 数组中出现次数超过一半的数字
    数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
    你可以假设数组是非空的，并且给定的数组总是存在多数元素。
    https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/

    ACM模板（3）输入输出（整数、Vector）
    https://blog.csdn.net/nameofcsdn/article/details/106796449
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {

        int num = nums[0];
        int idx = 1;

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == num)
                idx++;
            else
                idx--;

            if (idx < 0)
            {
                num = nums[i];
                idx = 1;
            }
        }
        return num;
    }
};

// ACM 模式 输入一个一维vector
template<typename T>
void fcin(vector<T>& v) {
    for(int i = 0; i < v.size(); ++i) {
        cin >> v[i];
    }
}

// ACM 模式 输出一个一维vector
template <typename T>
void fcout(vector<T> &v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

int main() {
    cout << "***********************************************" << endl;
    cout << "剑指 Offer 39. 数组中出现次数超过一半的数字" << endl;
    cout << "***********************************************" << endl;
    int n = 9;
    vector <int> tmp(n);    // 需要指定vector大小
    cout << "请输入一个数组(大小为" << n << "): ";
    fcin(tmp);
    Solution a;
    int ans = a.majorityElement(tmp);
    cout << "***********************************************" << endl;
    cout << "数组中出现次数超过一半的数字: " << ans << endl;
    cout << "***********************************************" << endl;
}