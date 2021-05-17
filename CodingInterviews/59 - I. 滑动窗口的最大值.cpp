/*
    剑指 Offer 59 - I. 滑动窗口的最大值
    给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。

    示例:
    输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
    输出: [3,3,5,5,6,7] 
    解释: 
    ----------------------------------------------------------
     滑动窗口的位置                最大值
    ---------------               -----
    [1  3  -1] -3  5  3  6  7       3
    1 [3  -1  -3] 5  3  6  7       3
    1  3 [-1  -3  5] 3  6  7       5
    1  3  -1 [-3  5  3] 6  7       5
    1  3  -1  -3 [5  3  6] 7       6
    1  3  -1  -3  5 [3  6  7]      7
    ----------------------------------------------------------

    难度：困难
    https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    /*
            设计一个队列：
                - 放进去窗口里的元素，然后随着窗口的移动，队列也一进一出；
                - 每次移动之后，队列告诉我们里面的最大值是什么；
    */
    class Queue
    {
    public:
        deque<int> que;
        void pop(int value)
        {
            if (!que.empty() && value == que.front())
            {
                // 最大值要离开这个窗口了，才把它pop掉
                que.pop_front();
            }
        }

        void push(int value)
        {
            // 滑动窗口添加元素的数值
            // 遇到比窗口中的值大，把小的都pop掉
            while (!que.empty() && value > que.back())
            {
                que.pop_back();
            }
            que.push_back(value);
        }

        int front()
        {
            // 返回最大值
            return que.front();
        }
    };

    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;
        if (nums.size() == 0 || k <= 0)
            return res;

        Queue que;

        for (int i = 0; i < k; ++i)
        {
            que.push(nums[i]);
        }
        res.push_back(que.front());

        for (int i = k; i < nums.size(); ++i)
        {
            que.pop(nums[i - k]);
            que.push(nums[i]);
            res.push_back(que.front());
        }
        return res;
    }
};

// ACM模式 数组输入
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
    cout << "剑指 Offer 59 - I. 滑动窗口的最大值" << endl;
    cout << "给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。" << endl;
    cout << "***********************************************" << endl;
    int n;
    cout << "数组 nums大小: ";
    cin >> n;
    cout << "给定一个数组 nums: ";
    vector<int> vec(n);
    fcin(vec);
    cout << "滑动窗口大小: ";
    int k;
    cin >> k;
    vector<int> res = Solution().maxSlidingWindow(vec, k);

    cout << "滑动窗口的最大值: [";
    for(int i = 0; i < res.size() - 1; ++i) {
        cout << res[i] << ",";
    }
    cout << res[res.size() - 1] << "]" << endl;
    return 0;
}