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
    int lengthOfLIS(vector<int>& A) {
        int n = A.size(), m = 1;
        vector<int> dp(n + 1, 1);
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (A[i] > A[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    m = max(m, dp[i]);
                }
            }
        }
        return m;
    }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {10, 9, 2, 5, 3, 7, 101, 18};
        auto r = so.lengthOfLIS(A);
        cout << r << endl;
    }
    {
        A = {0, 1, 0, 3, 2, 3};
        auto r = so.lengthOfLIS(A);
        cout << r << endl;
    }
    {
        A = {7, 7, 7, 7, 7, 7, 7};
        auto r = so.lengthOfLIS(A);
        cout << r << endl;
    }
    return 0;
}