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
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> count(n, 0);
        vector<int> res;
        for (auto e : edges) {
            int u = e[0];
            int v = e[1];
            count[v]++;
        }
        for (int i = 0; i < n; i++) {
            if (count[i] == 0) {
                res.push_back(i);
            }
        }
        return res;
    }
};
int main() {
    Solution so;
    int n;
    vector<vector<int>> edges;
    {
        n = 6;
        edges = {{0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}};
        auto r = so.findSmallestSetOfVertices(n, edges);
        printvector(r);
    }
    return 0;
}