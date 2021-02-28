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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0)
            return head;
        auto p = head;
        int n = 1;
        while (p->next) {
            p = p->next;
            n++;
        }
        k %= n;
        p->next = head;
        p = head;
        for (int i = 0; i < n - k - 1; i++) {
            p = p->next;
        }
        auto y = p->next;
        p->next = nullptr;
        return y;
    }
};
int main() {
    Solution so;
    vector<int> A;
    int k;
    k = 2;
    A = {8, 10, 1, 2, 4, 5, 6};
    auto l = ListNode::create_list(A);
    print_list(l);
    print_list(so.rotateRight(l, k));
    return 0;
}
