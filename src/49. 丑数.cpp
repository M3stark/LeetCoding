/*
    剑指 Offer 49. 丑数
    我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。
    求按从小到大的顺序的第 n 个丑数。
    难度：中等
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        // Dynamic Programming
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