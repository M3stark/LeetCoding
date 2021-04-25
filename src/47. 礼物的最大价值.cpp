/*
    剑指 Offer 47. 礼物的最大价值
    在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。
    你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。
    给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？
    难度：中等
    https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxValue(vector<vector<int> > &grid)
    {
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (i == 0 && j == 0)
                    continue;
                else if (i == 0)
                    grid[i][j] += grid[i][j - 1];
                else if (j == 0)
                    grid[i][j] += grid[i - 1][j];
                else
                    grid[i][j] += max(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[grid.size() - 1][grid[0].size() - 1];
    }
};

// ACM模式 数组输入
template<typename T>
void fcin(vector<T> &v) {
    for(int i = 0; i < v.size(); ++i) {
        cin >> v[i];
    }
}

// ACM模式 二维数组输入
template<typename T>
void fcin2(vector<vector<T> > &v2) {
    for(int i = 0; i < v2.size(); ++i) {
        fcin(v2[i]);
    }
}

int main()
{
    cout << "***********************************************" << endl;
    cout << "剑指 Offer 47. 礼物的最大价值" << endl;
    cout << "***********************************************" << endl;
    cout << "请输入一个二维数组(以回行结束)：";
    vector < vector<int> > tmp;
    fcin2(tmp);
    cout << "***********************************************" << endl;

    Solution a;
    int res = a.maxValue(tmp);
    cout << "礼物的最大价值: " << res << endl;
    return 0;
}
