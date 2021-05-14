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
    int len = 0;
    int longestUnivaluePath(TreeNode* root) {
        if (root == nullptr)
            return 0;
        len = 0;
        dfs(root);
        return len - 1;
    }
    int dfs(TreeNode* root) {
        if (root == nullptr)
            return 0;
        auto L = dfs(root->left);
        auto R = dfs(root->right);
        int r = 1;
        if (root->left && root->val == root->left->val) {
            r = max(r, L + 1);
        }
        if (root->right && root->val == root->right->val) {
            r = max(r, R + 1);
        }
        if (root->left && root->right && root->val == root->left->val &&
            root->right->val == root->val) {
            // r = max(L + R + 1, r);
            len = max(L + R + 1, len);
        }
        len = max(len, r);
        return r;
    }
};
int main() {
    Solution so;

    return 0;
}