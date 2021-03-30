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
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        dfs(n, 0, k, path);
        return res;
    }
    void dfs(int n, int i, int k, vector<int>& path) {
        if (k == 0) {
            res.push_back(path);
            return;
        }
        for (int j = i + 1; j <= n; j++) {
            path.push_back(j);
            dfs(n, j, k - 1, path);
            path.pop_back();
        }
    }
};
int main() {
    Solution so;
    int n, k;
    {
        n = 4;
        k = 2;
        auto r = so.combine(n, k);
        printvector(r);
    }
    {
        n = 5;
        k = 3;
        auto r = so.combine(n, k);
        printvector(r);
    }
    return 0;
}