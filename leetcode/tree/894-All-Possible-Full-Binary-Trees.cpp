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
    vector<TreeNode*> allPossibleFBT(int n) { return dfs(n); }
    vector<TreeNode*> dfs(int n) {
        if (!(n & 0x01)) {
            return {};
        }
        if (n == 1) {
            return {new TreeNode(0)};
        }
        vector<TreeNode*> res;
        for (int i = 0, j = n - 1; i < n; ++i, --j) {
            auto L = dfs(i);
            auto R = dfs(j);
            for (auto r : R) {
                for (auto l : L) {
                    auto root = new TreeNode(0);
                    root->right = r;
                    root->left = l;
                    res.push_back(root);
                }
            }
        }

        return res;
    }
};
int main() {
    Solution so;

    return 0;
}