#include <cstdio>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_map>
#include <vector>
#include "../data_type.h"

using namespace std;
const int N = 26;
struct TrieNode {
    char ch;
    unordered_map<char, TrieNode*> child;
    int isleaf;
};

struct Trie {
    TrieNode node;
    Trie() {}
    void insert(string& w) {
        auto n = &node;
        for (auto c : w) {
            if (n->child.find(c) == n->child.end()) {
                n->child[c] = new TrieNode();
                n->child[c]->ch = c;
            }
            n = n->child[c];
        }
        n->isleaf = 1;
    }
    int prefix(string w) {
        auto n = &node;
        for (auto c : w) {
            if (n->child.find(c) == n->child.end()) {
                return 0;
            }
            n = n->child[c];
        }
        return n != nullptr && n->isleaf == 1;
    }
};
class Solution {
   public:
    string longestWord(vector<string>& words) {
        Trie trie;
        for (auto& w : words) {
            trie.insert(w);
        }
        int midx = -1;
        for (int i = 0; i < words.size(); ++i) {
            int f = 1;
            for (int j = 1; j < words[i].size(); ++j) {
                f += trie.prefix(words[i].substr(0, j));
            }
            cout << f << " " << words[i] << endl;
            if (f == words[i].size()) {
                if (midx < 0) {
                    midx = i;

                } else if (words[i].size() > words[midx].size() ||
                           ((words[i].size() == words[midx].size() &&
                             words[i] < words[midx]))) {
                    midx = i;
                }
            }
        }
        return midx >= 0 ? words[midx] : "";
    }
};

int main() {
    Solution so;
    vector<string> A;
    A = {"w", "wo", "wor", "worl", "world"};
    A = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    A = {"ca", "banana"};
    auto r = so.longestWord(A);
    cout << r << endl;
    return 0;
}