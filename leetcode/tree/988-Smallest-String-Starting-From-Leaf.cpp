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
    string res;
    string smallestFromLeaf(TreeNode* root) {
        string s;
        dfs(root, s);
        return res;
    }
    void dfs(TreeNode* root, string& s) {
        if (root == nullptr)
            return;
        s.push_back(root->val + 'a');
        if (root->left == nullptr && root->right == nullptr) {
            reverse(s.begin(), s.end());
            res = res.empty() ? s : min(res, s);
            reverse(s.begin(), s.end());
        }
        dfs(root->left, s);
        dfs(root->right, s);
        s.pop_back();
    }
};
int main() {
    Solution so;

    return 0;
}