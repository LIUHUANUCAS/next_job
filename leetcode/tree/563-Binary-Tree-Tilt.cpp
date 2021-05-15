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
    int res;
    int findTilt(TreeNode* root) {
        res = 0;
        dfs(root);
        return res;
    }
    int dfs(TreeNode* root) {
        if (root == nullptr)
            return 0;
        auto L = dfs(root->left);
        auto R = dfs(root->right);
        res += abs(L - R);
        return L + R + root->val;
    }
};
int main() {
    Solution so;

    return 0;
}