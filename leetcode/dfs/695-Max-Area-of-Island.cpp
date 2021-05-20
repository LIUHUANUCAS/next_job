#include <cstdio>
#include <iostream>
#include <map>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

#include "../data_type.h"

using namespace std;
class Solution {
   public:
    const vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int maxAreaOfIsland(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        int r = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] == 1) {
                    r = max(dfs(g, i, j), r);
                }
            }
        }
        return r;
    }
    int dfs(vector<vector<int>>& g, int i, int j) {
        if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || g[i][j] != 1)
            return 0;
        int c = 1;
        g[i][j] = -1;
        for (auto d : dir) {
            int x = i + d[0], y = j + d[1];
            c += dfs(g, x, y);
        }
        return c;
    }
};
int main() {
    Solution so;
    vector<vector<int>> g;
    int r;
    {
        g = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
             {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
             {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
             {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
        r = so.maxAreaOfIsland(g);
        cout << r << endl;
    }
    {
        g = {{0, 0, 0, 0, 0, 0, 0, 0}};
        r = so.maxAreaOfIsland(g);
        cout << r << endl;
    }
    return 0;
}