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
    //    f[m,n] = f[m-1,n] + f[m,n-1]
    int uniquePathsWithObstacles(vector<vector<int>>& g) { return dyp(g); }
    int dyp(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m && !g[i][0]; i++) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n && !g[0][j]; j++) {
            dp[0][j] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = (1 - g[i][j]) * (dp[i - 1][j] + dp[i][j - 1]);
            }
        }
        return dp[m - 1][n - 1];
    }
};
int main() {
    Solution so;
    vector<vector<int>> g;
    int r;
    {
        g = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
        r = so.uniquePathsWithObstacles(g);
        cout << r << endl;
    }
    {
        g = {{0, 1}, {0, 0}};
        r = so.uniquePathsWithObstacles(g);
        cout << r << endl;
    }

    {
        g = {{0, 0, 0, 0},
             {0, 1, 0, 0},
             {0, 0, 0, 0},
             {0, 0, 1, 0},
             {0, 0, 0, 0}};
        r = so.uniquePathsWithObstacles(g);
        cout << r << endl;
    }
    return 0;
}