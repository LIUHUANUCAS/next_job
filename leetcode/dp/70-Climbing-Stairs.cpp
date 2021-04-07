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
    int climbStairs(int n) {
        vector<int> dp(n + 3, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
int main() {
    Solution so;
    int n;
    {
        n = 10;
        auto r = so.climbStairs(n);
        cout << r << endl;
    }
    {
        n = 2;
        auto r = so.climbStairs(n);
        cout << r << endl;
    }
    return 0;
}