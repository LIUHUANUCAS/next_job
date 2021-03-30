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
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& A, int x) {
        sort(A.begin(), A.end());
        vector<int> path;
        dfs(A, path, x, 0);
        return res;
    }
    void dfs(vector<int>& m, vector<int>& path, int x, int i) {
        if (x < 0) {
            return;
        }
        if (x == 0) {
            res.push_back(path);
            return;
        }
        int n = m.size();
        for (int j = i; j < n && x >= m[j]; j++) {
            auto e = m[j];
            path.push_back(e);
            dfs(m, path, x - e, j);
            path.pop_back();
        }
    }
};
int main() {
    Solution so;
    vector<int> A;
    int x;
    {
        A = {2, 3, 6, 7};
        x = 7;
        auto r = so.combinationSum(A, x);
        printvector(r);
    }

    {
        A = {2, 3, 6, 7};
        x = 499;
        auto r = so.combinationSum(A, x);
        // printvector(r);
    }

    return 0;
}