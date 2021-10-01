/*
    剑指 Offer 62. 圆圈中最后剩下的数字
    0,1,···,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字（删除后从下一个数字开始计数）。求出这个圆圈里剩下的最后一个数字。
    例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。
    难度：简单
    https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int lastRemaining(int n, int m) {
        int res = 0;
        // 每多一人 胜利者下标相当于往右挪动了m位,再对当前人数取模求得新的胜利者下标
        for(int i = 1; i <= n; ++i) 
        {
            res = (res + m) % i;
        }
        return res;
    }
};