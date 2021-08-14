/*
    剑指 Offer 42. 连续子数组的最大和
    输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
    要求时间复杂度为O(n)。
    难度： 简单
    https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/
*/

#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    /*
    解法1: 贪心算法
    */
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

    /*
    解法2: 动态规划
    */

    /*
    int maxSubArray(vector<int>& nums) {
        int dp_0 = nums[0], dp_1 = 0, res = dp_0;

        for(int i = 1; i < nums.size(); ++i) {
            // 局部最大
            dp_1 = max(nums[i], nums[i]+dp_0);
            dp_0 = dp_1;
            // 全局最大
            res = res > dp_1 ? res : dp_1;
        }
        return res;
    }
    */
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
    cout << "***********************************************" << endl;

    Solution a;
    int res = a.maxSubArray(tmp);
    cout << "连续子数组的最大和:" << res << endl;
    cout << "***********************************************" << endl;

    return 0;
}