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
    int minCostClimbingStairs(vector<int>& A) {
        int n = A.size();
        return dfs(A, n - 1);
    }
    int dfs(vector<int>& A, int i) {
        if (i < 0)
            return 0;
        if (i <= 1) {
            return 0;
        }
        int x = dfs(A, i - 1);
        int y = dfs(A, i - 2);
        int cost = min(x, y) + A[i];
        return cost;
    }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {10, 15, 20};
        auto r = so.minCostClimbingStairs(A);
        cout << r << endl;
    }
    {
        A = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
        auto r = so.minCostClimbingStairs(A);
        cout << r << endl;
    }
    return 0;
}