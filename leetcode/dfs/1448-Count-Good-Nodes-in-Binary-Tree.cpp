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
    int c = 0;
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return c;
    }
    void dfs(TreeNode* root, int pre_max) {
        if (root == nullptr) {
            return;
        }
        int m = max(root->val, pre_max);
        if (root->val >= pre_max) {
            c++;
        }
        dfs(root->left, m);
        dfs(root->right, m);
    }
};
int main() {
    Solution so;

    return 0;
}