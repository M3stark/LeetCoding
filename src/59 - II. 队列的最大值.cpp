/*
    剑指 Offer 59 - II. 队列的最大值
    请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
    若队列为空，pop_front 和 max_value 需要返回 -1
    难度：中等
    链接：https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof
*/
#include <iostream>
#include <deque>

using namespace std;

class MaxQueue
{
public:
    deque<int> q, max_q;
    MaxQueue() {}

    int max_value()
    {
        return max_q.empty() ? -1 : max_q.front();
    }

    void push_back(int value)
    {
        q.push_back(value);
        while (!max_q.empty() && value > max_q.back())
        {
            max_q.pop_back();
        }
        max_q.push_back(value);
    }

    int pop_front()
    {
        if (q.empty())
            return -1;
        int res = q.front();
        q.pop_front();

        if (!max_q.empty() && res == max_q.front())
        {
            max_q.pop_front();
        }
        return res;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

int main()
{
    /*  This part is to be done.    */
}