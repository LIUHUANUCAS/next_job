#include <cstdio>
#include <iostream>
#include <map>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

#include "../data_type.h"

using namespace std;
class Solution {
   public:
    int findCircleNum(vector<vector<int>>& A) {
        int n = A.size();
        vector<int> visit(n, 0);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                dfs(A, i, visit);
                count++;
            }
        }
        return count;
    }
    void dfs(vector<vector<int>>& g, int s, vector<int>& visit) {
        visit[s] = 1;
        for (int i = 0; i < g[s].size(); i++) {
            if (!visit[i] && g[s][i] > 0) {
                dfs(g, i, visit);
            }
        }
    }
};
int main() {
    Solution so;

    vector<vector<int>> A;
    int r;
    {
        A = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
        r = so.findCircleNum(A);
        cout << r << endl;
    }
    {
        A = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        r = so.findCircleNum(A);
        cout << r << endl;
    }
    return 0;
}