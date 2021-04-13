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
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
   public:
    // level to last node map
    unordered_map<int, Node*> m;
    Node* connect(Node* root) {
        dfs(root, 0);
        return root;
    }
    void dfs(Node* root, int level) {
        if (root == nullptr)
            return;
        if (m.find(level) != m.end()) {
            m[level]->next = root;
            m[level] = root;
        } else {
            m[level] = root;
        }
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }
};
int main() {
    Solution so;

    return 0;
}