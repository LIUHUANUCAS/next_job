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
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n, vector<int>());
        vector<int> visit(n, 0);
        vector<int> stack(n, 0);  // vertex is on stack
        cycle = 0;
        vector<int> reversePost;
        for (auto e : edges) {
            int u = e[0], v = e[1];
            g[v].push_back(u);
        }
        for (int i = 0; i < n; i++) {
            if (!visit[i] && !cycle)  // not visit && no-cycle
                dfs(g, i, visit, stack, reversePost);
        }
        if (cycle)
            return {};
        reverse(reversePost.begin(), reversePost.end());
        return reversePost;
    }
    void dfs(vector<vector<int>>& g,
             int s,
             vector<int>& visit,
             vector<int>& stack,
             vector<int>& reversePost) {
        if (cycle)  // has cycle
            return;
        stack[s] = 1;
        visit[s] = 1;
        for (auto e : g[s]) {
            if (cycle) {  // has cycle
                return;
            } else if (!visit[e]) {
                dfs(g, e, visit, stack, reversePost);
            } else if (stack[e]) {  // e is pre-dfs order
                cycle = 1;
            }
        }
        stack[s] = 0;
        reversePost.push_back(s);
    }
};
int main() {
    Solution so;
    vector<vector<int>> edge;
    int n;
    {
        n = 2;
        edge = {{1, 0}};
        auto r = so.findOrder(n, edge);
        printvector(r);
    }
    {
        n = 4;
        edge = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
        auto r = so.findOrder(n, edge);
        printvector(r);
    }

    {
        n = 1;
        edge = {};
        auto r = so.findOrder(n, edge);
        printvector(r);
    }
    return 0;
}