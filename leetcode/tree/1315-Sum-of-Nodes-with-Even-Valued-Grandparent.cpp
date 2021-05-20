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
    int sumEvenGrandparent(TreeNode* root) {
        return dfs(root, nullptr, nullptr);
    }
    int dfs(TreeNode* cur, TreeNode* pre, TreeNode* grand) {
        if (cur == nullptr)
            return 0;
        int s = 0;
        if (grand != nullptr && grand->val % 2 == 0) {
            s += cur->val;
        }
        s += dfs(cur->left, cur, pre);
        s += dfs(cur->right, cur, pre);
        return s;
    }
};
int main() {
    Solution so;

    return 0;
}