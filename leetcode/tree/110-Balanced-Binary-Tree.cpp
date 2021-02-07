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
    int result;
    bool isBalanced(TreeNode* root) {
        result = 1;
        maxDepth(root);
        return result;
    }
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        auto l = maxDepth(root->left);
        auto r = maxDepth(root->right);
        if (abs(l - r) > 1) {
            result = 0;
        }
        return 1 + max(l, r);
    }
};

int main() {
    Solution so;

    return 0;
}