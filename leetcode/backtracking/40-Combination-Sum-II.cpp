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
    vector<vector<int>> combinationSum(vector<int>& A, int x) {
        sort(A.begin(), A.end());
        vector<int> path;
        vector<vector<int>> res;
        dfs(res, A, path, x, 0);
        return res;
    }
    void dfs(vector<vector<int>>& res,
             vector<int>& m,
             vector<int>& path,
             int x,
             int i) {
        if (x < 0) {
            return;
        }
        if (x == 0) {
            res.push_back(path);
            return;
        }
        int n = m.size();
        for (int j = i; j < n && x >= m[j]; j++) {
            if (j > i && m[j] == m[j - 1])
                continue;
            auto e = m[j];
            path.push_back(e);
            dfs(res, m, path, x - e, j + 1);
            path.pop_back();
        }
    }
};
int main() {
    Solution so;
    vector<int> A;
    int x;
    {
        A = {10, 1, 2, 7, 6, 1, 5};
        x = 8;
        auto r = so.combinationSum(A, x);
        printvector(r);
    }

    {
        A = {2, 5, 2, 1, 2};
        x = 5;
        auto r = so.combinationSum(A, x);
        printvector(r);
    }

    return 0;
}