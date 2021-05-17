/*
    剑指 Offer 56 - I. 数组中数字出现的次数
    一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。
    要求时间复杂度是O(n)，空间复杂度是O(1)。
    难度：中等
    https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/
*/

/*
    任何数 x 与 0 异或，结果为 x 
    任何数与自身异或，结果为 0 
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> singleNumbers(vector<int> &nums)
    {
        int exor = 0;
        /*  求出两个独立数字的异或值    */
        for (int n : nums)
            exor ^= n;

        int idx = 1;
        /*  找到该异或值从右往左第一个 1 出现的位置 */
        while (!(idx & exor))
            idx <<= 1;

        int a = 0, b = 0;
        for (int i : nums)
        {
            if (idx & i)
            {
                /*  如果 i 从右往左第一个 1 出现的位置与异或值一样  */
                a ^= i;
            }
            else
                /*  如果 i 从右往左第一个 1 出现的位置与异或值不一样    */
                b ^= i;
        }
        return {a, b};  // c++11
    }
};

template<typename T>
void fcin(vector<T>& v) {
    for(int i = 0; i < v.size(); ++i) {
        cin >> v[i];
    }
}

template <typename T>
void fcout(vector<T> &v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << endl;
    }
}

/*
    g++ 56\ -\ I.\ 数组中数字出现的次数.cpp -o 56.o -std=c++11
*/

int main()
{
    cout << "***********************************************" << endl;
    cout << "剑指 Offer 42. 连续子数组的最大和" << endl;
    cout << "***********************************************" << endl;
    int n;
    cout << "请输入数组大小：";
    cin >> n;
    vector<int> vec(n);
    cout << "请输入一个数组: ";
    fcin(vec);
    vector<int> res = Solution().singleNumbers(vec);
    cout << "只出现一次的数字: " << endl;
    fcout(res);
    cout << "***********************************************" << endl;
    return 0;
}

