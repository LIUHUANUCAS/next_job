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
    bool canPartitionKSubsets(vector<int>& A, int k) {
        int s = 0, maxv = 0;
        for (auto e : A) {
            s += e;
            maxv = max(maxv, e);
        }
        if (s % k != 0 || maxv > s / k)
            return 0;
        return dfs(A, 0, s / k, k, 0);
    }
    int dfs(vector<int>& A, int s, int target, int k, int idx) {
        // printf("%d %d %d \n", s, target, k);
        if (k == 0)
            return 1;
        if (s > target)
            return 0;
        if (s == target) {
            return dfs(A, 0, target, k - 1, 0);
        }
        int n = A.size();
        for (int i = idx; i < n; i++) {
            if (A[i] < 0)
                continue;
            int y = A[i];
            A[i] = -y;
            if (dfs(A, s + y, target, k, i + 1)) {
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
    int k;
    {
        A = {4, 3, 2, 3, 5, 2, 1};
        k = 4;
        auto r = so.canPartitionKSubsets(A, k);
        cout << r << endl;
    }
    {
        A = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        k = 5;
        auto r = so.canPartitionKSubsets(A, k);
        cout << r << endl;
    }
    {
        A = {5, 2, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3};
        k = 15;
        auto r = so.canPartitionKSubsets(A, k);
        cout << r << endl;
    }

    {
        A = {18,  20,  39,  73,  96,  99,  101, 111,
             114, 190, 207, 295, 471, 649, 700, 1037};
        k = 4;
        auto r = so.canPartitionKSubsets(A, k);
        cout << r << endl;
    }
    return 0;
}