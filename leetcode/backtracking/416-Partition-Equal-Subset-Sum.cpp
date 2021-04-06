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
        return dfs(A, sum / 2);
    }
    int dfs(vector<int>& A, int sum) {
        if (sum == 0)
            return 1;
        int n = A.size();
        for (int i = 0; i < n; i++) {
            if (A[i] < 0)
                continue;
            int y = A[i];
            A[i] = -y;
            if (dfs(A, sum - y)) {
                return 1;
            }
            A[i] = y;
        }
        return 0;
    }
};
int main() {
    Solution so;

    return 0;
}