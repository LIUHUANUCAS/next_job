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
    int res;
    int maxSumBST(TreeNode* root) {
        res = 0;
        dfs(root);
        return res;
    }

    //(isbst,max,min,sum)
    vector<int> dfs(TreeNode* root) {
        if (root == nullptr) {
            return {1, INT_MIN, INT_MAX, 0};
        }
        auto L = dfs(root->left);
        auto R = dfs(root->right);
        int isbst_l = L[0], isbst_r = R[0];
        int left_max = L[1], left_min = L[2];
        int right_min = R[2], right_max = R[1];
        vector<int> cur(4);
        if (isbst_l && isbst_r && left_max < root->val &&
            root->val < right_min) {
            cur[0] = 1;
            cur[1] = max(root->val, right_max);
            cur[2] = min(root->val, left_min);
            cur[3] = L[3] + R[3] + root->val;
            res = max(res, cur[3]);
            return cur;
        }
        return {0, 0, 0, 0};
    }
};
int main() {
    Solution so;

    return 0;
}