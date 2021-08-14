/*
    剑指 Offer 53 - I. 在排序数组中查找数字 I
    统计一个数字在排序数组中出现的次数。
    难度：简单
    https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/
*/

/*
    二分法思路：
    * 假设存在边界为 left 和 right, 满足 nums[left] < target && nums[right] > target
    * 我们要找到满足条件最大的left和最小的right
    * 对应的窗口大小就是 right - left - 1
    * 时间复杂度：O（logN）
    * 空间复杂度：O（1）
*/

#include <iostream>
#include <vector>

using namespace std;

/*  二分法  */
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        if (nums.empty())
            return 0;

        int i = 0, j = nums.size() - 1; // 二分法的左右指针

        while (i <= j)
        { // 第一次二分法求出右边界
            int m = (i + j) >> 1;
            // 正是i = j 时的这最后这次循环，i又右移了一次使得i成为右边界
            if (nums[m] < target) // target在 [m+1, j]中
                i = m + 1;        // target在 [i, m-1]中
            else if (nums[m] > target)
            {
                j = m - 1;
            }
            else
            { // 查找右边界   (跳出时指向右边界)
                i = m + 1;
            }
        }

        int right = i;

        // 如果j位置不是target，说明数组中无target，提前返回
        if (j >= 0 && nums[j] != target)
            return 0;

        j = i, i = 0; // 重置左右指针；右指针重置为右边界，减少下次二分的区间
        while (i <= j)
        { // 第二次二分法求出左边界
            int m = (i + j) >> 1;
            // 正是i = j时的这最后这次循环，j又左移了一次使得j成为左边界
            if (nums[m] < target)
                i = m + 1;
            else if (nums[m] > target)
            {
                j = m - 1;
            }
            else
            { // 查找左边界
                j = m - 1;
            }
        }

        int left = j;

        return right - left - 1;
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
    cout << "剑指 Offer 53 - I. 在排序数组中查找数字 I" << endl;
    cout << "统计一个数字在排序数组中出现的次数。" << endl;
    cout << "***********************************************" << endl;
    int n;
    cout << "请输入数组大小：";
    cin >> n;
    vector<int> vec(n);
    fcin(vec);
    int target = 0;
    cout << "请输入target：";
    cin >> target;
    Solution a;
    int res = a.search(vec, target);
    cout << target << " 在排序数组中出现的次数: " << res << endl;
    cout << "***********************************************" << endl;
}