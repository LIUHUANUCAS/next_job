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
        auto p = head;
        auto d = ListNode(head->val - 1);
        auto cur = &d;
        while (p) {
            auto next = p->next;
            if (p->val != cur->val) {
                cur->next = p;
                cur = p;
                cur->next = nullptr;
            }
            p = next;
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
