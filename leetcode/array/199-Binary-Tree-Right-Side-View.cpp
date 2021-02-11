#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>
#include "../data_type.h"

using namespace std;
class Solution {
   public:
    vector<int> rightSideView(TreeNode* root) { return bfs(root); }
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