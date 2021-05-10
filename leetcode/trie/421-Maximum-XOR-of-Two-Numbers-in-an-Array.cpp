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
    vector<Trie*> child;
    int num;
    Trie() : num(0), child(vector<Trie*>(2, nullptr)) {}
    void add(int n) {
        Trie* node = this;
        for (int i = N - 1; i >= 0; --i) {
            int idx = (n >> i) & 0x01;
            if (node->child[idx] == nullptr) {
                node->child[idx] = new Trie();
            }
            // cout << idx << endl;
            node = node->child[idx];
        }
        node->num = n;
    }
    int search(int n) {
        Trie* node = this;
        int sum = 0;
        for (int i = N - 1; i >= 0; --i) {
            int idx = (n >> i) & 0x01;
            if (node->child[idx ^ 0x01] != nullptr) {
                node = node->child[idx ^ 0x01];
                sum += 1 << i;
            } else {
                node = node->child[idx];
            }
        }
        return sum;
    }
};

class Solution {
   public:
    Trie* node;
    int findMaximumXOR(vector<int>& A) {
        node = new Trie();
        for (auto n : A) {
            node->add(n);
        }
        int maxsum = INT_MIN;
        for (auto n : A) {
            auto r = node->search(n);
            maxsum = max(r, maxsum);
        }
        return maxsum;
    }
};
int main() {
    Solution so;
    vector<int> A;
    int r;
    {
        A = {3, 10, 5, 25, 2, 8};
        r = so.findMaximumXOR(A);
        cout << r << endl;
    }
    {
        A = {2, 4};
        r = so.findMaximumXOR(A);
        cout << r << endl;
    }
    {
        A = {0};
        r = so.findMaximumXOR(A);
        cout << r << endl;
    }
    {
        A = {8, 10, 2};
        r = so.findMaximumXOR(A);
        cout << r << endl;
    }
    {
        A = {14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70};
        r = so.findMaximumXOR(A);
        cout << r << endl;
    }
    return 0;
}