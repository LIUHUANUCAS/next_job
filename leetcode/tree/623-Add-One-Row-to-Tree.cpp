#include <cstdio>
#include <iostream>
#include <map>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

#include "../data_type.h"

using namespace std;

class Solution {
   public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            return new TreeNode(val, root, nullptr);
        }
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty() && depth > 0) {
            auto n = que.size();
            depth--;
            for (int i = 0; i < n; i++) {
                auto x = que.front();
                que.pop();
                if (depth == 1) {
                    x->left = new TreeNode(val, x->left, nullptr);
                    x->right = new TreeNode(val, nullptr, x->right);
                    // return root;
                } else {
                    if (x->left)
                        que.push(x->left);
                    if (x->right)
                        que.push(x->right);
                }
            }
            if (depth == 1)
                return root;
        }
        return root;
    }
};
int main() {
    Solution so;

    return 0;
}