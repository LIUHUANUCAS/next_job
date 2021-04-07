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
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;
        int len = 1, idx = 0;
        for (int i = 0; i < n - 1; i++) {
            dp[i][i + 1] = s[i] == s[i + 1];
            if (dp[i][i + 1]) {
                idx = i;
                len = 2;
            }
        }
        for (int l = 2; l < n; l++) {
            for (int i = 0; i < n - l; i++) {
                int j = i + l;
                dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
                if (dp[i][j]) {
                    // printf(">>>%s %d %d %s\n", s.c_str(), i, j,
                    //    s.substr(i, l + 1).c_str());
                    idx = i, len = l + 1;
                }
                // printf("==== %d %d %d\n", i, j, dp[i][j]);
            }
        }
        return s.substr(idx, len);
    }
};
int main() {
    Solution so;
    string s;
    {
        s = "babad";
        auto r = so.longestPalindrome(s);
        cout << r << endl;
    }
    {
        s = "cbbd";
        auto r = so.longestPalindrome(s);
        cout << r << endl;
    }
    {
        s = "ac";
        auto r = so.longestPalindrome(s);
        cout << r << endl;
    }
    return 0;
}