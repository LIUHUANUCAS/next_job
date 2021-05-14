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
class Solution {
   public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int len = getlen(root);
        int n = len / k;
        int topk = len % k;
        vector<ListNode*> res(k, nullptr);
        if (len <= k) {
            n = 1;
        }
        // printf("%d %d %d\n", len, n, topk);
        for (int i = 0; i < k && root; i++) {
            res[i] = root;
            int s = n;
            if (i < topk && k < len) {
                s += 1;
            }
            root = advance(root, s);
        }
        return res;
    }

    ListNode* advance(ListNode* root, int s) {
        if (root == nullptr)
            return root;
        for (int i = 1; i < s && root; i++) {
            root = root->next;
        }
        auto next = root;
        if (root) {
            next = root->next;
            root->next = nullptr;
        }
        return next;
    }
    int getlen(ListNode* root) {
        int c = 0;
        while (root) {
            root = root->next;
            c++;
        }
        return c;
    }
};
int main() {
    Solution so;
    vector<int> A;
    ListNode* head;
    vector<ListNode*> r;
    int k;
    {
        A = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        k = 7;
        head = ListNode::create_list(A);
        r = so.splitListToParts(head, k);
        for (auto e : r) {
            print_list(e);
        }
    }
    {
        A = {1, 2, 3};
        k = 5;
        head = ListNode::create_list(A);
        r = so.splitListToParts(head, k);
        for (auto e : r) {
            print_list(e);
        }
    }
    return 0;
}