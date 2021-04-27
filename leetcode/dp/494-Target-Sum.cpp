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
    int c;
    int findTargetSumWays(vector<int>& A, int S) {
        c = 0;
        dfs(A, 0, 0, S);
        return c;
    }
    void dfs(vector<int>& A, int start, int s, int S) {
        int n = A.size();
        if (start == n && s == S) {
            c++;
            return;
        }
        for (int i = start; i < n; i++) {
            dfs(A, i + 1, s + A[i], S);
            dfs(A, i + 1, s - A[i], S);
        }
    }
};
int main() {
    Solution so;
    vector<int> A;
    int S;
    {
        A = {1, 1, 1, 1, 1};
        S = 3;
        auto r = so.findTargetSumWays(A, S);
        cout << r << endl;
    }
    {
        A = {1};
        S = 1;
        auto r = so.findTargetSumWays(A, S);
        cout << r << endl;
    }
    return 0;
}