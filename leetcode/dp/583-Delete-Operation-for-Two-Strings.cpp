#include <cstdio>
#include <iostream>
#include <map>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

#include "../data_type.h"

using namespace std;
class Solution {
   public:
    int minDistance(string w1, string w2) {
        int m = w1.size(), n = w2.size(), len;
        unordered_map<string, int> cache;
        len = dfs(w1, 0, w2, 0, cache);
        // len = longestCommonSubsequence(w1, w2);
        return m - len + n - len;
    }
    int dfs(string& s,
            int i,
            string& t,
            int j,
            unordered_map<string, int>& cache) {
        int m = s.size(), n = t.size();
        if (i == m || j == n) {
            return 0;
        }
        string key = to_string(i) + "_" + to_string(j);
        if (cache.find(key) != cache.end())
            return cache[key];
        if (s[i] == t[j]) {
            cache[key] = 1 + dfs(s, i + 1, t, j + 1, cache);
        } else {
            cache[key] =
                max(dfs(s, i, t, j + 1, cache), dfs(s, i + 1, t, j, cache));
        }
        return cache[key];
    }
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        if (m == 0 || n == 0)
            return 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};
int main() {
    Solution so;
    string word1, word2;
    int r;
    {
        word1 = "sea", word2 = "eat";
        r = so.minDistance(word1, word2);
        cout << r << endl;
    }
    {
        word1 = "leetcode", word2 = "etco";
        r = so.minDistance(word1, word2);
        cout << r << endl;
    }
    {
        word1 = "mart", word2 = "karma";
        r = so.minDistance(word1, word2);
        cout << r << endl;
    }
    return 0;
}