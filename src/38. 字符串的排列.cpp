#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std; 


class Solution
{
public:
    vector<string> res;
    vector<string> permutation(string s)
    {
        res.clear();
        sort(s.begin(), s.end());
        string path; 
        vector<bool> used(s.size(), false);
        dfs(s, path, used);
        return res;
    }

    void dfs(string &s, string &path, vector<bool> &used)
    {
        if (path.size() == s.size())
        {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < s.size(); ++i)
        {
            if (used[i] == true)
                continue;
            if (i > 0 && s[i] == s[i - 1] && used[i - 1])
                continue;

            used[i] = true;
            path += s[i];

            dfs(s, path, used);
            used[i] = false;
            path.pop_back();
        }
    }
};

int main() {
    cout << "***********************************************" << endl;
    cout << "剑指 Offer 38. 字符串的排列" << endl;
    cout << "***********************************************" << endl;
    string word;
    cout << "输入一个字符串: ";
    cin >> word;
    cout << "***********************************************" << endl;
    Solution a;
    vector<string> res;
    res = a.permutation(word);
    cout << "字符串的排列为：[";
    

    for (int i = 0; i < res.size() - 1; ++i)
    {
        cout << "'" << res[i] <<  "',";
    }
    cout << "'" << res[res.size() - 1] << "']" << endl;
    cout << "***********************************************" << endl;

    return 0;

}