#include <cstdio>
#include <iostream>
#include <list>
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
class Codec {
   public:
    // stringstream sst;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        encode(root, out);
        return out.str();
    }

    void encode(TreeNode* root, ostringstream& out) {
        if (root == nullptr) {
            out << "# ";
            return;
        }
        out << root->val << " ";
        encode(root->left, out);
        encode(root->right, out);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return decode(in);
    }
    TreeNode* decode(istringstream& in) {
        string val;
        in >> val;
        if (val == "#")
            return nullptr;
        auto root = new TreeNode(stoi(val));
        root->left = decode(in);
        root->right = decode(in);
        return root;
    }

    string serializex(TreeNode* root) {
        if (root == nullptr)
            return "#";
        auto L = serialize(root->left);
        auto R = serialize(root->right);
        stringstream sst;
        sst << root->val << "," << L << "," << R;
        // cout << sst.str() << endl;
        return sst.str();
    }

    TreeNode* deserializex(string data) {
        // sst << data;
        auto b = data.begin();
        list<string> ls;
        for (auto it = data.begin(); it != data.end(); ++it) {
            if (*it == ',') {
                ls.push_back(string(b, it));
                b = it + 1;
            } else if (*it == '#') {
                ls.push_back("#");
                b = it + 1;
            }
        }
        return dfs(ls);
    }
    TreeNode* dfs(list<string> ls) {
        if (ls.empty())
            return nullptr;
        auto s = ls.front();
        ls.pop_front();
        if (s == "#") {
            return nullptr;
        }
        auto root = new TreeNode(atoi(s.c_str()));
        root->left = dfs(ls);
        root->right = dfs(ls);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
int main() {
    // TreeNode* ans = deser.deserialize(ser.serialize(root));
    Codec ser, deser;
    vector<int> A;
    int k;
    {
        A = {1, 2, 3, 4, 5, 6, 7, 8};
        k = 0;
        TreeNode* root = TreeNode::create_tree(A, k);
        auto str = ser.serialize(root);
        cout << str << endl;
    }
    return 0;
}