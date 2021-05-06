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
struct TrieNode {
    string word;
    unordered_map<char, TrieNode*> m;
    int idx;
    bool isWord() { return word.size() > 0; }
};
struct Trie {
    TrieNode* node;
    Trie() : node(new TrieNode()) {}
    void add(string w, int idx) {
        TrieNode* n = node;
        for (auto c : w) {
            if (n->m.find(c) == n->m.end()) {
                n->m[c] = new TrieNode();
            }
            n = n->m[c];
            if (idx > n->idx) {
                n->idx = idx;
            }
        }
        n->word = w;
    }
    TrieNode* search(string w) {
        TrieNode* n = node;
        for (auto c : w) {
            if (n->m.find(c) == n->m.end()) {
                return nullptr;
            }
            n = n->m[c];
        }
        return n;
    }
};
class WordFilter {
   public:
    Trie n;
    WordFilter(vector<string>& words) {
        int wsize = words.size();
        for (int i = 0; i < wsize; i++) {
            string t(words[i]);
            // n.add("#" + t, i);
            int size = t.size();
            for (int j = 0; j <= size; j++) {
                string s = t.substr(j);
                // cout << s + "#" + t << endl;
                n.add(s + "#" + t, i);
            }
        }
    }

    int f(string prefix, string suffix) {
        auto r = n.search(suffix + "#" + prefix);
        if (r == nullptr)
            return -1;
        return r->idx;
    }
};

int main() {
    vector<string> words;
    string prefix, suffix;

    {
        words = {"apple", "aple"};
        prefix = "a", suffix = "e";
        WordFilter* obj = new WordFilter(words);
        int r = obj->f(prefix, suffix);
        cout << r << endl;
    }
    return 0;
}