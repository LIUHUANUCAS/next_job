#include <cstdio>
#include <iostream>
#include <random>
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    void push(TreeNode* root) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }

   public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) { push(root); }

    /** @return the next smallest number */
    int next() {
        auto x = st.top();
        st.pop();
        push(x->right);
        return x->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() { return !st.empty(); }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
int main() {
    // Solution so;
    return 0;
}