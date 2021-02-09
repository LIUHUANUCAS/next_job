#include <cstdio>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_map>
#include <vector>
// #include "../data_type.h"

using namespace std;
// Definition for a Node.
struct Node {
   public:
    int val;
    Node* left;
    Node* right;
    Node() {}
    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }
    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
   public:
    Node* pre = nullptr;
    Node* head = nullptr;
    Node* treeToDoublyList(Node* root) {
        dfs(root);
        if (pre)
            pre->right = head;
        if (head)
            head->left = pre;
        return head;
    }
    void dfs(Node* root) {
        if (root == nullptr)
            return;
        dfs(root->left);
        if (head == nullptr)
            head = root;
        root->left = pre;
        if (pre)
            pre->right = root;
        pre = root;
        dfs(root->right);
    }
};
int main() {
    Solution so;

    return 0;
}