#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>

// #include "../data_type.h"

using namespace std;
// ## 请在下方进行输入 ( 支持Markdown、插入公式，点击上方按钮“环境说明”查看详情
// )

// input:
// 7 -> 3 -> 1 -> 0
//      4 -> 9 -> 3

// 7310+493=7803

// output:
// 7 -> 8 -> 0 -> 3

// 你必须定义一个 `main()` 函数入口。
#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
    ListNode() : val(0), next(nullptr) {}
};
ListNode* copyList(ListNode* ra, int& c, ListNode* tail);

ListNode* reverse(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode* n = head->next;
    ListNode* r = reverse(head->next);
    n->next = head;
    head->next = nullptr;
    return r;
}
ListNode* add(ListNode* a, ListNode* b) {
    if (a == nullptr)
        return b;
    if (b == nullptr)
        return a;
    ListNode* ra = reverse(a);
    ListNode* rb = reverse(b);
    ListNode d;
    ListNode* tail = &d;
    int c = 0;
    while (ra != nullptr && rb != nullptr) {
        int x = ra->val + rb->val + c;
        c = x / 10;
        x = x % 10;
        tail->next = new ListNode(x);
        tail = tail->next;

        ra = ra->next;
        rb = rb->next;
    }

    tail = copyList(ra, c, tail);
    tail = copyList(rb, c, tail);

    if (c > 0) {
        tail->next = new ListNode(c);
    }

    return reverse(d.next);
}
ListNode* copyList(ListNode* ra, int& c, ListNode* tail) {
    while (ra != nullptr) {
        int x = ra->val + c;
        c = x / 10;
        x = x % 10;
        tail->next = new ListNode(x);
        tail = tail->next;
        ra = ra->next;
    }
    return tail;
}

ListNode* f(vector<int>& a) {
    ListNode d;
    ListNode* tail = &d;
    for (auto e : a) {
        tail->next = new ListNode(e);
        tail = tail->next;
    }
    return d.next;
}

void print(ListNode* l) {
    while (l != nullptr) {
        cout << l->val << " ";
        l = l->next;
    }
    cout << endl;
}

int main() {
    vector<int> A, B;
    {
        A = {9, 9, 1, 0};
        B = {4, 9, 3};
        ListNode* a = f(A);
        ListNode* b = f(B);
        ListNode* c = add(a, b);
        print(a);
        print(b);
        print(c);
    }
    cout << "Hello, World!" << endl;
    return 0;
}