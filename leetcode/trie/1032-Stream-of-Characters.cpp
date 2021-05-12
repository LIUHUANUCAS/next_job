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
struct Trie {
    int end;
    unordered_map<char, Trie*> child;
    Trie() : end(0) {}
    void add(string w) {
        auto n = this;
        for (auto c : w) {
            if (n->child.find(c) == n->child.end())
                n->child[c] = new Trie();
            n = n->child[c];
        }
        n->end = 1;
    }
    int search(deque<char>& dque) {
        auto n = this;
        for (int i = dque.size() - 1; i >= 0; i--) {
            char ch = dque[i];
            if (n->child.find(ch) == n->child.end())
                return 0;
            n = n->child[ch];
            if (n->end)
                return 1;
        }
        return 0;
    }
};
class StreamChecker {
    Trie *root, *cur;
    deque<char> dque;
    int max_len = 0;

   public:
    StreamChecker(vector<string>& words) {
        root = new Trie();
        cur = root;
        for (auto w : words) {
            max_len = max(max_len, int(w.size()));
            reverse(w.begin(), w.end());
            root->add(w);
        }
    }

    bool query(char c) {
        dque.push_back(c);
        if (dque.size() > max_len) {
            dque.pop_front();
        }
        return root->search(dque);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
int main() {
    StreamChecker* obj;
    int r;
    vector<char> list;
    vector<string> words;
    {
        words = {"cd", "f", "kl"};
        obj = new StreamChecker(words);
        list = {'a', 'b', 'c', 'd', 'e', 'f', 'i', 'j', 'k', 'l', 'm'};
        for (auto c : list) {
            r = obj->query(c);
            cout << c << ":" << r << endl;
        }
    }
    return 0;
}