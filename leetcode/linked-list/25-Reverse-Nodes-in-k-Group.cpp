#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "../data_type.h"

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
    ListNode* reverseKGroup(ListNode* head, int k) { return dfs(head, k); }
    ListNode* dfs(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr)
            return head;
        auto p = head;
        int i = 0;
        // cout << p->val << endl;
        for (i = 0; i < k && p; i++) {
            p = p->next;
        }
        if (i < k)  // 不够k个
            return head;
        // cout << "i:" << i << " k:" << k << endl;
        auto r = reverse_end(head, p);  //翻转[head,p)区间内
        auto end = dfs(p, k);
        // head->next = nullptr;
        head->next = end;
        return r;
    }

    ListNode* reverse_end(ListNode* head, ListNode* end) {
        if (head == end || head->next == end)
            return head;
        auto n = head->next;
        auto r = reverse_end(n, end);
        head->next = nullptr;
        n->next = head;
        return r;
    }
};
int main() {
    Solution so;
    vector<int> A;
    int k;
    k = 2;
    A = {1, 2, 3, 4, 5, 6};
    auto l = ListNode::create_list(A);
    print_list(l);
    print_list(so.reverseKGroup(l, k));
    return 0;
}
