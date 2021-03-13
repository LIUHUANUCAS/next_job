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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return;
        merge_dfs(head, reverse(mid(head)));
        // merge(head, reverse(mid(head)));
    }
    ListNode* mid(ListNode* head) {
        auto fast = head, slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        auto h = slow->next;
        slow->next = nullptr;
        return h;
    }
    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        auto n = head->next;
        auto r = reverse(head->next);
        n->next = head;
        head->next = nullptr;
        return r;
    }

    ListNode* merge_dfs(ListNode* head, ListNode* newHead) {
        if (head == nullptr)
            return newHead;
        if (newHead == nullptr)
            return head;

        auto pnext = head->next;
        auto qnext = newHead->next;

        head->next = newHead;
        newHead->next = nullptr;
        auto r = merge(pnext, qnext);
        newHead->next = r;
        return head;
    }
    ListNode* merge(ListNode* head, ListNode* newHead) {
        if (head == nullptr)
            return newHead;
        if (newHead == nullptr)
            return head;

        ListNode d(0);
        auto tail = &d;
        auto p = head, q = newHead;
        while (p && q) {
            auto pnext = p->next;
            auto qnext = q->next;

            tail->next = p;
            tail = p;
            p->next = nullptr;

            tail->next = q;
            tail = q;
            q->next = nullptr;

            p = pnext;
            q = qnext;
        }

        if (p) {
            tail->next = p;
        }

        if (q) {
            tail->next = q;
        }
        return d.next;
    }
};
int main() {
    Solution so;
    vector<int> A;
    int k;
    k = 2;
    A = {1, 2, 4, 5, 6, 8, 10};
    auto l = ListNode::create_list(A);
    print_list(l);
    so.reorderList(l);
    print_list(l);
    return 0;
}
