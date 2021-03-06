#include <cstdio>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_map>
#include <vector>
#include "../data_type.h"

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return dfs(root, target);
    }
    TreeNode* dfs(TreeNode* root, int val) {
        if (root == nullptr)
            return root;
        root->left = dfs(root->left, val);
        root->right = dfs(root->right, val);
        if (root->val == val && root->left == nullptr && root->right == nullptr)
            return nullptr;
        return root;
    }
};
int main() {
    Solution so;

    return 0;
}