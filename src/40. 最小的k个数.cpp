/*
    剑指 Offer 40. 最小的k个数
    输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。
    https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/

*/

/*
    补充：最大堆/最小堆
    头文件：#include <queue>
    声明形式为：priority_queue< type, container, function>;
    构建大顶堆：
        priority_queue<int> max_heap;
        或者 priority_queue<int,vector<int>,less<int> > max_heap;
    构建小顶堆：
        priority_queue<int,vector<int>,greater<int> > min_heap;
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    // priority
    vector<int> getLeastNumbers(vector<int> &arr, int k) {
        vector<int> res(k);
        priority_queue<int> max_heap;
        
        for(int i = 0; i < k; ++i) {
            max_heap.push(arr[i]);
        }

        for(int i = k; i < arr.size(); ++i) {
            if(arr[i] < max_heap.top()) {
                max_heap.pop();
                max_heap.push(arr[i]);
            }
        }

        for(int i = 0; i < k; ++i) {
            res[i] = max_heap.top();
            max_heap.pop();
        }
        return res;
    }
};

// ACM 模式 输入一个一维vector
template <typename T>
void fcin(vector<T> &v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        cin >> v[i];
    }
}

// ACM 模式 输出一个一维vector
template <typename T>
void fcout(vector<T> &v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

int main() {
    cout << "***********************************************" << endl;
    cout << "剑指 Offer 40. 最小的k个数" << endl;
    cout << "***********************************************" << endl;
    int n = 5;
    vector<int> tmp(n);     // 输入 n 个
    cout << "请输入一个数组(大小为" << n << "): ";
    fcin(tmp);
    int k;
    cout << "请输入k: ";
    cin >> k;
    Solution b;
    vector<int> res(k);
    res = b.getLeastNumbers(tmp, k);
    cout << "最小的k个数为: ";
    fcout(res);
    cout << "***********************************************" << endl;

    return 0;
}
