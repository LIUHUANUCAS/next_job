#include <cstdio>
#include <iostream>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>
#include "../data_type.h"

using namespace std;
class Solution {
   public:
    int empty = 1;
    int sx, sy;
    int res = 0;
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    empty++;
                } else if (grid[i][j] == 1) {
                    sx = i;
                    sy = j;
                }
            }
        }
        dfs(grid, sx, sy);
        return res;
    }
    const int R = -2;
    void dfs(vector<vector<int>>& g, int sx, int sy) {
        if (sx < 0 || sx >= g.size() || sy < 0 || sy >= g[0].size() ||
            g[sx][sy] < 0) {
            return;
        }
        if (g[sx][sy] == 2) {
            if (empty == 0)
                res++;
            return;
        }
        g[sx][sy] = R;
        empty--;
        dfs(g, sx + 1, sy);
        dfs(g, sx - 1, sy);
        dfs(g, sx, 1 + sy);
        dfs(g, sx, sy - 1);
        g[sx][sy] = 0;
        empty++;
    }
};
int main() {
    Solution so;
    return 0;
}