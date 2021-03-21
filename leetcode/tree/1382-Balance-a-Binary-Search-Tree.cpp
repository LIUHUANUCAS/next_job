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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   public:
    vector<int> r;
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        int n = r.size();
        return blance(0, n - 1);
    }
    TreeNode* blance(int i, int j) {
        int n = r.size();
        if (i < 0 || j >= n || i > j)
            return nullptr;
        int mid = (i + j) / 2;
        TreeNode* root = new TreeNode(r[mid]);
        root->left = blance(i, mid - 1);
        root->right = blance(mid + 1, j);
        return root;
    }
    void inorder(TreeNode* root) {
        if (root == nullptr)
            return;
        inorder(root->left);
        r.push_back(root->val);
        inorder(root->right);
    }
};
int main() {
    Solution so;

    return 0;
}