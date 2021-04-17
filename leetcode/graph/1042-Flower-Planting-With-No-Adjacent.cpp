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
    const int N = 4;
    vector<int> ans;
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> g(n + 1, vector<int>());
        for (auto p : paths) {
            int u = p[0], v = p[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        // printvector(g);
        vector<int> visit(n + 1, 0);
        ans = vector<int>(n, 0);
        for (int i = 1; i <= n; i++) {
            if (!visit[i])
                dfs(g, i, visit);
        }
        return ans;
    }
    void dfs(vector<vector<int>>& g, int s, vector<int>& visit) {
        // unordered_map<int, int> m;
        vector<int> m(N + 1);
        for (auto adj : g[s]) {
            if (visit[adj]) {
                // m[ans[adj - 1]] = 1;
                m[ans[adj - 1]] = 1;
            }
        }
        int color = find_uncolor(m);
        // printf("s,%d,c:%d\n", s, color);
        if (color == 0)
            return;
        visit[s] = 1;
        ans[s - 1] = color;
        for (auto adj : g[s]) {
            if (!visit[adj]) {
                dfs(g, adj, visit);
            }
        }
    }

    int find_uncolor(vector<int>& m) {
        for (int i = 1; i <= N; i++) {
            if (m[i] == 0)
                return i;
        }
        return 0;
    }
    int find_uncolor(unordered_map<int, int>& m) {
        for (int i = 1; i <= N; i++) {
            if (m.find(i) == m.end())
                return i;
        }
        return 0;
    }
};
int main() {
    Solution so;
    vector<vector<int>> paths;
    int n;
    {
        n = 3;
        paths = {{1, 2}, {2, 3}, {3, 1}};
        auto r = so.gardenNoAdj(n, paths);
        printvector(r);
    }
    {
        n = 4;
        paths = {{1, 2}, {3, 4}};
        auto r = so.gardenNoAdj(n, paths);
        printvector(r);
    }

    {
        n = 4;
        paths = {{1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 3}, {2, 4}};
        auto r = so.gardenNoAdj(n, paths);
        printvector(r);
    }
    return 0;
}