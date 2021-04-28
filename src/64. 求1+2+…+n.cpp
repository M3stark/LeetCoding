/*
    剑指 Offer 64. 求1+2+…+n
    求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
    难度：中等
    https://leetcode-cn.com/problems/qiu-12n-lcof/
*/

#include <iostream>
using namespace std;

class Solution
{
public:
    int sumNums(int n)
    {
        n && (n += sumNums(n - 1));
        return n;
    }
};

int main()
{
    cout << "***********************************************" << endl;
    cout << "剑指 Offer 64. 求1+2+…+n" << endl;
    cout << "***********************************************" << endl;
    int n;
    cout << "请输入n: ";
    cin >> n;
    int res = Solution().sumNums(n);
    cout << "1+2+…+n = " << res << endl;
    cout << "***********************************************" << endl;
    return 0;
}