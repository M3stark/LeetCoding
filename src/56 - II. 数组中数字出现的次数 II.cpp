/*
    剑指 Offer 56 - II. 数组中数字出现的次数 II
    在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。
    难度：中等
    https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
    思路1: map
*/

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        map<int, int> mp;
        for (int i : nums)
            mp[i]++;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (mp[nums[i]] == 1)
                return nums[i];
        }
        return -1;
    }
};

/*
    思路2: 位运算
*/

template <typename T>
void fcin(vector<T> &v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        cin >> v[i];
    }
}

int main()
{
    cout << "***********************************************" << endl;
    cout << "剑指 Offer 56 - II. 数组中数字出现的次数 II" << endl;
    cout << "在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。" << endl;
    cout << "***********************************************" << endl;
    int n;
    cout << "请输入数组大小：";
    cin >> n;
    vector<int> vec(n);
    cout << "请输入一个数组: ";
    fcin(vec);
    int res = Solution().singleNumber(vec);
    cout << "只出现一次的数字: " << endl;
    cout << "***********************************************" << endl;
    return 0;
}