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
    int maxAncestorDiff(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return dfs(root, root->val, root->val);
    }
    int dfs(TreeNode* root, int cur_min, int cur_max) {
        if (root == nullptr)
            return cur_max - cur_min;
        cur_min = min(root->val, cur_min);
        cur_max = max(root->val, cur_max);
        int L = dfs(root->left, cur_min, cur_max);
        int R = dfs(root->right, cur_min, cur_max);
        return max(L, R);
    }
};
int main() {
    Solution so;

    return 0;
}