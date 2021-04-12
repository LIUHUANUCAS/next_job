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
struct Depth {
    int depth;
    TreeNode* data;
    Depth(int d, TreeNode* da) : depth(d), data(da) {}
};
class Solution {
   public:
    TreeNode* recoverFromPreorder(string s) { return split(s); }
    TreeNode* split(string& s) {
        if (s.empty()) {
            return nullptr;
        }
        vector<string> res;
        stack<Depth> st;
        auto it = s.begin();
        int d = 0;
        while (it != s.end() && *it != '-') {
            it++;
        }
        // res.push_back(string(s.begin(),it));
        int v = atoi(string(s.begin(), it).c_str());
        auto root = new TreeNode(v);

        st.push(Depth(d, root));
        while (it != s.end()) {
            auto pre = it;
            while (it != s.end() && *it == '-') {
                it++;
            }
            int d = it - pre;
            int v = 0;
            while (it != s.end() && *it != '-') {
                v *= 10;
                v += *it - '0';
                it++;
            }
            // printf("-%d v:%d\n",d,v);
            // d =
            Depth de = Depth(d, new TreeNode(v));
            link(st, de);
        }
        linkstack(st);
        return root;
    }
    void linkstack(stack<Depth>& st) {
        while (st.size() > 1) {
            auto x = st.top();
            st.pop();
            auto y = st.top();

            if (x.depth == y.depth) {
                st.pop();
                auto z = st.top();
                linkTreeNode(&z, &y, 0);
                linkTreeNode(&z, &x, 1);
            } else {
                linkTreeNode(&y, &x, 0);
            }
        }
    }
    void link(stack<Depth>& st, Depth d) {
        int push = 0;
        while (!st.empty()) {
            auto x = st.top();
            if (x.depth <= d.depth) {
                st.push(d);
                push = 1;
                break;
            } else if (x.depth > d.depth) {
                st.pop();
                if (st.empty()) {
                } else {
                    auto y = st.top();
                    if (y.depth == x.depth) {
                        st.pop();
                        auto z = st.top();
                        linkTreeNode(&z, &y, 0);
                        linkTreeNode(&z, &x, 1);
                        // print_tree_level(z.data);
                        // printf(" data:%d\n",z.data->val);
                    } else {  // y < x
                        linkTreeNode(&y, &x, 0);
                    }
                }
            }
        }
        if (!push) {
            st.push(d);
        }
    }
    void linkTreeNode(Depth* root, Depth* chirld, int dir) {
        if (dir) {
            root->data->right = chirld->data;
        } else {
            root->data->left = chirld->data;
        }
    }
    string dfs(TreeNode* root, string path = "") {
        if (root == nullptr)
            return "";
        auto L = dfs(root->left, path + "-");
        auto R = dfs(root->right, path + "-");
        return path + to_string(root->val) + L + R;
    }
};
int main() {
    Solution so;
    string s, str;
    {
        s = "1-2--3--4-5--6--7";
        auto r = so.recoverFromPreorder(s);
        str = so.dfs(r);
        printf("%s\n%s\n", s.c_str(), str.c_str());
    }

    {
        s = "1-2--3---4-5--6---7";
        auto r = so.recoverFromPreorder(s);
        str = so.dfs(r);
        printf("%s\n%s\n", s.c_str(), str.c_str());
    }
    return 0;
}