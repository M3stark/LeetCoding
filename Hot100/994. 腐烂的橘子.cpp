/*
    994. 腐烂的橘子
    在给定的网格中，每个单元格可以有以下三个值之一：
        值 0 代表空单元格；
        值 1 代表新鲜橘子；
        值 2 代表腐烂的橘子。
    每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂。
    返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1。
    难度：中等
    https://leetcode-cn.com/problems/rotting-oranges/
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int> > &grid)
    {
        queue<pair<int, int> > que;
        vector<vector<int> > dic{ {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        int m = grid.size();
        int n = grid[0].size();
        int res = 0, fresh = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    fresh++;
                }
                else if (grid[i][j] == 2)
                {
                    que.push(make_pair(i, j));
                }
            }
        }
        while (!que.empty() && fresh)
        {
            int size = que.size();
            for (int i = 0; i < size; ++i)
            {
                std::pair<int, int> p = que.front();
                que.pop();
                for (int k = 0; k < 4; ++k)
                {
                    int tx = p.first + dic[k][0];
                    int ty = p.second + dic[k][1];
                    if (tx >= 0 && tx < m && ty >= 0 && ty < n && grid[tx][ty] == 1)
                    {
                        --fresh;
                        grid[tx][ty] = 2;
                        que.push(make_pair(tx, ty));
                    }
                }
            }
            res++;
        }
        return fresh == 0 ? res : -1;
    }
};


int main()
{
    /*  */
}