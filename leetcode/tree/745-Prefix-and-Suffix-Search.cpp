#include <cstdio>
#include <iostream>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>
#include "../data_type.h"

using namespace std;
const int N = 26;
struct TrieNode {
    char ch;
    vector<TrieNode*> child;  //(N, nullptr);
    set<int> idx;
    int pre;
    int suf;
    TrieNode(int p = 0, int s = 0) {
        pre = p;
        suf = s;
        child = vector<TrieNode*>(N, nullptr);
    }
};
class WordFilter {
   public:
    TrieNode trie;
    vector<int> length;
    WordFilter(vector<string>& words) {
        auto n = &trie;
        int idx;
        for (int i = 0; i < words.size(); ++i) {
            n = &trie;
            auto w = words[i];
            length.push_back(w.size());
            for (int j = 0; j < w.size(); ++j) {
                idx = w[j] - 'a';
                if (n->child[idx] == nullptr) {
                    n->child[idx] = new TrieNode(1, 0);
                }
                n->idx.insert(i);
                n = n->child[idx];
            }
            n = &trie;
            for (int j = w.size() - 1; j >= 0; --j) {
                idx = w[j] - 'a';
                if (n->child[idx] == nullptr) {
                    n->child[idx] = new TrieNode(0, 1);
                }
                n->idx.insert(i);
                n = n->child[idx];
            }
        }
    }
    TrieNode* pre_search(string w) {
        auto n = &trie;
        int idx;
        for (auto ch : w) {
            idx = ch - 'a';
            if (n->child[idx] == nullptr)
                return nullptr;
            if (n->child[idx]->pre == 0) {
                return nullptr;
            }
            n = n->child[idx];
        }
        return n;
    }
    TrieNode* suf_search(string w) {
        auto n = &trie;
        int idx;
        for (auto ch : w) {
            idx = ch - 'a';
            if (n->child[idx] == nullptr)
                return nullptr;
            if (n->child[idx]->suf == 0) {
                return nullptr;
            }
            n = n->child[idx];
        }
        return n;
    }

    int f(string prefix, string suffix) {
        auto pre = pre_search(prefix);
        auto suf = suf_search(suffix);
        if (pre == nullptr || suf == nullptr) {
            return -1;
        }
        printf("pre:%d suf:%d\n", pre->pre, suf->suf);
        set<int> s;
        for (auto e : pre->idx) {
            if (suf->idx.count(e)) {
                s.insert(e);
            }
        }
        int r = -1;
        for (auto e : s) {
            if (r < 0) {
                r = e;
            }
            if (length[r] < length[e]) {
                r = e;
            }
        }
        return r;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
int main() {
    // WordFilter so;
    vector<string> words;
    words = {"apple", "e", "a", "absle"};
    WordFilter* obj = new WordFilter(words);
    string prefix, suffix;
    prefix = "a";
    suffix = "el";
    int r = obj->f(prefix, suffix);
    cout << "pre:" << prefix << ",suf:" << suffix << ":" << r << endl;
    return 0;
}