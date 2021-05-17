/*
    1. 两数之和
    给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，
    并返回它们的数组下标。
    你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
    难度：简单
    https://leetcode-cn.com/problems/two-sum/
*/

/*  有人相爱，有人夜里开车看海，有人leetcode第一题都做不出来。  */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std; // namespace std;


class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i)
            mp[nums[i]] = i;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (mp[target - nums[i]] && mp[target - nums[i]] != i)
            {
                /*
                generalized initializer lists are a C++11 extension [-Wc++11-extensions]
                non-aggregate type 'vector<int>' cannot be initialized with an initializer list
                */
                return {i, mp[target - nums[i]]};
                break;
            }
        }

        return {};
    }
};

// cin
template <typename T>
void fcin(vector<T>& v) {
    for(int i = 0; i < v.size(); ++i) {
        cin >> v[i];
    }
}

int main() {
    cout << "***********************************************" << endl;
    cout << "剑指 Offer 42. 连续子数组的最大和" << endl;
    cout << "有人相爱，有人夜里开车看海，有人leetcode第一题都做不出来。" << endl;
    cout << "***********************************************" << endl;

    int n;
    cout << "请输入数组大小：";
    cin >> n;
    vector<int> tmp(n);
    cout << "请输入一个数组: ";
    fcin(tmp);
    int target;
    cout << "请输入一个target: ";
    cin >> target; 
    cout << "***********************************************" << endl;

    Solution a;
    vector<int> res = a.twoSum(tmp, target);
    cout << "两数之和为" << target << "的数为: " << res[0] << ", " << res[1] << endl;

    return 0;
}

/*
    Usage:
    g++ 1.\ 两数之和.cpp -o 1 -std=c++11
*/