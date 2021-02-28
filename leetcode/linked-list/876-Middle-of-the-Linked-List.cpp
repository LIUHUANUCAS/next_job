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
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr)
            return head;
        auto fast = head;
        auto slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
int main() {
    Solution so;
    vector<int> A;
    int m, n;
    {
        A = {1, 2, 3, 4, 5, 6};
        auto l = ListNode::create_list(A);
        print_list(l);
        print_list(so.middleNode(l));
    }
    {
        A = {1, 2, 3};
        auto l = ListNode::create_list(A);
        print_list(l);
        print_list(so.middleNode(l));
    }
    return 0;
}
