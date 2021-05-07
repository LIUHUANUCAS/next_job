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
const int N = 32;
struct Trie {
    int bit;
    vector<Trie*> child;
    int num;
    int max_pre;
    Trie() : max_pre(N), bit(0), num(0), child(vector<Trie*>(2, nullptr)) {}
    void add(int n) {
        vector<int> bit(N, 0);
        getbit(n, bit);
        Trie* node = this;
        for (int i = 0; i < N; i++) {
            if (node->child[bit[i]] == nullptr) {
                node->child[bit[i]] = new Trie();
            }
            node = node->child[bit[i]];
        }
        node->num = n;
        // cout << n << " ";
        // printvector(bit);
    }
    Trie* search(int n) {
        vector<int> bit(N, 1);
        // key for search,we should search from highest bit with 1 in all
        // number.for example insert number n = [0,0,1,0,0]=4, when  search x =
        // 3=[0,0,0,1,1],we should give the binary format with x =
        // [1,1,0,1,1],not the format x = [1,1,1,1,1],highest bit is
        // siginificant
        for (int i = max_pre; i < N; i++) {
            bit[i] = 0;
        }
        getbit(n, bit);
        Trie* node = this;
        for (int i = 0; i < N; i++) {
            auto idx = !bit[i];
            if (node->child[idx] == nullptr) {
                node = node->child[!idx];
            } else {
                node = node->child[idx];
            }
            if (node == nullptr) {
                // printf("nullptr:%d\n", n);
                return node;
            }
        }
        // printvector(bit);
        // printf("re:%d %d\n", node->num, n);
        return node;
    }
    void getbit(int n, vector<int>& bit) {
        // vector<int> bit(N, 1);
        // cout << n << " ";
        int i;
        for (i = N - 1; i >= 0 && n > 0; i--) {
            bit[i] = n & 0x01;
            n /= 2;
        }
        max_pre = min(i, max_pre);
        // printvector(bit);
    }
};
class Solution {
   public:
    Trie* trie;
    vector<int> maximizeXor(vector<int>& A, vector<vector<int>>& Q) {
        trie = new Trie();
        sort(A.begin(), A.end());
        for (int i = 0; i < Q.size(); i++) {
            Q[i].push_back(i);
        }
        sort(Q.begin(), Q.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
        int idx = 0, n = A.size();
        vector<int> res(Q.size(), 0);
        for (auto q : Q) {
            int x = q[0], m = q[1], ridx = q[2];
            for (; idx < n && A[idx] <= m; idx++) {  // add number <= m
                trie->add(A[idx]);
            }
            auto r = trie->search(x);
            int y = -1;
            if (r != nullptr)
                y = x ^ r->num;
            res[ridx] = y;
        }
        return res;
    }
};
int main() {
    Solution so;
    vector<int> A;
    vector<vector<int>> Q;
    {
        A = {0, 1, 2, 3, 4};
        Q = {{3, 1}, {1, 3}, {5, 6}};
        auto r = so.maximizeXor(A, Q);
        printvector(r);
    }

    {
        A = {5, 2, 4, 6, 6, 3};
        Q = {{12, 4}, {8, 1}, {6, 3}};
        auto r = so.maximizeXor(A, Q);
        printvector(r);
    }
    {
        A = {0, 4, 6, 6, 3};
        Q = {{12, 4}, {8, 1}, {6, 3}};
        auto r = so.maximizeXor(A, Q);
        printvector(r);
    }
    return 0;
}