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
    vector<int> ans;
    const int N = 26;
    vector<int> countSubTrees(int n,
                              vector<vector<int>>& edges,
                              string labels) {
        ans = vector<int>(n, 0);
        vector<int> visit(n, 0);
        vector<vector<int>> g(n, vector<int>());
        for (auto e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(g, labels, 0, visit);
        return ans;
    }
    vector<int> dfs(vector<vector<int>>& g,
                    string& label,
                    int s,
                    vector<int>& visit) {
        visit[s] = 1;
        vector<int> count(N, 0);
        for (auto e : g[s]) {
            if (!visit[e]) {
                auto r = dfs(g, label, e, visit);
                for (int i = 0; i < N; i++) {
                    count[i] += r[i];
                }
            }
        }
        int ch = label[s];
        count[ch - 'a'] += 1;
        ans[s] += count[ch - 'a'];
        return count;
    }
};
int main() {
    Solution so;
    int n = 7;
    vector<vector<int>> edges;
    string labels;
    {
        labels = "abaedcd";
        n = labels.size();
        edges = {{0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6}};
        auto r = so.countSubTrees(n, edges, labels);
        printvector(r);
    }

    {
        labels = "bbbb";
        n = labels.size();
        edges = {{0, 1}, {1, 2}, {0, 3}};
        auto r = so.countSubTrees(n, edges, labels);
        printvector(r);
    }

    {
        labels = "aabab";
        n = labels.size();
        edges = {{0, 1}, {0, 2}, {1, 3}, {0, 4}};
        auto r = so.countSubTrees(n, edges, labels);
        printvector(r);
    }
    {
        labels = "cbabaa";
        n = labels.size();
        edges = {{0, 1}, {0, 2}, {1, 3}, {3, 4}, {4, 5}};
        auto r = so.countSubTrees(n, edges, labels);
        printvector(r);
    }

    {
        labels = "aaabaaa";
        n = labels.size();
        edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}};
        auto r = so.countSubTrees(n, edges, labels);
        printvector(r);
    }

    {
        labels = "aeed";
        n = labels.size();
        edges = {{0, 2}, {0, 3}, {1, 2}};
        auto r = so.countSubTrees(n, edges, labels);
        printvector(r);
    }

    return 0;
}