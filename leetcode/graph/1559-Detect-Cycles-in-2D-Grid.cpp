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
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int cycle;
    bool containsCycle(vector<vector<char>>& grid) {
        cycle = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visit(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visit[i][j] && !cycle) {
                    dfs(grid, i, j, i, j, visit);
                }
            }
        }
        return cycle;
    }

    void dfs(vector<vector<char>>& g,
             int i,
             int j,
             int prex,
             int prey,
             vector<vector<int>>& visit) {
        if (cycle) {
            return;
        }
        int m = g.size(), n = g[0].size();
        // printf("%d %d\n", i, j);
        visit[i][j] = 1;
        // for (auto e : dir) {
        //     int x = i + e[0], y = j + e[1];
        //     if (valid_location(m, n, x, y) && same_color(g[i][j], g[x][y])) {
        //         if (!visit[x][y]) {
        //             dfs(g, x, y, i, j, visit);
        //         } else if (x != prex || y != prey) {
        //             cycle = 1;
        //             return;
        //         }
        //     }
        // }
        auto adj = getAdjList(g, i, j);
        for (auto e : adj) {
            int x = e[0], y = e[1];
            if (!visit[x][y]) {
                dfs(g, x, y, i, j, visit);
            } else if (x != prex || y != prey) {
                cycle = 1;
                return;
            }
        }
    }
    vector<vector<int>> getAdjList(vector<vector<char>>& g, int i, int j) {
        int m = g.size(), n = g[0].size();
        vector<vector<int>> adj;
        for (auto e : dir) {
            int x = i + e[0], y = j + e[1];
            if (valid_location(m, n, x, y) && same_color(g[i][j], g[x][y])) {
                adj.push_back({x, y});
            }
        }
        return adj;
    }
    int same_color(char x, char y) { return x == y; }
    int valid_location(int m, int n, int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
};
int main() {
    Solution so;
    vector<vector<char>> g;
    {
        g = {{'a', 'a', 'a', 'a'},
             {'a', 'b', 'b', 'a'},
             {'a', 'b', 'b', 'a'},
             {'a', 'a', 'a', 'a'}};
        auto r = so.containsCycle(g);
        cout << r << endl;
    }

    {
        g = {{'a', 'a', 'b'}};
        auto r = so.containsCycle(g);
        cout << r << endl;
    }

    {
        g = {{'a', 'b', 'b'}, {'b', 'z', 'b'}, {'b', 'b', 'a'}};
        auto r = so.containsCycle(g);
        cout << r << endl;
    }
    return 0;
}