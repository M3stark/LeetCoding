/*
    剑指 Offer 61. 扑克牌中的顺子
    从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
    2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。
    难度：简单
    链接：https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    bool isStraight(vector<int> &nums)
    {
        set<int> mySet;
        int maxVal = 0; // INT_MIN
        int minVal = 14; // INT_MAX;

        for (int num : nums)
        {
            if (num == 0)   // 小王可以看成任意数字
                continue;
            maxVal = max(maxVal, num);
            minVal = min(minVal, num);
            if (mySet.count(num) != 0)  // num出现过
                return false;
            mySet.insert(num);
        }

        return maxVal - minVal < 5;
    }
};

template<typename T>
void fcin(vector<T>& v) {
    for(int i = 0; i < v.size(); ++i) {
        cin >> v[i];
    }
}

/*
    g++ 61.\ 扑克牌中的顺子.cpp -o 61.o -std=c++11
*/

int main()
{
    cout << "***********************************************" << endl;
    cout << "剑指 Offer 61. 扑克牌中的顺子" << endl;
    cout << "从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。" << endl;
    cout << "***********************************************" << endl;
    cout << "从扑克牌中随机抽5张牌: ";
    vector<int> vec(5);
    fcin(vec);
    bool res = Solution().isStraight(vec);
    if(res == true) {
        cout << "这5张牌是顺子！" << endl;
    }
    else {
        cout << "这5张牌不是顺子！" << endl;
    }

    return 0;
}