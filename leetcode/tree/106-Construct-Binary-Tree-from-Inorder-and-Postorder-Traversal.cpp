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
    unordered_map<int, int> cache;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        reverse(postorder.begin(), postorder.end());
        reverse(inorder.begin(), inorder.end());
        vector<int>& preorder = postorder;
        int n = preorder.size();
        if (n != inorder.size())
            return nullptr;
        for (int i = 0; i < n; i++) {
            cache[inorder[i]] = i;
        }
        auto r = dfs(preorder, 0, n - 1, inorder, 0, n - 1);
        mirrorTree(r);
        return r;
    }
    void mirrorTree(TreeNode* root) {
        if (root == nullptr)
            return;
        swap(root->left, root->right);
        mirrorTree(root->left);
        mirrorTree(root->right);
        return;
    }
    TreeNode* dfs(vector<int>& pre,
                  int plo,
                  int phi,
                  vector<int>& in,
                  int ilo,
                  int ihi) {
        if (plo > phi || ilo > ihi)
            return nullptr;
        if (plo == phi || ilo == ihi) {
            return new TreeNode(pre[plo]);
        }
        auto root = new TreeNode(pre[plo]);
        auto idx = find_in(in, pre[plo]);
        auto size = idx - ilo;
        root->left = dfs(pre, plo + 1, plo + size, in, ilo, idx - 1);
        root->right = dfs(pre, plo + size + 1, phi, in, idx + 1, ihi);
        return root;
    }
    int find_in(vector<int>& in, int pre) {
        return cache[pre];
        int n = in.size();
        for (int i = 0; i < n; i++) {
            if (in[i] == pre) {
                return i;
            }
        }
        return -1;
    }
};
int main() {
    Solution so;

    return 0;
}