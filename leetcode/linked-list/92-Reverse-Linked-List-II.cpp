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
    ListNode* s;
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // return reverseB(head, m, n);
        return dfs(head, m, n);
    }
    ListNode* dfs(ListNode* head, int m, int n) {
        ListNode d(0);
        d.next = head;
        auto p = &d;
        for (int i = 1; i < m; i++) {
            p = p->next;
        }
        p->next = reverseN(p->next, n - m + 1);
        return d.next;
    }
    ListNode* reverseB(ListNode* cur, int m, int n) {
        if (m == 1) {
            return reverseN(cur, n);
        }
        cur->next = reverseBetween(cur->next, m - 1, n - 1);
        return cur;
    }
    ListNode* reverseN(ListNode* head, int n) {
        if (n == 1) {
            s = head->next;
            return head;
        }
        auto last = reverseN(head->next, n - 1);
        head->next->next = head;
        head->next = s;
        return last;
    }
};
int main() {
    Solution so;
    vector<int> A;
    int m, n;
    {
        m = 2;
        n = 4;
        A = {1, 2, 3, 4, 5, 6};
        auto l = ListNode::create_list(A);
        print_list(l);
        print_list(so.reverseBetween(l, m, n));
    }
    {
        m = 2;
        n = 2;
        A = {1, 2};
        auto l = ListNode::create_list(A);
        print_list(l);
        print_list(so.reverseBetween(l, m, n));
    }
    return 0;
}
