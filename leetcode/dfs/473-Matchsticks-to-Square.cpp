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
    int r = 0;
    bool makesquare(vector<int>& A) {
        int k = 4, s = 0, v = 0;
        r = 0;
        for (auto e : A) {
            s += e;
            v = max(v, e);
        }
        sort(A.begin(), A.end());
        if (s % k != 0 || v > s / k)
            return 0;
        return dfs(A, 0, 0, s / k, k, 0);
        // dfs(A, 0, 0, s / k, k);
        // return r;
    }
    int dfs(vector<int>& m, int i, int cur, int target, int k, int z) {
        int n = m.size();
        if (i > n || cur > target)
            return 0;
        if (k == 0)
            return 1;
        if (cur == target) {
            return dfs(m, 0, 0, target, k - 1, z);
        }
        for (int j = i; j < n; j++) {
            if (m[j] < 0)
                continue;
            int y = m[j];
            m[j] = -y;
            if (dfs(m, j + 1, cur + y, target, k, z)) {
                return 1;
            }
            m[j] = y;
        }
        return 0;
    }
    void dfs(vector<int>& m, int i, int cur, int target, int k) {
        int n = m.size();
        if (i > n || cur > target || r)
            return;
        // printf("%d %d %d \n", i, cur, k);
        // if (i == n && target == cur && k == 1) {
        if (k == 0) {
            r = 1;
            return;
        }

        if (cur == target) {
            dfs(m, 0, 0, target, k - 1);
            return;
        }
        for (int j = i; j < n; j++) {
            if (m[j] < 0)
                continue;
            int y = m[j];
            m[j] = -y;
            dfs(m, j + 1, cur + y, target, k);
            m[j] = y;
        }
    }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {1, 1, 2, 2, 2};
        auto r = so.makesquare(A);
        cout << r << endl;
    }
    {
        A = {3, 3, 3, 3, 4};
        auto r = so.makesquare(A);
        cout << r << endl;
    }
    {
        A = {5, 5, 5, 5, 4, 4, 4, 4, 3, 3, 3, 3};
        auto r = so.makesquare(A);
        cout << r << endl;
    }

    {
        A = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 8};
        auto r = so.makesquare(A);
        cout << r << endl;
    }
    return 0;
}