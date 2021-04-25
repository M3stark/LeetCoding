/*
    剑指 Offer 40. 最小的k个数
    输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。
    难度： 简单
    https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/

*/

/*
    补充：最大堆/最小堆
    头文件：#include <queue>
    声明形式为：priority_queue< type, container, function>;
    构建大顶堆：
        priority_queue<int> max_heap;
        或者 priority_queue<int,vector<int>,less<int> > max_heap;
    构建小顶堆：
        priority_queue<int,vector<int>,greater<int> > min_heap;
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
    // 解法1: 快速选择
public:
    vector<int> res;
    vector<int> getLeastNumbers(vector<int> &arr, int k)
    {
        // 快速选择,相当于一个“不完全”的快速排序
        // 找前 K 大/前 K 小问题不需要对整个数组进行 O(NlogN) 的排序
        // 直接通过快排切分排好第 K 小的数（下标为 K-1），
        // 那么它左边的数就是比它小的另外 K-1 个数

        if (arr.size() == 0 || k == 0)
            return res;

        return quickSelect(arr, 0, arr.size() - 1, k - 1);
    }

    vector<int> quickSelect(vector<int> &arr, int i, int j, int k)
    {
        int idx = partition(arr, i, j);
        if (idx == k)
        { // 若 j 刚好等于 k - 1，将 arr[0] 至 arr[j] 输入 res
            for (int i = 0; i < k + 1; ++i)
                res.push_back(arr[i]);
            return res;
        }
        else if (idx < k)
            return quickSelect(arr, idx + 1, j, k);
        else
            return quickSelect(arr, i, idx - 1, k);
    }

    int partition(vector<int> &arr, int left, int right)
    {
        // 将函数区间所有小于下标为j的数放在j的左侧，~放在j的右侧
        // 和快速排序中partition一样
        int val = arr[left]; // 最左边的数，基准数
        while (left < right)
        {
            // 找到一个小于基准数的数
            while (left < right && arr[right] >= val)
                right--;
            arr[left] = arr[right];
            // 找到一个大于基准数的数
            while (left < right && arr[left] <= val)
                left++;
            arr[right] = arr[left];
        }
        // left 左侧都比他小
        arr[left] = val;
        return left;
    }
};

/*
class Solution {
public:
    // 解法2: 大顶堆
    vector<int> getLeastNumbers(vector<int> &arr, int k) {
        vector<int> res(k);
        priority_queue<int> max_heap;
        
        for(int i = 0; i < k; ++i) {
            max_heap.push(arr[i]);
        }

        for(int i = k; i < arr.size(); ++i) {
            if(arr[i] < max_heap.top()) {
                max_heap.pop();
                max_heap.push(arr[i]);
            }
        }

        for(int i = 0; i < k; ++i) {
            res[i] = max_heap.top();
            max_heap.pop();
        }
        return res;
    }
};
*/

// ACM 模式 输入一个一维vector
template <typename T>
void fcin(vector<T> &v)
{
    for (int i = 0; i < v.size(); ++i)
    {
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
    cout << "剑指 Offer 40. 最小的k个数" << endl;
    cout << "***********************************************" << endl;
    int n = 5;
    vector<int> tmp(n);     // 输入 n 个
    cout << "请输入一个数组(大小为" << n << "): ";
    fcin(tmp);
    int k;
    cout << "请输入k: ";
    cin >> k;
    Solution b;
    vector<int> res(k);
    res = b.getLeastNumbers(tmp, k);
    cout << "最小的k个数为: ";
    fcout(res);
    cout << "***********************************************" << endl;

    return 0;
}
