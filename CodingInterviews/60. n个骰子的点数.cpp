/*
    剑指 Offer 60. n个骰子的点数
    把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。
    你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。
    难度：中等
    https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof/
*/

/*
    Notes:
    - 投掷 n 个骰子，一共会有 6 的 n 次方 种结果，且每种结果都是等可能事件。
    - 投掷 n 个骰子，那么就会有 n 个面朝上，这 n 个朝上的面的点数之和 s 的最大值是 6n，
      最小值是 n。故投掷 n 个骰子，s 一共有 6n - n + 1 个可能的值。
    - s 的每一个可能值的概率等于：这个值出现的次数（可表示为 #s，即 the number of s） / 6 的 n 次方。
*/


/*
    解题思路
    dp[n][s]: 表示投掷 n 个骰子，n 个朝上的面的点数之和为 s 的事件出现的次数;
    转移方程：dp[n][s] += dp[n - 1][s - k]，k 属于 [1, 6];
        - eg. dp[3][8] 表示投掷 3 个骰子，3 个朝上的面的点数之和为 8 的事件出现的次数,
              dp[3][8] 可转移为求只投掷 2 个骰子，2 个朝上的面的点数之和分别为 7、6、5、4、3、2 的事件的次数之和。
    转移方程的前提条件是要保证 s - k > 0，因为没有骰子能投掷出小于等于 0 的点数。
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
    vector<double> dicesProbability(int n)
    {
        // 投掷 n 个骰子，s一共有 6n - n + 1 个可能的值
        vector<double> res(n * 6 - n + 1);  // 最小为n
        vector<vector<int> > dp(n + 1, vector<int>(6 * n + 1, 0));

        int row = dp.size(), col = dp[0].size();

        for (int n = 1; n <= 6; ++n)
        {
            // 初始化 dp 数组
            dp[1][n] = 1;
        }

        for (int n = 2; n < row; ++n)
        {
            for (int s = n; s < col; ++s)
            {
                // 注意 s 从 n 开始，因为 s 的最小值为 n
                // 比如掷 3 个骰子，s 最小为 3
                for (int k = 1; k <= 6; ++k)
                {
                    if (s - k > 0)
                    {
                        dp[n][s] += dp[n - 1][s - k];
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }

        double denominator = pow(6.0, n); // 分母

        for (int s = n; s <= 6 * n; ++s)
        {
            // s 的最小值为 n，在 res 里是第 s - n 位
            res[s - n] = dp[n][s] / denominator;
        }

        return res;
    }
};


int main()
{
    /*  To be done. */
}