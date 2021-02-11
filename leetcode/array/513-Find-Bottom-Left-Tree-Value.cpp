#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>
#include "../data_type.h"

using namespace std;
class Solution {
   public:
    int findBottomLeftValue(TreeNode* root) { return bfs(root); }
    int bfs(TreeNode* root) {
        if (root == nullptr)
            return 0;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            root = que.front();
            que.pop();
            if (root->right)
                que.push(root->right);
            if (root->left)
                que.push(root->left);
        }
        return root->val;
    }
};
int main() {
    Solution so;
    return 0;
}