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
    ListNode* sortList(ListNode* head) { return sort(head, nullptr); }
    // sort list using merge-sort
    ListNode* sort(ListNode* head, ListNode* tail) {  // tail is unused!
        if (head == nullptr || head->next == nullptr)
            return head;
        auto fast = head;
        auto slow = head;
        ListNode* pre = nullptr;
        while (fast && fast->next) {
            pre = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        if (pre)
            pre->next = nullptr;
        auto l1 = sort(head, nullptr);
        auto l2 = sort(slow, nullptr);
        return merge(l1, l2);
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        if (l1->val <= l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        }
        l2->next = merge(l1, l2->next);
        return l2;
    }
};
int main() {
    Solution so;
    vector<int> A;
    int k;
    k = 2;
    A = {1, 2, 3, 4, 5, 6};
    {
        A = {6, 8, 5, 3, 1};
        auto l = ListNode::create_list(A);
        cout << "list: ";
        print_list(l);
        print_list(so.sortList(l));
    }
    {
        A = {2, 1};
        auto l = ListNode::create_list(A);
        cout << "list: ";
        print_list(l);
        print_list(so.sortList(l));
    }
    {
        A = {2};
        auto l = ListNode::create_list(A);
        cout << "list: ";
        print_list(l);
        print_list(so.sortList(l));
    }
    {
        A = {};
        auto l = ListNode::create_list(A);
        cout << "list: ";
        print_list(l);
        print_list(so.sortList(l));
    }
    return 0;
}
