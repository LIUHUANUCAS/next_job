#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "../data_type.h"

using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        head = dup(head);
        head = update(head);
        return cut(head);
    }
    Node* cut(Node* head) {
        if (head == nullptr)
            return head;
        auto p = head;
        Node n = Node(0);
        auto q = &n;
        while (p) {
            auto next = p->next->next;
            q->next = p->next;
            q = q->next;
            q->next = nullptr;
            p->next = next;
            p = next;
        }
        return n.next;
    }
    Node* update(Node* head) {
        if (head == nullptr)
            return head;
        auto p = head;
        while (p) {
            auto n = p->next;
            if (p->random) {
                n->random = p->random->next;
            }
            p = p->next->next;
        }
        return head;
    }
    Node* dup(Node* head) {
        if (head == nullptr)
            return head;
        auto next = head->next;
        auto n = new Node(head->val);
        auto r = dup(next);
        n->next = next;
        head->next = n;
        return head;
    }
};
int main() {
    Solution so;

    return 0;
}