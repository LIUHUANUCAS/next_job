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
        // max(dp[1,n],dp[0,n-1])
        int n = A.size();
        if (n == 1) {
            return A[0];
        }
        return max(dyp(A, 1, n), dyp(A, 0, n - 1));
    }
    int dyp(vector<int>& A, int start, int end) {
        int n = A.size();
        vector<int> dp(n + 1, 0);
        dp[start] = 0, dp[start + 1] = A[start];
        for (int i = start + 2; i <= end; i++) {
            dp[i] = max(dp[i - 2] + A[i - 1], dp[i - 1]);
        }
        return dp[end];
    }
};
int main() {
    Solution so;
    vector<int> A;
    int r;
    {
        A = {2, 3, 2};
        r = so.rob(A);
        cout << r << endl;
    }
    {
        A = {1, 2, 3, 1};
        r = so.rob(A);
        cout << r << endl;
    }
    {
        A = {1};
        r = so.rob(A);
        cout << r << endl;
    }
    return 0;
}