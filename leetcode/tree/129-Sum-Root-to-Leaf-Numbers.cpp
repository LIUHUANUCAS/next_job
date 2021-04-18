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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }
    void dfs(TreeNode* root, int s, int& sum) {
        if (root == nullptr) {
            return;
        }
        int v = s * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            sum += v;
            return;
        }
        dfs(root->left, v, sum);
        dfs(root->right, v, sum);
    }
};
int main() {
    Solution so;

    return 0;
}