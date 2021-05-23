/*
    剑指 Offer 41. 数据流中的中位数
    如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
    如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
    难度：困难
    https://leetcode-cn.com/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class MedianFinder
{
public:
    /** initialize your data structure here. */
    // 构造大顶堆，堆首为最大值
    priority_queue<int, vector<int>, less<int> > maxQue;
    // 构造小顶堆，堆首为最小值
    priority_queue<int, vector<int>, greater<int> > minQue;

    MedianFinder()
    {
    }
    /*
                ___________________
        小顶堆   |  6     5     4     top()
                ___________________

                ___________________
        top()       3     2     1  |    大顶堆
                ___________________
    */
    void addNum(int num)
    {
        if (maxQue.size() == minQue.size())
        {
            minQue.push(num);
            int top = minQue.top();
            minQue.pop();
            maxQue.push(top);
        }
        else
        {
            maxQue.push(num);
            int top = maxQue.top();
            maxQue.pop();
            minQue.push(top);
        }
    }

    double findMedian()
    {
        if (maxQue.size() == minQue.size())
        {
            return (maxQue.top() + minQue.top()) / 2.0;
        }
        else
        {
            return maxQue.top() * 1.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


int main()
{
    /*  This part is to be done.  */
}