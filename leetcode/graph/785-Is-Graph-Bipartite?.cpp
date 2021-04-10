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
    int bit;
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        bit = 0;
        auto color = vector<int>(n, 0);  // 0:color0,1:visited
        auto visit = vector<int>(n, 0);  // 0:unvisitd,1:visited
        // 染色数组和标记数组可以合二为一
        for (int i = 0; i < n; i++) {
            if (visit[i] == 0) {
                visit[i] = 1;
                color[i] = 1;
                dfs(graph, i, color, visit);
            }
            if (bit)
                return 0;
        }
        return bit == 0;
    }
    void dfs(vector<vector<int>>& graph,
             int s,
             vector<int>& color,
             vector<int>& visit) {
        if (bit) {
            return;
        }

        for (auto adj : graph[s]) {
            if (visit[adj] == 0) {
                visit[adj] = 1;
                // 染色，和s不一样 color[adj] = - color[s];
                color[adj] = 1 - color[s];
                dfs(graph, adj, color, visit);
            } else if (color[adj] == color[s]) {
                bit = 1;
                break;
            }
        }
    }
};
int main() {
    Solution so;

    return 0;
}