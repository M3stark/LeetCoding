/*
    127. 单词接龙
    字典 wordList 中从单词 beginWord 和 endWord 的 转换序列 是一个按下述规格形成的序列：
        - 序列中第一个单词是 beginWord 。
        - 序列中最后一个单词是 endWord 。
        - 每次转换只能改变一个字母。
        - 转换过程中的中间单词必须是字典 wordList 中的单词。
        
    给你两个单词 beginWord 和 endWord 和一个字典 wordList ，
    找到从 beginWord 到 endWord 的 最短转换序列 中的 单词数目 。如果不存在这样的转换序列，返回 0。
    难度：困难
    链接：https://leetcode-cn.com/problems/word-ladder
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;


class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        // 将vector转成unordered_set，提高查询速度
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        // 如果endWord没有在wordSet出现，直接返回0
        if (wordSet.find(endWord) == wordSet.end())
            return 0;

        // 记录word是否访问过, int -> 查询到这个word路径长度path
        unordered_map<string, int> visitMap;

        // 初始化队列
        queue<string> que;
        que.push(beginWord);

        // 初始化visitMap
        visitMap.insert(pair<string, int>(beginWord, 1));

        while (!que.empty())
        {
            string word = que.front();
            que.pop();
            int path = visitMap[word]; // 这个word路径长度
            for (int i = 0; i < word.size(); ++i)
            {
                string newWord = word; // 用一个新单词替换word，因为每次置换一个字母
                for (int j = 0; j < 26; ++j)
                {
                    newWord[i] = j + 'a';
                    // 找到了end，返回path+1
                    if (newWord == endWord)
                        return path + 1;
                    if (wordSet.find(newWord) != wordSet.end() && visitMap.find(newWord) == visitMap.end())
                    {
                        // wordSet出现了newWord，并且newWord没有被访问过
                        // 添加访问信息
                        visitMap.insert(pair<string, int>(newWord, path + 1));
                        que.push(newWord);
                    }
                }
            }
        }
        return 0;
    }
};