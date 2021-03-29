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
    int c = 0;
    int solveNQueens(int n) {
        vector<string> q(n, string(n, '.'));
        dfs(q, n, 0);
        return c;
    }
    void dfs(vector<string>& q, int n, int r) {
        if (r == n) {
            c++;
            return;
        }
        for (int j = 0; j < n; j++) {
            if (valid(q, r, j)) {
                q[r][j] = 'Q';
                dfs(q, n, r + 1);
                q[r][j] = '.';
            }
        }
    }
    int valid(vector<string>& q, int r, int j) {
        int n = q.size();
        for (int k = r - 1; k >= 0; k--) {
            for (int i = 0; i < n; i++) {
                if (q[k][j] == 'Q' ||
                    ((j - (r - k)) >= 0 && q[k][j - (r - k)] == 'Q') ||
                    ((j + r - k < n) && q[k][j + (r - k)] == 'Q'))
                    return 0;
            }
        }
        return 1;
    }
};
int main() {
    Solution so;
    int n;
    {
        n = 4;
        auto r = so.solveNQueens(n);
        cout << r << endl;
    }
    {
        n = 8;
        auto r = so.solveNQueens(n);
        cout << r << endl;
    }
    return 0;
}