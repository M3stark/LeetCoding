/*
    692. 前K个高频单词
    给一非空的单词列表，返回前 k 个出现次数最多的单词。
    返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。
    难度：中等
    https://leetcode-cn.com/problems/top-k-frequent-words/
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    struct camp {
        // 自定义排序:使用 struct + 重载操作符()
        bool operator() (const pair<string, int>& a, const pair<string, int>& b) {
            if(a.second != b.second) return a.second < b.second;
            else return a.first > b.first;
        }
    };
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> myMap;
        
        auto newCamp = [] (const pair<string, int>& a, const pair<string, int>& b) {
            if(a.second != b.second) return a.second < b.second;
            else return a.first > b.first;
        };

        for (string word : words)
        {
            myMap[word]++;
        }
        // 自定义排序： struct + operator()
        //    priority_queue<pair<string, int>, vector<pair<string, int> >, camp> que;

        // 自定义排序：lambda + decltype
        priority_queue<pair<string, int>, vector<pair<string, int> >, decltype(newCamp)> que(newCamp);

       for (auto it : myMap)
       {
           que.push(it);
       }

       vector<string> res;

       while(!que.empty() && k--) {
           res.push_back(que.top().first);
           que.pop();
       }

       return res;
    }
};

int main()
{
    /* */
}