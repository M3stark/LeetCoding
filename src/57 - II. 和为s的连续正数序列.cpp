/*
    剑指 Offer 57 - II. 和为s的连续正数序列
    输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。
    序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。
    难度：简单
    https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int> > findContinuousSequence(int target)
    {
        int i = 1, j = 1, sum = 0;
        vector<vector<int> > res;
        while (i <= target / 2)
        {
            if (sum < target)
                sum += j++;
            else if (sum > target)
                sum -= i++;
            else
            {
                vector<int> vec;
                for (int k = i; k < j; ++k)
                    vec.push_back(k);
                res.push_back(vec);
                sum -= i++;
            }
        }
        return res;
    }
};

/*  cout  */

template <typename T>
void fcout(vector<T> &v)
{
    cout << "[";
    for (int i = 0; i < v.size() - 1; ++i)
    {
        cout << v[i] << ",";
    }
    cout <<  v[v.size() - 1] << ']';
}

template <typename T>
void fcout2(vector < vector<T> > & v2){
    for(int i = 0; i < v2.size(); ++i) {
        fcout(v2[i]);
    }
}

    int main()
    {
        cout << "***********************************************" << endl;
        cout << "剑指 Offer 57 - II. 和为s的连续正数序列" << endl;
        cout << "输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。" << endl;
        cout << "序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。" << endl;
        cout << "***********************************************" << endl;
        int target;
        cout << "请输入target：";
        cin >> target;
        vector<vector<int> > res = Solution().findContinuousSequence(target);
        cout << "和为s的连续正数序列: [";
        fcout2(res);
        cout << "]" << endl;
        cout << "***********************************************" << endl;
    }