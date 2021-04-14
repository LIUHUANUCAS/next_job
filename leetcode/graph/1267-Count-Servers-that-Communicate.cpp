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
    int countServers(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        int total = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] > 0) {
                    int node = dfs(g, i, j);
                    if (node > 1) {
                        total += node;
                    }
                }
            }
        }
        return total;
    }
    int dfs(vector<vector<int>>& g, int i, int j) {
        int m = g.size();
        int n = g[0].size();
        if (i >= m || i < 0 || j < 0 || j >= n)
            return 0;
        g[i][j] = -1;
        int c = 1;
        for (int r = 0; r < m; r++) {
            if (g[r][j] > 0) {
                c += dfs(g, r, j);
            }
        }
        for (int col = 0; col < n; col++) {
            if (g[i][col] > 0) {
                c += dfs(g, i, col);
            }
        }
        return c;
    }
};
int main() {
    Solution so;

    return 0;
}