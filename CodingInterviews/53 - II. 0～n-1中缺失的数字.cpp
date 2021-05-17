/*
    剑指 Offer 53 - II. 0～n-1中缺失的数字
    一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。
    难度：简单
    链接：https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof
*/

/*
    排序数组中的搜索问题，首先想到 二分法 解决。
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int i = 0, j = nums.size() - 1;

        while (i <= j)
        {
            int m = (i + j) >> 1;
            // 因为nums递增，不相等的时候必然在右边
            if (nums[m] == m)   
                i = m + 1;
            else
                j = m - 1;
        }
        return i;
    }
};

template<typename T>
void fcin(vector<T>& v) {
    for(int i = 0; i < v.size(); ++i) {
        cin >> v[i];
    }
}

int main()
{
    cout << "***********************************************" << endl;
    cout << "剑指 Offer 53 - II. 0～n-1中缺失的数字" << endl;
    cout << "一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。" << endl;
    cout << "在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。" << endl;
    cout << "***********************************************" << endl;
    int n;
    cout << "请输入数组大小：";
    cin >> n;
    vector<int> vec(n);
    fcin(vec);

    Solution a;
    int res = a.missingNumber(vec);
    cout << "数组缺少的元素: " << res << endl;
    cout << "***********************************************" << endl;
}