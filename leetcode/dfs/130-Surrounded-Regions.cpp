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
    int m, n;
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void solve(vector<vector<char>>& b) {
        m = b.size(), n = b[0].size();
        vector<vector<int>> visit(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            if (b[i][0] == 'O')
                dfs(b, i, 0, 1, visit);
            if (b[i][n - 1] == 'O') {
                dfs(b, i, n - 1, 1, visit);
            }
        }
        for (int j = 0; j < n; j++) {
            if (b[0][j] == 'O')
                dfs(b, 0, j, 1, visit);
            if (b[m - 1][j] == 'O')
                dfs(b, m - 1, j, 1, visit);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (b[i][j] == 'O') {
                    b[i][j] = 'X';
                }
                if (b[i][j] == 'Y')
                    b[i][j] = 'O';
            }
        }
    }
    vector<vector<int>> getadj(vector<vector<char>>& b, int i, int j) {
        vector<vector<int>> res;
        for (auto e : dir) {
            int x = i + e[0], y = j + e[1];
            if (x >= 0 && x < m && y >= 0 && y < n) {
                res.push_back({x, y});
            }
        }
        return res;
    }
    int dfs(vector<vector<char>>& b,
            int i,
            int j,
            int on,
            vector<vector<int>>& visit) {
        visit[i][j] = 1;
        // printf("%d %d\n", i, j);
        char y = b[i][j];
        b[i][j] = 'Y';
        int r = on + onborder(i, j);
        auto adjlist = getadj(b, i, j);
        for (auto adj : adjlist) {
            int x = adj[0], y = adj[1];
            if (!visit[x][y] && b[x][y] == 'O') {
                dfs(b, x, y, r, visit);
            }
        }

        return r;
    }
    int onborder(int i, int j) {
        return i == 0 || j == 0 || i == m - 1 || j == n - 1;
    }
};
int main() {
    Solution so;
    vector<vector<char>> g;
    {
        g = {{'X', 'X', 'X', 'X'},
             {'X', '0', '0', '0'},
             {'X', 'X', 'X', 'X'},
             {'X', '0', '0', 'X'}};
        so.solve(g);
        // printvector(g);
    }
    {
        g = {{'X', 'X', 'X', 'X'},
             {'X', '0', '0', 'X'},
             {'X', 'X', '0', 'X'},
             {'X', 'O', '0', 'X'}};
        so.solve(g);
        // printvector(g);
    }
    {
        g = {{'X', 'X', 'X', 'X'},
             {'X', '0', 'X', '0'},
             {'X', 'X', '0', 'X'},
             {'X', '0', 'X', 'X'}};
        so.solve(g);
        // printvector(g);
    }
    {
        g = {{'O', 'O', 'O', 'O', 'X', 'X'}, {'O', 'O', 'O', 'O', 'O', 'O'},
             {'O', 'X', 'O', 'X', 'O', 'O'}, {'O', 'X', 'O', 'O', 'X', 'O'},
             {'O', 'X', 'O', 'X', 'O', 'O'}, {'O', 'X', 'O', 'O', 'O', 'O'}};
        printvector(g);
        so.solve(g);
        printvector(g);
    }
    {
        g = {{'X', 'X', 'X', 'X', 'O', 'O', 'X', 'X', 'O'},
             {'O', 'O', 'O', 'O', 'X', 'X', 'O', 'O', 'X'},
             {'X', 'O', 'X', 'O', 'O', 'X', 'X', 'O', 'X'},
             {'O', 'O', 'X', 'X', 'X', 'O', 'O', 'O', 'O'},
             {'X', 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'O'},
             {'O', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
             {'O', 'O', 'O', 'X', 'X', 'O', 'X', 'O', 'X'},
             {'O', 'O', 'O', 'X', 'O', 'O', 'O', 'X', 'O'},
             {'O', 'X', 'O', 'O', 'O', 'X', 'O', 'X', 'O'}};
        printvector(g);
        so.solve(g);
        printvector(g);
    }
    return 0;
}