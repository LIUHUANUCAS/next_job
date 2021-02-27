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
    ListNode* partition(ListNode* head, int x) {
        ListNode d(1), d2(2);
        auto p = &d, q = &d2;
        ListNode** z;
        for (ListNode* y = head; y != nullptr; y = y->next) {
            z = y->val < x ? &p : &q;
            (*z)->next = y;
            *z = (*z)->next;
        }
        q->next = nullptr;
        p->next = d2.next;
        println("end1:%d", p->val);
        return d.next;
    }

    ListNode* partition_twopointer(ListNode* head, int x) {
        ListNode d(1), d2(2);
        auto p = &d, q = &d2;
        auto y = head;
        ListNode** z;
        while (y) {
            if (y->val < x) {
                p->next = y;
                p = p->next;
            } else {
                q->next = y;
                q = q->next;
            }
            y = y->next;
        }
        q->next = nullptr;
        p->next = d2.next;
        return d.next;
    }
};
int main() {
    Solution so;
    vector<int> A;
    int k;
    k = 5;
    // setDebug();
    A = {8, 10, 1, 2, 4, 5, 6};
    auto l = ListNode::create_list(A);
    print_list(l);
    print_list(so.partition(l, k));
    return 0;
}
