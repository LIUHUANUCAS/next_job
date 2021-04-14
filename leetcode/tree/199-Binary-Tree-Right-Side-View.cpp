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
    vector<int> l;  // level right most record
    vector<int> rightSideView(TreeNode* root) {
        // return bfs(root);
        dfs(root, 0);
        return l;
    }
    void dfs(TreeNode* root, int level) {
        if (root == nullptr)
            return;
        if (level >= l.size()) {  // new level
            l.push_back(root->val);
        } else {
            l[level] = root->val;  // update level with right most value
        }
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }
    vector<int> bfs(TreeNode* root) {
        if (root == nullptr)
            return {};
        queue<TreeNode*> que;
        que.push(root);
        vector<int> vec;
        while (!que.empty()) {
            auto size = que.size();
            for (int i = 0; i < size; i++) {
                root = que.front();
                que.pop();
                if (i == 0) {
                    vec.push_back(root->val);
                }
                if (root->right)
                    que.push(root->right);
                if (root->left)
                    que.push(root->left);
            }
        }
        return vec;
    }
};
int main() {
    Solution so;

    return 0;
}