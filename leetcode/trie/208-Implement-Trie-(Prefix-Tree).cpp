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

class Trie {
    string word;
    unordered_map<char, Trie*> list;

   public:
    /** Initialize your data structure here. */
    Trie() {}

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto r = this;
        for (auto c : word) {
            if (r->list.find(c) == r->list.end()) {
                r->list[c] = new Trie();
            }
            r = r->list[c];
        }
        r->word = word;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto r = this;
        for (auto c : word) {
            if (r->list.find(c) == r->list.end()) {
                return false;
            }
            r = r->list[c];
        }

        return !r->word.empty();
    }

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool startsWith(string prefix) {
        auto r = this;
        for (auto c : prefix) {
            if (r->list.find(c) == r->list.end()) {
                return false;
            }
            r = r->list[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
int main() {
    Trie* obj;
    string word, prefix;
    int r;
    {
        obj = new Trie();
        word = "apple";
        prefix = "appl";
        obj->insert(word);
        r = obj->search(word);
        cout << word << ":" << r << endl;
        r = obj->startsWith(prefix);
        cout << prefix << ":" << r << endl;
    }

    return 0;
}