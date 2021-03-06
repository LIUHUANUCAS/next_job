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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode d(0);
        auto p = head;
        auto cur = &d;
        while (p) {
            auto q = p->next;
            while (q && q->val == p->val) {  // equal
                q = q->next;
            }
            if (q == p->next) {
                cur->next = p;
                cur = cur->next;
                cur->next = nullptr;
            }
            p = q;
        }
        return d.next;
    }
};
int main() {
    Solution so;
    vector<int> A;

    A = {1, 2, 2, 3, 3, 4, 5, 6, 7};
    auto l = ListNode::create_list(A);
    print_list(l);
    print_list(so.deleteDuplicates(l));
    return 0;
}
