/*
    剑指 Offer 64. 求1+2+…+n
    求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
    难度：中等
    https://leetcode-cn.com/problems/qiu-12n-lcof/
*/

#include <iostream>
using namespace std;

/*
    Notes:
        a && b，计算机会先判断 a 是否为 true，假如 a 为 true，那么计算机会接着运行 b 语句;
        如果 b 为 true 那 a && b 为 true，否则为 false；
        如果 a 为 false，那计算机会直接返回 a && b = false，而不会再去运行 b 语句了。
*/

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