/*
    剑指 Offer 57. 和为s的两个数字
    输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。
    如果有多对数字的和等于s，则输出任意一对即可。
    难度：简单
    https://leetcode-cn.com/problems/he-wei-sde-liang-ge-shu-zi-lcof/
*/

#include <iostream>
#include <vector>

using namespace std;

/*
    思路：滑动窗口
*/

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int i = 0, j = nums.size() - 1;

        while (i < j)
        {
            if (nums[i] + nums[j] < target)
                i++;
            else if (nums[i] + nums[j] > target)
                j--;
            else
                return {nums[i], nums[j]};  // c++11
        }
        return {};
    }
};

template<typename T>
void fcin(vector<T>& v) {
    for(int i = 0; i < v.size(); ++i) {
        cin >> v[i];
    }
}

template <typename T>
void fcout(vector<T> &v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
}

/*
    g++ 57.\ 和为s的两个数字.cpp -o 57.o -std=c++11
*/

int main()
{
    cout << "***********************************************" << endl;
    cout << "剑指 Offer 57. 和为s的两个数字" << endl;
    cout << "输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。" << endl;
    cout << "如果有多对数字的和等于s，则输出任意一对即可。" << endl;
    cout << "***********************************************" << endl;
    int n;
    cout << "请输入数组大小：";
    cin >> n;
    int target;
    cout << "请输入target：";
    cin >> target;
    vector<int> vec(n);
    cout << "请输入一个数组: ";
    fcin(vec);
    vector<int> res = Solution().twoSum(vec, target);
    cout << "和为s的两个数字: ";
    fcout(res);
    cout << endl;
    cout << "***********************************************" << endl;
}