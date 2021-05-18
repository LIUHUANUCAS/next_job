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
    unordered_map<string, vector<TreeNode*>> cache;
    vector<TreeNode*> generateTrees(int n) {
        cache.clear();
        auto r = dfs(1, n);
        // cout << r.size() << endl;
        return r;
    }
    vector<TreeNode*> dfs(int start, int n) {
        if (start > n) {
            return {nullptr};
        }
        if (n == start) {
            return {new TreeNode(n)};
        }
        auto key = getkey(start, n);
        if (cache.find(key) != cache.end())
            return cache[key];
        vector<TreeNode*> res;
        for (int i = start; i <= n; ++i) {
            auto L = dfs(start, i - 1);
            auto R = dfs(i + 1, n);
            for (auto l : L) {
                for (auto rc : R) {
                    auto root = new TreeNode(i);
                    root->left = l;
                    root->right = rc;
                    res.push_back(root);
                }
            }
        }
        return cache[key] = res;
    }
    string getkey(int i, int j) { return to_string(i) + ":" + to_string(j); }
};
int main() {
    Solution so;
    int n;
    vector<TreeNode*> r;
    {
        n = 3;
        r = so.generateTrees(n);
    }
    return 0;
}