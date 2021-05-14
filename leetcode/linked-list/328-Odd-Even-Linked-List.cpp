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
    ListNode* oddEvenList(ListNode* head) {
        ListNode odd, even;
        ListNode *p = &odd, *q = &even, **x, *next;
        for (int i = 1; head != nullptr; head = next, i++) {
            next = head->next;
            head->next = nullptr;
            x = (i & 0x01) ? &p : &q;
            (*x)->next = head;
            *x = head;
        }
        p->next = even.next;
        return odd.next;
    }
};
// ListNode* create_list ;
int main() {
    Solution so;
    vector<int> A;
    ListNode* head;
    {
        A = {1, 2, 3, 4, 5, 10, 11, 12};
        head = ListNode::create_list(A);
        print_list(head);
        head = so.oddEvenList(head);
        print_list(head);
    }
    return 0;
}