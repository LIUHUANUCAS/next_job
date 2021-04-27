#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>

// #include "../data_type.h"

using namespace std;
struct Node {
    int val;
    Node* next;
    Node(int v = 0) : val(v), next(nullptr) {}
};
class MyLinkedList {
   public:
    // int val;
    Node node;
    Node* tail;
    int len;
    /** Initialize your data structure here. */
    MyLinkedList() {
        tail = nullptr;
        len = 0;
    }
    void printlist() {
        auto p = &node;
        while (p->next) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
    /** Get the value of the index-th node in the linked list. If the index is
     * invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= len) {
            return -1;
        }
        auto p = &node;
        for (int i = 0; i < index; i++) {
            p = p->next;
        }
        printlist();
        return p->val;
    }

    /** Add a node of value val before the first element of the linked list.
     * After the insertion, the new node will be the first node of the linked
     * list. */
    void addAtHead(int val) {
        auto n = new Node(val);
        n->next = node.next;
        node.next = n;
        if (len == 0)
            tail = n;
        len++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if (len == 0) {
            addAtHead(val);
            return;
        }
        auto n = new Node(val);
        tail->next = n;
        tail = n;
        len++;
    }

    /** Add a node of value val before the index-th node in the linked list. If
     * index equals to the length of linked list, the node will be appended to
     * the end of linked list. If index is greater than the length, the node
     * will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index >= len || index < 0)
            return;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        if (index == len) {
            addAtTail(val);
            return;
        }
        auto p = &node;
        for (int i = 0; i < index; i++) {
            p = p->next;
        }
        auto n = new Node(val);
        n->next = p->next;
        p->next = n;
        len++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (invalid_index(index)) {
            return;
        }
        auto p = &node;
        for (int i = 0; i < index; i++) {
            p = p->next;
        }
        auto d = p->next;
        p->next = d->next;
        delete d;
    }

    int invalid_index(int idx) { return idx < 0 || idx >= len; }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
int main() {
    return 0;
}
