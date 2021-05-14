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
    int maxv;
    int maxPathSum(TreeNode* root) {
        if (root == nullptr)
            return 0;
        maxv = INT_MIN;
        dfs(root);
        return maxv;
    }
    // return from root to one child maxsum,root->left or root->right
    int dfs(TreeNode* root) {
        if (root == nullptr)
            return 0;
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        l = max(0, l);
        r = max(0, r);
        maxv = max(l + r + root->val, maxv);
        return max(l, r) + root->val;
    }
};
int main() {
    Solution so;

    return 0;
}