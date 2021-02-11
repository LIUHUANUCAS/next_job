#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>
#include "../data_type.h"

using namespace std;
class Solution {
   public:
    int sumOfLeftLeaves(TreeNode* root) { return dfs(root); }
    int dfs(TreeNode* root) {
        if (root == nullptr)
            return 0;
        if (leaf(root->left)) {
            return root->left->val + dfs(root->right);
        }
        return dfs(root->left) + dfs(root->right);
    }

    int leaf(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return root->left == nullptr && root->right == nullptr;
    }
};
int main() {
    Solution so;
    return 0;
}