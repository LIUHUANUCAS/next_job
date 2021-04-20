#include <cstdio>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_map>
#include <vector>
// #include "../data_type.h"

using namespace std;
// Definition for a Node.
class Node {
   public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) { val = _val; }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
   public:
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(Node* root) {
        dfs(root, 0);
        return res;
    }
    void dfs(Node* root, int level) {
        if (root == nullptr)
            return;
        if (level == res.size()) {
            res.push_back({});
        }
        int val = root->val;
        res[level].push_back(val);
        for (auto e : root->children) {
            dfs(e, level + 1);
        }
    }
};
int main() {
    Solution so;

    return 0;
}