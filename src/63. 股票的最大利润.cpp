/*
    剑指 Offer 63. 股票的最大利润
    假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？
    难度：中等
    https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h> // INT_MAX头文件

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int price = INT_MAX, profits = 0;
        for (int i = 0; i < prices.size(); ++i)
        {
            price = min(price, prices[i]);
            profits = max(profits, prices[i] - price);
        }
        return profits;
    }
};

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
    cout << "剑指 Offer 63. 股票的最大利润" << endl;
    cout << "假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？" << endl;
    cout << "***********************************************" << endl;
    int n;
    cout << "股票开盘天数: ";
    cin >> n;
    vector<int> vec(n);
    fcin(vec);
    int res = Solution().maxProfit(vec);
    cout << "股票的最大利润: " << res << endl;
    return 0;
}