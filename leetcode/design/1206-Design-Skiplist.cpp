#include <cstdio>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;
const int N = 32;
const double p = 0.5;
const int Max = 10 * 1000;
struct Node {
    int val;
    vector<Node*> forward;
    Node(int v = 0) : val(v), forward(vector<Node*>(N + 1, nullptr)) {}
};
class Skiplist {
    Node* head;
    int size;
    int get_random_level() {
        int height = 1;
        while (getrand() < p && height < N) {
            height++;
        }
        return height;
    }

   public:
    double getrand() {
        auto r = (std::rand() + 1) % Max;
        return double(r) / Max;
    }
    Skiplist() : size(0) { head = new Node(); }

    bool search(int target) {
        Node* x = head;
        for (int i = N; i >= 0; i--) {
            while (x->forward[i] != nullptr && x->forward[i]->val < target) {
                x = x->forward[i];
            }
        }
        x = x->forward[0];
        return x != nullptr && x->val == target;
    }

    void add(int num) {
        Node* n = new Node(num);
        Node* x = head;
        vector<Node*> update(N + 1, nullptr);
        for (int i = N; i >= 0; i--) {
            while (x->forward[i] != nullptr && x->forward[i]->val < num) {
                x = x->forward[i];
            }
            update[i] = x;
        }
        Node* next = x->forward[0];
        if (next != nullptr && next->val == num)
            return;
        int height = get_random_level();
        for (int i = 0; i < height; i++) {
            n->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = n;
        }
        size++;
    }

    bool erase(int num) {
        Node* x = head;
        vector<Node*> update(N + 1, nullptr);
        for (int i = N; i >= 0; i--) {
            while (x->forward[i] != nullptr && x->forward[i]->val < num) {
                x = x->forward[i];
            }
            update[i] = x;
        }
        Node* next = x->forward[0];
        if (next == nullptr || next->val != num)
            return 0;
        for (int i = 0; i < N; i++) {
            if (update[i]->forward[i] != next)
                break;
            update[i]->forward[i] = next->forward[i];
        }
        size--;
        return 1;
    }
    void print_level(int l) {
        if (l > N)
            return;
        auto x = head->forward[l];
        int c = 0;
        printf("level:%d [", l);
        while (x != nullptr) {
            printf("%d ", x->val);
            x = x->forward[l];
            c++;
        }
        printf("] %d\n", c);
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
int getRand(int m, int n)  //获取[m,n]的随机数
{
    int r = (int)(m + (std::rand() + 1) %
                          ((n + 1) - m));  //产生范围为[m,n]的随机数。

    return r;
}
int main() {
    // Solution so;
    Skiplist sk;
    int N = 100;
    // for (int i = 0; i < 100; i++) {
    //     // auto r = getRand(0, N);
    //     // cout << double(r) / N << " ";
    //     auto y = sk.getrand();
    //     cout << y << " ";
    // }
    // cout << endl;
    for (int i = 1; i < N; i++) {
        sk.add(i);
    }
    sk.erase(10);
    sk.print_level(0);
    sk.print_level(9);

    return 0;
}