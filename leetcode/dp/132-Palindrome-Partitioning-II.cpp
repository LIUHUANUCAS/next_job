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
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (s[i] == s[j] && (i - j <= 2 || dp[j + 1][i - 1])) {
                    dp[j][i] = 1;
                }
            }
        }
        vector<vector<int>> mindp(n, vector<int>(n, 0));

        // return dp_dfs(dp, 0, n - 1);
    }

    int dp_dfs(vector<vector<int>>& dp, int start, int end) {
        if (dp[start][end]) {
            return 0;
        }
        int len = (end - start + 1);
        int y = len - 1;
        for (int k = start; k < end; k++) {
            int z = 1 + dp_dfs(dp, start, k) + dp_dfs(dp, k + 1, end);
            y = min(y, z);
        }
        return y;
    }

    int dfs(vector<vector<int>>& dp, int start) {
        int n = dp.size();
        if (start >= n) {
            return 0;
        }
        int cut = n - start - 1;
        for (int i = start; i < n; i++) {
            if (dp[start][i]) {
                cut = min(cut, dfs(dp, i + 1));
            }
        }
        return cut + 1;
    }
};
int main() {
    Solution so;
    string s;
    {
        s = "abc";
        auto r = so.minCut(s);
        cout << r << endl;
    }
    {
        s = "abb";
        auto r = so.minCut(s);
        cout << r << endl;
    }

    {
        s = "abba";
        auto r = so.minCut(s);
        cout << r << endl;
    }

    {
        s = "helloworldhellowo";
        auto r = so.minCut(s);
        cout << r << endl;
    }

    return 0;
}