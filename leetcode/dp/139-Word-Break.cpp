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
    unordered_map<int, int> cache;
    bool wordBreak(string s, vector<string>& wordDict) {
        cache.clear();
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        return dfs(s, 0, set);
    }
    int dfs(string& s, int idx, unordered_set<string>& set) {
        int n = s.size();
        if (idx == n)
            return 1;
        if (cache.find(idx) != cache.end()) {
            return cache[idx];
        }
        for (int i = idx; i < n; i++) {
            string str(s.substr(idx, i - idx + 1));
            if (!str.empty() && set.find(str) != set.end() &&
                dfs(s, i + 1, set)) {
                cache[idx] = 1;
                return 1;
            }
        }
        cache[idx] = 0;
        return 0;
    }
};
int main() {
    Solution so;
    string s;
    vector<string> wordDict;
    {
        s = "leetcode", wordDict = {"leet", "code"};
        auto r = so.wordBreak(s, wordDict);
        cout << r << endl;
    }
    {
        s = "applepenapple", wordDict = {"apple", "pen"};
        auto r = so.wordBreak(s, wordDict);
        cout << r << endl;
    }
    {
        s = "catsandog", wordDict = {"cats", "dog", "sand", "and", "cat"};
        auto r = so.wordBreak(s, wordDict);
        cout << r << endl;
    }
    {
        s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaab";
        wordDict = {"a",      "aa",      "aaa",      "aaaa",      "aaaaa",
                    "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};
        auto r = so.wordBreak(s, wordDict);
        cout << r << endl;
    }
    return 0;
}