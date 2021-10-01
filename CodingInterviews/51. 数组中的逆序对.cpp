/*
    剑指 Offer 51. 数组中的逆序对
    在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
    输入一个数组，求出这个数组中的逆序对的总数。
    难度：困难
    https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        // 本题用 并归排序， 顺便计算逆序对
        vector<int> temp(nums.size());      // 辅助数组
        return mergeSort(nums, temp, 0, nums.size() - 1);
    }

private:
    int mergeSort(vector<int> &nums, vector<int> &temp, int left, int right)
    {
        if (left >= right)
            return 0;

        int mid = (left + right) >> 1;
        int res = mergeSort(nums, temp, left, mid) + mergeSort(nums, temp, mid + 1, right);

        int i = left, j = mid + 1;
        for (int k = left; k <= right; ++k)
            temp[k] = nums[k]; 

        for (int k = left; k <= right; ++k)
        {
            if (i == mid + 1)
                nums[k] = temp[j++]; // 左边满了
            else if (j == right + 1)
                nums[k] = temp[i++]; // 右边满了
            else if (temp[i] <= temp[j])
                nums[k] = temp[i++];    // 左边小
            else
            {
                nums[k] = temp[j++];    // 右边小，构成逆序对
                res += (mid - i + 1);
            }
        }
        return res;
    }
};