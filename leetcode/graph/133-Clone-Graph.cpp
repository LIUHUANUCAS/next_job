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
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
   public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> visit;
        return dfs(node, visit);
    }
    Node* dfs(Node* n, unordered_map<Node*, Node*>& visit) {
        if (n == nullptr)
            return n;
        int size = n->neighbors.size();
        auto node = new Node(n->val, vector<Node*>(size, nullptr));
        visit[n] = node;
        for (int i = 0; i < size; i++) {
            auto e = n->neighbors[i];
            if (!visit[e]) {  // dfs clone graph
                auto r = dfs(e, visit);
                node->neighbors[i] = r;
            } else {  // just link node with edge
                node->neighbors[i] = visit[e];
            }
        }
        return node;
    }
};
int main() {
    Solution so;

    return 0;
}