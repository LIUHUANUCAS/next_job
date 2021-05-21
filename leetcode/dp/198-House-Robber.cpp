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
    int rob(vector<int>& A) {
        return dyp(A);
        // int n = A.size();
        // vector<int> cache(n, -1);
        // return dfs(A, n - 1, cache);
    }
    int dyp(vector<int>& A) {
        int n = A.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 0, dp[1] = A[0];
        for (int i = 2; i <= n; i++) {
            dp[i] = max(dp[i - 2] + A[i - 1], dp[i - 1]);
        }
        return dp[n];
    }
    // dfs(n) = dfs(n-2) + A[n] || dfs(n-1)
    int dfs(vector<int>& A, int n, vector<int>& cache) {
        if (n < 0)
            return 0;
        if (n == 0) {
            return A[0];
        }
        if (cache[n] >= 0)
            return cache[n];
        return cache[n] =
                   max(dfs(A, n - 2, cache) + A[n], dfs(A, n - 1, cache));
    }
};
int main() {
    Solution so;
    vector<int> A;
    int r;
    {
        A = {1, 2, 3, 1};
        r = so.rob(A);
        cout << r << endl;
    }
    {
        A = {2, 7, 9, 3, 1};
        r = so.rob(A);
        cout << r << endl;
    }
    return 0;
}