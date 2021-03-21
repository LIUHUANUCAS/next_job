#include <cstdio>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_map>
#include <vector>
#include "../data_type.h"

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (head == nullptr)
            return 1;
        if (root == nullptr)
            return 0;
        return dfs(root, head) ||
               (isSubPath(head, root->left) || isSubPath(head, root->right));
    }
    bool dfs(TreeNode* root, ListNode* head) {
        if (head == nullptr)
            return 1;
        if (root == nullptr)
            return 0;
        return root->val == head->val &&
               (dfs(root->left, head->next) || dfs(root->right, head->next));
    }
};
int main() {
    Solution so;

    return 0;
}