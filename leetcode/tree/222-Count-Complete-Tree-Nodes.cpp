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
    int countNodes(TreeNode* root) {
        return count_dfs(root);
        // return dfs(root);
    }
    int dfs(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return 1 + dfs(root->left) + dfs(root->right);
    }

    int count_dfs(TreeNode* root) {
        if (root == nullptr)
            return 0;
        auto L = count(root->left, 0);
        auto R = count(root->right, 1);
        if (L == R)
            return (1 << (L + 1)) - 1;
        return count_dfs(root->left) + count_dfs(root->right) + 1;
    }
    int count(TreeNode* root, int dir) {
        if (root == nullptr)
            return 0;
        int c = 0;
        while (root) {
            root = direction(root, dir);
            c++;
        }
        return c;
    }
    TreeNode* direction(TreeNode* root, int dir) {
        auto r = root->left;
        if (dir)
            r = root->right;
        return r;
    }
};
int main() {
    Solution so;

    return 0;
}