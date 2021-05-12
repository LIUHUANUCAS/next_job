#include <cstdio>
#include <iostream>
#include <map>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../data_type.h"

using namespace std;
class Solution {
   public:
    vector<vector<int>> res;

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        res.clear();
        dyp(s, wordDict);
        // for (auto& r : res) {
        //     printvector(r);
        // }
        return getresult(res, s);
    }
    vector<string> getresult(vector<vector<int>>& path, string& s) {
        vector<string> res;
        for (auto& p : path) {
            stringstream sst;
            int pre = 0;
            for (auto it = p.begin(); it != p.end(); it++) {
                string str(s.substr(pre, *it - pre + 1));
                if (!str.empty()) {
                    sst << str << (it + 1 != p.end() ? " " : "");
                }

                pre = *it + 1;
            }
            res.push_back(sst.str());
        }
        return res;
    }

    vector<int> dyp(string& s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        vector<vector<int>> dp(n + 1, vector<int>());
        dp[n].push_back(n + 1);
        // dp[i] = dp[j] && isword(s[j,n]);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n; j >= i; j--) {
                string str(s.substr(i, j - i));
                if (!dp[j].empty() && isword(str, set)) {
                    dp[i].push_back(j);
                }
            }
        }
        if (dp[0].empty())
            return {};
        vector<int> path;
        backtracking(dp, 0, s, path);
        return {};
    }
    void backtracking(vector<vector<int>>& g,
                      int idx,
                      string& s,
                      vector<int>& path) {
        // vector<string> res;
        // printf("idx:%d,%ld\n", idx, g.size());
        int n = g.size();
        if (idx + 1 == g.size()) {
            res.push_back(path);
            return;
        }

        for (auto e : g[idx]) {
            if (e > n) {
                continue;
            }
            path.push_back(e - 1);
            backtracking(g, e, s, path);
            path.pop_back();
        }
    }
    int isword(string& s, unordered_set<string>& set) {
        return set.find(s) != set.end();
    }
};
int main() {
    Solution so;
    string s;
    vector<string> wordDict;
    {
        s = "leetcode", wordDict = {"leet", "code"};
        auto r = so.wordBreak(s, wordDict);
        printvector(r);
    }
    {
        s = "applepenapple", wordDict = {"apple", "pen"};
        auto r = so.wordBreak(s, wordDict);
        printvector(r);
    }
    {
        s = "catsanddog", wordDict = {"cat", "cats", "and", "sand", "dog"};
        auto r = so.wordBreak(s, wordDict);
        printvector(r);
    }
    {
        s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaab";
        wordDict = {"a",      "aa",      "aaa",      "aaaa",      "aaaaa",
                    "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};
        auto r = so.wordBreak(s, wordDict);
        printvector(r);
    }
    {
        s = "pineapplepenapple";
        wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};
        auto r = so.wordBreak(s, wordDict);
        printvector(r);
    }

    return 0;
}