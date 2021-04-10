
/**
描述符：
vid1 -> tag_list:[a1,b2,c1]
vid2 -> tag_list:[a1,b3,c4]

vidn

n = 100*10000
taglist:10
1000*10000

1、统计所有标签排序，topk问题
2、统计一部分写入文件hash表，在内存中能够存下，然后写入磁盘。生成x个文件。
3、从每个文件中，拿去topk个，到内存里。归并。[a,b] + [c ,d] -> [a,c]
*/
/**
atoi()实现
1.空格，加号减号
2.数字结束后，之后字符省略。任意在字符
string -> int [INT_MIN,INT_MAX]
*/
#include <iostream>
#include <vector>
using namespace std;
struct Node {
    int val;
    Node* next;
    Node(int v = 0) : val(v), next(nullptr) {}
};
struct Solution {
    Node* reverse_list(Node* head, int k) {
        if (head == nullptr || k <= 0)
            return head;
        Node* p = head;
        Node d;
        Node* q = &d;
        while (p && k) {
            //插入到q
            Node* next = p->next;
            p->next = q->next;
            q->next = p;
            //
            p = next;
            k--;
        }
        head->next = p;
        return d.next;
    }
    Node* create_list(vector<int>& A) {
        Node *head = nullptr, *p = nullptr;
        for (auto e : A) {
            if (head == nullptr) {
                head = p = new Node(e);
            } else {
                p->next = new Node(e);
                p = p->next;
            }
        }
        return head;
    }
    void print_list(Node* head) {
        while (head) {
            printf("%d ", head->val);
            head = head->next;
        }
        cout << endl;
    }
};
int main() {
    Solution so;
    vector<int> A;
    int k;
    {
        A = {1, 2, 3, 4};
        k = 3;
        so.print_list(so.reverse_list(so.create_list(A), k));
    }

    {
        A = {1, 2, 3, 4};
        k = 4;
        so.print_list(so.reverse_list(so.create_list(A), k));
    }
}
