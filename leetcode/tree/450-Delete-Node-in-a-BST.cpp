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
    TreeNode* deleteNode(TreeNode* root, int key) { return dfs(root, key); }
    TreeNode* dfs(TreeNode* root, int key) {
        if (root == nullptr)
            return root;
        if (root->val < key) {
            root->right = dfs(root->right, key);
            return root;
        } else if (root->val > key) {
            root->left = dfs(root->left, key);
            return root;
        }
        if (isleaf(root)) {
            return nullptr;
        }
        if (root->left == nullptr)
            return root->right;
        if (root->right == nullptr)
            return root->left;
        // not null for left & right
        auto m = findMin(root->right);
        root->val = m->val;
        root->right = dfs(root->right, m->val);
        return root;
    }

    TreeNode* findMin(TreeNode* root) {
        while (root->left) {
            root = root->left;
        }
        return root;
    }
    int isleaf(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return root->left == nullptr && root->right == nullptr;
    }
};
int main() {
    Solution so;

    return 0;
}