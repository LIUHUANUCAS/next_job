#include <cstdio>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_map>
#include <vector>
#include "../data_type.h"

using namespace std;
class Solution {
   public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        dp_dfs(s);
        return res;
    }

    void dp_dfs_help(string& s,
                     int start,
                     vector<string>& onepath,
                     vector<vector<int>>& dp) {
        int n = s.size();
        if (start >= n) {
            res.push_back(onepath);
            return;
        }

        for (int i = start; i < n; i++) {
            if (dp[start][i]) {
                onepath.push_back(s.substr(start, i - start + 1));
                dp_dfs_help(s, i + 1, onepath, dp);
                onepath.pop_back();
            }
        }
    }
    void dp_dfs(string& s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (s[i] == s[j] && (i - j <= 2)) {
                    dp[j][i] = 1;
                } else if (s[i] == s[j] && dp[j + 1][i - 1]) {
                    dp[j][i] = 1;
                }
                // if (s[i] == s[j] && (i - j <= 2 || dp[j + 1][i - 1])) {
                //     dp[j][i] = 1;
                // }
            }
        }
        vector<string> onepath;
        dp_dfs_help(s, 0, onepath, dp);
    }
    int is_palindrome(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return 0;
            i++, j--;
        }
        return 1;
    }
    void dfs(string& s, int start, vector<string>& onepath) {
        int n = s.size();
        if (start >= n) {
            res.push_back(onepath);
            return;
        }

        for (int i = start; i < n; i++) {
            if (is_palindrome(s, start, i)) {
                onepath.push_back(s.substr(start, i - start + 1));
                dfs(s, i + 1, onepath);
                onepath.pop_back();
            }
        }
    }
};
int main() {
    Solution so;
    string s;
    {
        s = "abb";
        auto r = so.partition(s);
        printvector(r);
    }
    return 0;
}