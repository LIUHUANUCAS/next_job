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
    vector<vector<int>> res;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visit(n, 0);
        vector<int> path = {0};

        dfs(graph, 0, visit, path);
        return res;
    }
    void dfs(vector<vector<int>>& g,
             int s,
             vector<int>& visit,
             vector<int>& path) {
        if (s + 1 == visit.size()) {
            res.push_back(path);
            return;
        }
        for (auto e : g[s]) {
            if (visit[e] == 0) {
                visit[e] = 1;
                path.push_back(e);
                dfs(g, e, visit, path);
                path.pop_back();
                visit[e] = 0;
            }
        }
    }
};
int main() {
    Solution so;
    vector<vector<int>> g;
    {
        g = {{1, 2}, {3}, {3}, {}};
        auto r = so.allPathsSourceTarget(g);
        printvector(r);
    }
    return 0;
}