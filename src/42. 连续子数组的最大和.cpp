/*
    剑指 Offer 42. 连续子数组的最大和
    输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
    要求时间复杂度为O(n)。
    https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/
*/

#include <iostream>
#include <vector>

using namespace std;

/*
    解法1: 贪心算法
*/
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int res = nums[0];
        int sum = 0;
        for (int n : nums)
        {
            if (sum <= 0)
                sum = n;
            else
                sum += n;
            res = sum > res ? sum : res;
        }
        return res;
    }
};


// 输入一个vector
template<typename T>
void fcin(vector<T>& v) {
    for(int i = 0; i < v.size(); ++i) {
        cin >> v[i];
    }
}


int main()
{
    cout << "***********************************************" << endl;
    cout << "剑指 Offer 42. 连续子数组的最大和" << endl;
    cout << "***********************************************" << endl;
    int n;
    cout << "请输入数组大小：";
    cin >> n;
    vector<int> tmp(n);
    cout << "请输入一个数组: ";
    fcin(tmp);

    Solution a;
    int res = a.maxSubArray(tmp);
    cout << "连续子数组的最大和:" << res << endl;

    return 0;
}