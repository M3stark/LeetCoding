/*
    剑指 Offer 66. 构建乘积数组
    给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B[i] 的值是数组 A 中除了下标 i 以外的元素的积, 
    即 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。
    难度：中等
    链接：https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof
*/

#include <iostream>
#include <vector>

using namespace std;

/*
    首先申请结果数组 res
    求出左侧三角从上到下的值，依次存入 res[i] 中
    求出右侧三角从下到上的值，并且和之前的 res[i] 做乘积存入，即可得到结果
    时间复杂度：O(n)
    空间复杂度：O(1)
    ----------------------------------------------------------------
         a[0]  |  a[1]  |  a[2]  |  a[3]  |  a[4]  
    b[0]  \    |   2    |   3    |   4    |   5    _   -> 120
    b[1]  1    |   \    |   3    |   4    |   5    1   -> 60
    b[2]  1    |   2    |   \    |   4    |   5    2   -> 40
    b[3]  1    |   2    |   3    |   \    |   5    6   -> 30
    b[4]  1    |   3    |   3    |   4    |   \    24  -> 24
    ----------------------------------------------------------------
*/

class Solution
{
public:
    vector<int> constructArr(vector<int> &a)
    {
        vector<int> res(a.size());

        int left = 1;
        for (int i = 0; i < a.size(); ++i)
        {
            res[i] = left;
            left *= a[i];
        }

        int right = 1;
        for (int j = a.size() - 1; j >= 0; --j)
        {
            res[j] *= right;
            right *= a[j];
        }

        return res;
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

template <typename T>
void fcout(vector<T> &v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << endl;
    }
}

int main()
{
    cout << "***********************************************" << endl;
    cout << "剑指 Offer 66. 构建乘积数组" << endl;
    cout << "***********************************************" << endl;
    int n;
    cout << "请输入数组大小: ";
    cin >> n;
    vector<int> vec(n);
    cout << "请输入数组: ";
    fcin(vec);
    vector<int> res = Solution().constructArr(vec);
    cout << "乘积数组: " << endl;
    fcout(res);
    return 0;
}