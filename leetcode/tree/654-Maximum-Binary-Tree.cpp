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
    TreeNode* constructMaximumBinaryTree(vector<int>& A) {
        int n = A.size();
        return dfs(A, 0, n - 1);
    }
    TreeNode* dfs(vector<int>& A, int i, int j) {
        if (i > j)
            return nullptr;
        if (i == j) {
            return new TreeNode(A[i]);
        }
        auto midx = find_max(A, i, j);
        auto r = new TreeNode(A[midx]);
        r->left = dfs(A, i, midx - 1);
        r->right = dfs(A, midx + 1, j);
        return r;
    }
    int find_max(vector<int>& A, int i, int j) {
        int midx = i;
        for (int k = i + 1; k <= j; ++k) {
            if (A[midx] < A[k]) {
                midx = k;
            }
        }
        return midx;
    }
};
int main() {
    Solution so;

    return 0;
}