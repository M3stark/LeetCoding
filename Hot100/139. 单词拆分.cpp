//
// Created by Mike on 2021/8/18.
//

/*
 * 139. 单词拆分
 * 给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，
 * 判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
 * 说明：
 * - 拆分时可以重复使用字典中的单词。
 * - 你可以假设字典中没有重复的单词。
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
 * Notes:
 * 题目中说是拆分为一个或多个在字典中出现的单词，所以这是完全背包。
 */

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // 去重
        unordered_set<string> strSet(wordDict.begin(), wordDict.end());

        // dp[i] : 字符串长度为i的话，dp[i]为true，
        // 表示可以拆分为一个或多个在字典中出现的单词。
        vector<int>dp(s.length() + 1, false);

        // 如果dp[0] = false，后面所有结果都是flase
        dp[0] = true;

        for(int i = 0; i <= s.length(); ++i) {      // 遍历背包
            for(int j = 0; j < i; ++j) {            // 遍历物品
                string str = s.substr(j, i - j);
                if(strSet.find(str) != strSet.end() && dp[j]) {
                    dp[i] = true;
                }
            }
        }

        return dp[s.length()];
    }
};