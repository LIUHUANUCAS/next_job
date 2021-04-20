#include <cstdio>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_map>
#include <vector>
#include "../data_type.h"

using namespace std;
class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // return bfs(root);
        vector<vector<int>> res;
        dfs(root, 0, res);
        return res;
    }
    vector<vector<int>> bfs(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> r;
        if (root == nullptr)
            return r;
        que.push(root);
        while (!que.empty()) {
            auto size = que.size();
            vector<int> row;
            for (int i = 0; i < size; i++) {
                auto x = que.front();
                que.pop();
                row.push_back(x->val);
                if (x->left) {
                    que.push(x->left);
                }
                if (x->right) {
                    que.push(x->right);
                }
            }
            r.push_back(row);
        }
        return r;
    }

    void dfs(TreeNode* root, int level, vector<vector<int>>& res) {
        if (root == nullptr)
            return;
        if (level == res.size()) {
            res.push_back({});
        }
        int val = root->val;
        res[level].push_back(val);
        dfs(root->left, level + 1, res);
        dfs(root->right, level + 1, res);
    }
};
int main() {
    Solution so;

    return 0;
}