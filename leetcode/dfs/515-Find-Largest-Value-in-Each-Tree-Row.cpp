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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }
    void dfs(TreeNode* root, int d, vector<int>& res) {
        if (root == nullptr)
            return;
        if (d == res.size()) {
            res.push_back(root->val);
        } else {
            res[d] = max(res[d], root->val);
        }
        dfs(root->left, d + 1, res);
        dfs(root->right, d + 1, res);
    }
};
int main() {
    Solution so;

    return 0;
}