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
    bool canPartition(vector<int>& A) {
        int sum = 0;
        for (auto e : A) {
            sum += e;
        }
        if (sum & 0x01)
            return 0;
        int n = A.size();
        sort(A.begin(), A.end());
        // return dfs(A, sum / 2, 0);
        return dfs2(A, n - 1, sum / 2);
    }

    int dfs2(vector<int>& A, int size, int sum) {
        if (sum == 0)
            return 1;
        if (sum < 0 || size <= 0)
            return 0;
        int with = dfs2(A, size - 1, sum - A[size]);
        int without = dfs2(A, size - 1, sum);
        return with + without;
    }
    int dfs(vector<int>& A, int sum, int idx) {
        // printf("%d\n", sum);
        int n = A.size();
        if (sum == 0)
            return 1;
        if (sum < 0 || idx >= n)
            return 0;
        for (int i = idx; i < n; i++) {
            if (A[i] < 0)
                continue;
            int y = A[i];
            A[i] = -y;
            if (dfs(A, sum - y, i + 1)) {
                return 1;
            }
            A[i] = y;
        }
        return 0;
    }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
             100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
             100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
             100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
             100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
             100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
             100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
             100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
             100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
             100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
             100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
             100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
             100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
             100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
             100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
             100, 100, 100, 99,  97};
        auto r = so.canPartition(A);
        cout << r << endl;
    }
    return 0;
}