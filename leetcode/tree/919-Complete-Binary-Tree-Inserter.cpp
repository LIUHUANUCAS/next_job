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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class CBTInserter {
    queue<TreeNode*> que;
    TreeNode **cur, *root;

   public:
    CBTInserter(TreeNode* root) : root(root) { move(root); }

    TreeNode* move(TreeNode* next) {
        TreeNode* p = nullptr;
        int c = 1;
        que.push(next);
        while (!que.empty() && c) {
            auto x = que.front();
            p = p == nullptr ? x : p;
            if (x->left && x->right) {
                que.pop();
                que.push(x->left);
                que.push(x->right);
            } else if (x->left) {
                cur = &x->right;
                que.push(x->left);
            } else {
                cur = &x->left;
            }
            c = x->left && x->right;
        }
        return p;
    }
    int insert(int v) {
        *cur = new TreeNode(v);
        auto p = move(*cur);
        return p->val;
    }

    TreeNode* get_root() { return root; }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
int main() {
    // Solution so;
    TreeNode *root = new TreeNode(1, new TreeNode(2), new TreeNode(3)), *res;
    int p;
    CBTInserter* obj = new CBTInserter(root);
    int n = 10;
    for (int i = 4; i < n; i++) {
        p = obj->insert(i);
        printf("insert:%d p:%d\n", i, p);
        res = obj->get_root();
        // print_tree_level(res);
    }
    return 0;
}