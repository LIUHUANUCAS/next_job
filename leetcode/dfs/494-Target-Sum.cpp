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
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<int> path;
        return dfs(nums, 0, 0, S, path);
    }
    int dfs(vector<int>& A, int idx, int cur, int s, vector<int>& path) {
        int n = A.size();
        if (idx == n) {
            return cur == s;
        }
        int c = 0;
        c += dfs(A, idx + 1, cur + A[idx], s, path);
        c += dfs(A, idx + 1, cur - A[idx], s, path);
        return c;
    }
};
int main() {
    Solution so;
    vector<int> A;
    int n;
    {
        A = {1, 1, 1, 1, 1};
        n = 3;
        auto r = so.findTargetSumWays(A, n);
        cout << r << endl;
    }
    {
        A = {1};
        n = 1;
        auto r = so.findTargetSumWays(A, n);
        cout << r << endl;
    }
    return 0;
}