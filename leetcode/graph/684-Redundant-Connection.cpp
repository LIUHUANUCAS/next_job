#include <cstdio>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_map>
#include <vector>
#include "../data_type.h"

using namespace std;
// cycle detection
class Solution {
   public:
    int cycle;
    int u, v;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        return connect_help(edges);
    }

    vector<int> connect_help(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> g(n + 1, vector<int>());
        vector<int> visit(n + 1, 0);
        for (auto e : edges) {
            int u = e[0], v = e[1];
            visit = vector<int>(n + 1, 0);
            if (connect(g, u, v, visit)) {
                return e;
            }
            g[u].push_back(v);
            g[v].push_back(u);
        }
        return {0, 0};
    }
    int connect(vector<vector<int>>& g, int u, int v, vector<int>& visit) {
        visit[u] = 1;
        for (auto e : g[u]) {
            if (e == v) {
                return 1;
            }
            if (!visit[e] && connect(g, e, v, visit)) {
                return 1;
            }
        }
        return 0;
    }

    vector<int> find_dfs(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> g(n + 1, vector<int>());
        vector<int> visit(n + 1, 0);
        int s = -1;
        for (auto e : edges) {
            int u = e[0], v = e[1];
            if (s == -1) {
                s = u;
            }
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(g, s, s, visit);
        return {u, v};
    }
    void dfs(vector<vector<int>>& g, int s, int pre, vector<int>& visit) {
        visit[s] = 1;
        for (auto e : g[s]) {
            if (!visit[e]) {
                dfs(g, e, s, visit);
            } else if (e != pre) {
                cycle = 1;
                u = s, v = e;
            }
        }
    }
};
int main() {
    Solution so;
    vector<vector<int>> edges;
    {
        edges = {{1, 2}, {1, 3}, {2, 3}};
        auto r = so.findRedundantConnection(edges);
        printvector(r);
    }
    {
        edges = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};
        auto r = so.findRedundantConnection(edges);
        printvector(r);
    }
    return 0;
}