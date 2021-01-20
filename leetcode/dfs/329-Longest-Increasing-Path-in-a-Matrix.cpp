#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
   public:
    vector<vector<int>> cache;
    int m, n;
    int len;
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int longestIncreasingPath(vector<vector<int>>& M) {
        m = M.size();
        n = M[0].size();
        len = 1;
        cache = vector<vector<int>>(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                auto mlen = dfs(M, i, j);
                len = max(len, mlen);
            }
        }
        return len;
    }
    int dfs(vector<vector<int>>& M, int i, int j) {
        if (cache[i][j] != 0)
            return cache[i][j];
        int mlen = 1;
        for (auto e : dir) {
            auto x = i + e[0];
            auto y = j + e[1];
            if (x < 0 || x >= m || y < 0 || y >= n ||
                M[i][j] >= M[x][y])  // M[i][j] > M[x][y] is error,[[2,2]] cause
                                     // stack overflow
                continue;
            auto l = 1 + dfs(M, x, y);
            mlen = max(l, mlen);
        }
        cache[i][j] = mlen;
        return mlen;
    }
};
int main() {
    Solution so;
    vector<vector<int>> m = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
    auto r = so.longestIncreasingPath(m);
    cout << r << endl;
    return 0;
}