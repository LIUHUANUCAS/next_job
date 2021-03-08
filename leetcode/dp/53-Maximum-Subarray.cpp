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
    int maxSubArray(vector<int>& A) {
        int n = A.size();
        vector<int> dp(n, 0);
        dp[0] = A[0];
        int m = dp[0];
        for (int i = 1; i < n; ++i) {
            if (A[i] + dp[i - 1] > A[i]) {
                dp[i] = dp[i - 1] + A[i];
            } else {
                dp[i] = A[i];
            }
            m = max(m, dp[i]);
        }
        return m;
    }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        auto r = so.maxSubArray(A);
        cout << r << endl;
    }
    {
        A = {1};
        auto r = so.maxSubArray(A);
        cout << r << endl;
    }
    return 0;
}