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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    TreeNode *pre, *first, *sec;
    vector<TreeNode*> vec;
    void recoverTree(TreeNode* root) {
        // pre = new TreeNode(INT_MIN);
        // dfs2(root);
        // swap(first->val,sec->val);
        // stack_dfs(root);
        stack_iter(root);
    }
    void stack_iter(TreeNode* root) {
        if (root == nullptr)
            return;
        auto first = find(root, 0);
        auto sec = find(root, 1);
        swap(first->val, sec->val);
    }
    TreeNode* get_child(TreeNode* root, int r) {
        if (r == 0)
            return root->left;
        return root->right;
    }

    int compare(TreeNode* pre, TreeNode* next, int r) {
        if (r == 0)
            return compareNode(pre, next);
        return compareNode(next, pre);
    }
    int compareNode(TreeNode* pre, TreeNode* next) {
        return pre != nullptr && next != nullptr && pre->val > next->val;
    }

    TreeNode* find(TreeNode* root, int r) {
        if (root == nullptr)
            return nullptr;
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* pre = nullptr;
        while (1) {
            while (root) {
                st.push(root);
                root = get_child(root, r);
            }
            if (st.empty())
                break;
            auto x = st.top();
            st.pop();
            if (compare(pre, x, r)) {
                break;
            }
            pre = x;
            root = get_child(x, 1 - r);
        }
        return pre;
    }
    void stack_dfs(TreeNode* root) {
        if (root == nullptr)
            return;
        stack<TreeNode*> st;
        st.push(root);
        auto y = root;
        TreeNode* pre = nullptr;
        while (1) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            if (st.empty())
                break;
            auto x = st.top();
            st.pop();
            if (pre != nullptr && pre->val > x->val) {
                break;
            }
            pre = x;
            root = x->right;
        }

        stack<TreeNode*> st2;
        st2.push(y);
        root = y;
        TreeNode* sec = nullptr;
        while (1) {
            while (root) {
                st2.push(root);
                root = root->right;
            }
            if (st2.empty()) {
                break;
            }
            auto x = st2.top();
            st2.pop();
            if (sec != nullptr && sec->val < x->val) {
                break;
            }
            sec = x;
            root = x->left;
        }

        swap(pre->val, sec->val);
    }

    void recoverTree2(TreeNode* root) {
        dfs(root);
        int n = vec.size();
        int j = 0, k = 0;
        for (int i = 1; i < n; i++) {
            if (vec[i - 1]->val > vec[i]->val) {
                j = i - 1;
                break;
            }
        }
        for (int i = n - 1; i > 0; --i) {
            if (vec[i]->val < vec[i - 1]->val) {
                k = i;
                break;
            }
        }
        swap(vec[j]->val, vec[k]->val);
    }
    void dfs2(TreeNode* root) {
        if (root == nullptr)
            return;
        dfs2(root->left);
        if (first == nullptr && pre->val > root->val) {
            first = pre;
        }

        if (first != nullptr && pre->val > root->val) {
            sec = root;
        }
        pre = root;
        dfs2(root->right);
    }
    void dfs(TreeNode* root) {
        if (root == nullptr)
            return;
        dfs(root->left);
        vec.push_back(root);
        dfs(root->right);
    }
};

int main() {
    Solution so;

    return 0;
}