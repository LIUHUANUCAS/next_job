#include <cstdio>
#include <iostream>
#include <queue>
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
        // bfs(root,res);
        return res;
    }
    void bfs(Node* root, vector<vector<int>>& r) {
        if (root == nullptr)
            return;
        queue<Node*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            r.push_back({});
            for (int i = 0; i < size; i++) {
                auto x = que.front();
                que.pop();
                r.back().push_back(x->val);
                for (auto e : x->children) {
                    if (e != nullptr) {
                        que.push(e);
                    }
                }
            }
        }
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