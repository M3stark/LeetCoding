/*
    剑指 Offer 49. 丑数
    我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。
    求按从小到大的顺序的第 n 个丑数。
    难度：中等
*/

#include <iostream>
#include <vector>

using namespace std;

/*
    假设当前存在 3 个数组 nums2, nums3, nums5 分别代表丑数序列从 1 开始分别乘以 2, 3, 5 的序列:
    nums2 = {1*2, 2*2, 3*2, 4*2, 5*2, 6*2, 8*2...}
    nums3 = {1*3, 2*3, 3*3, 4*3, 5*3, 6*3, 8*3...}
    nums5 = {1*5, 2*5, 3*5, 4*5, 5*5, 6*5, 8*5...}

    # 注意 7 不是丑数. 
    # 2, 3, 5 这前 3 个丑数一定要乘以其它的丑数， 所得的结果才是新的丑数， 
    所以上例中没有出现 7*2, 7*3, 7*5.
    最终的丑数序列实际上就是这 3 个有序序列对的合并结果.
*/

// 动态规划
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        // Dynamic Programming
        // dp[i] 代表第 i + 1 个丑数
        vector<int> dp(n + 1);

        // base case
        dp[0] = 1; // dp[i] 第 i 个丑数

        int twoCnt = 0, threeCnt = 0, fiveCnt = 0;

        for (int i = 1; i < n; ++i)
        {
            int u_two = dp[twoCnt] * 2;
            int u_three = dp[threeCnt] * 3;
            int u_five = dp[fiveCnt] * 5;

            dp[i] = min(min(u_two, u_three), u_five);

            if (dp[i] % 2 == 0)
                twoCnt++;
            if (dp[i] % 3 == 0)
                threeCnt++;
            if (dp[i] % 5 == 0)
                fiveCnt++;
        }

        return dp[n - 1];
    }
};

// 最小堆
/*
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> nums{2, 3, 5};
        unordered_set<long> uglySet;
        priority_queue<long, vector<long>, greater<long>> uglyQue;
        uglySet.insert(1);
        uglyQue.push(1);
        int ugly = 0;

        for (int i = 0; i < n; ++i)
        {
            long tmp = uglyQue.top();
            uglyQue.pop();
            ugly = (int)tmp;
            for (int num : nums)
            {
                long next = num * tmp;
                if (uglySet.count(next) == 0)
                {
                    uglySet.insert(next);
                    uglyQue.push(next);
                }
            }
        }
        return ugly;
    }
};
*/

int main()
{
    cout << "***********************************************" << endl;
    cout << "剑指 Offer 49. 丑数" << endl;
    cout << "***********************************************" << endl;
    int n = 0;
    cout << "请输入n: ";
    cin >> n;
    Solution a;
    int res = a.nthUglyNumber(n);
    cout << "求按从小到大的顺序的第" << n << "个丑数为：" << res << endl;
    cout << "***********************************************" << endl;
    return 0;
}