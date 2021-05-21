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
    int minimumTotal(vector<vector<int>>& A) {
        int n = A.back().size(), m = A.size(), r = INT_MAX;
        vector<int> pre(n, 0);
        pre[0] = A[0][0];
        // cur[j] = pre[j] + A[i][j] || pre[j-1] + A[i][j]
        for (int i = 1; i < m; i++) {
            vector<int> cur(n, 0);
            for (int j = 0; j < A[i].size(); ++j) {
                int pre_v = 0;
                if (j == 0) {
                    pre_v = pre[j];
                } else if (j == A[i - 1].size()) {
                    pre_v = pre[j - 1];
                } else {
                    pre_v = min(pre[j], pre[j - 1]);
                }
                cur[j] = pre_v + A[i][j];
            }
            swap(cur, pre);
        }
        for (auto e : pre) {
            r = min(r, e);
        }
        return r;
    }

    int dpy(vector<vector<int>>& A) {
        int n = A.size();
        // dp[k][i] = min(dp[k + 1][i], dp[k + 1][i + 1]) + A[k][i];

        vector<int> dp(A.back());
        for (int layer = n - 2; layer >= 0; layer--) {
            for (int j = 0; j < layer; ++j) {
                dp[j] = min(dp[j], dp[j + 1]) + A[layer][j];
                // dp[j] is layer+1 sum for j not current layer sum for j
            }
        }
        return dp[0];

        // vector<int> minlen(triangle.back());
        // for (int layer = n - 2; layer >= 0; layer--)  // For each layer
        // {
        //     for (int i = 0; i <= layer; i++)  // Check its every 'node'
        //     {
        //         // Find the lesser of its two children, and sum the current
        //         // value in the triangle with it.
        //         minlen[i] = min(minlen[i], minlen[i + 1]) +
        //         triangle[layer][i];
        //     }
        // }
        // return minlen[0];
    }
};
int main() {
    Solution so;
    vector<vector<int>> A;
    int r;
    {
        A = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
        r = so.minimumTotal(A);
        cout << r << endl;
    }
    {
        A = {{-10}};
        r = so.minimumTotal(A);
        cout << r << endl;
    }
    return 0;
}