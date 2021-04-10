
/**
二叉树：距离最远的节点
*/
#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
};

int calc(TreeNode* root) {}
int max_dis = 0;
// 以经过root的最远距离[root,root->left] || [root,root->right]
/// left,dis ,right dis

//     1
//    /  \
//   2    3
//  / \ 
//  4  6
//  /
//  5
TreeNode *max_node, *max_left, *max_right;
struct Dist {
    int dis;
    TreeNode* node;
    Dist(int x, TreeNode* y) : dis(x), node(y) {}
};

Dist dfs2(TreeNode* root) {
    if (root == nullptr)
        return Dist(-1, root);

    Dist L = dfs2(root->left);
    Dist R = dfs2(root->right);
    TreeNode* leaf = root;
    Dist res = Dist(L.dis + 1, L.node);
    // int d = max(L, R) + 1;
    if (L.dis < R.dis) {
        res = Dist(R.dis + 1, R.node);
    }
    if (res.dis == 0) {
        res.node = leaf;
    }

    // {L + 1, R + 1, L + R + 1};
    if (max_dis < L.dis + R.dis + 2) {
        max_node = root;
        max_left = L.node;
        max_right = R.node;
    }
    max_dis = max(max_dis, L.dis + R.dis + 2);

    return res;
}

int dfs(TreeNode* root) {
    if (root == nullptr)
        return -1;

    int L = dfs(root->left);
    int R = dfs(root->right);
    int d = max(L, R) + 1;

    // {L + 1, R + 1, L + R + 1};
    if (max_dis < L + R + 2) {
        max_node = root;
    }
    max_dis = max(max_dis, L + R + 2);

    return d;
}
int main() {
    vector<int> A;
    int c;
}
