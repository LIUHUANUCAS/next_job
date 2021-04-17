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
    int cycle;
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n, vector<int>());
        vector<int> visit(n, 0);
        vector<int> stack(n, 0);  // vertex is on stack
        cycle = 0;
        for (auto e : edges) {
            int u = e[0], v = e[1];
            g[v].push_back(u);
        }
        for (int i = 0; i < n; i++) {
            if (!visit[i] && !cycle)  // not visit && no-cycle
                dfs(g, i, visit, stack);
        }
        return !cycle;
    }
    void dfs(vector<vector<int>>& g,
             int s,
             vector<int>& visit,
             vector<int>& stack) {
        if (cycle)  // has cycle
            return;
        stack[s] = 1;
        visit[s] = 1;
        for (auto e : g[s]) {
            if (cycle) {  // has cycle
                return;
            } else if (!visit[e]) {
                dfs(g, e, visit, stack);
            } else if (stack[e]) {  // e is pre-dfs order
                cycle = 1;
            }
        }
        stack[s] = 0;
    }
};
int main() {
    Solution so;
    vector<vector<int>> edge;
    int n;
    {
        n = 2;
        edge = {{1, 0}};
        auto r = so.canFinish(n, edge);
        cout << r << endl;
    }
    {
        n = 2;
        edge = {{1, 0}, {0, 1}};
        auto r = so.canFinish(n, edge);
        cout << r << endl;
    }
    return 0;
}