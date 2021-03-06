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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        function<bool(ListNode*, ListNode*)> cmp =
            [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>,
                       function<bool(ListNode*, ListNode*)>>
            que(cmp);
        for (auto e : lists) {
            if (e != nullptr) {
                que.push(e);
            }
        }
        ListNode d(0);
        ListNode* p = &d;
        while (!que.empty()) {
            auto x = que.top();
            que.pop();
            p->next = x;
            p = x;
            if (x->next) {
                que.push(x->next);
            }
            p->next = nullptr;
        }
        return d.next;
    }
};
int main() {
    Solution so;

    return 0;
}
