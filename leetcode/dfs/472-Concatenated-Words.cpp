#include <cstdio>
#include <iostream>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>
#include "../data_type.h"

using namespace std;
struct TrieNode {
    int isword, idx;
    unordered_map<char, TrieNode*> child;
    string word;
    TrieNode() {}
    void add(string& s) {
        auto n = this;
        for (auto ch : s) {
            if (n->child.find(ch) == n->child.end()) {
                n->child[ch] = new TrieNode();
            }
            n = n->child[ch];
        }
        n->isword = 1;
        n->word = s;
    }
};
class Solution {
   public:
    TrieNode trie;
    vector<string> res;
    set<string> word_set;
    unordered_set<string> visit;
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        res = vector<string>();
        trie = TrieNode();
        word_set = set<string>();
        size_t len = INT_MAX;
        for (auto& w : words) {
            trie.add(w);
            len = min(len, w.size());
        }
        vector<string> path;
        for (auto& w : words) {
            if (w.size() >= 2 * len) {
                dfs(w, 0, 0, &trie, path);
            }
        }

        return vector<string>(word_set.begin(), word_set.end());
    }

    int dfs(string& w, int start, int k, TrieNode* n, vector<string>& path) {
        int size = w.size();
        if (start == size) {
            if (k > 1) {
                printvector(path);
                word_set.insert(w);
            }
            return k > 1;
        }
        int r = 0;
        if (n == nullptr || start > size)
            return 0;
        for (int i = start; i < size; i++) {
            auto it = n->child.find(w[i]);
            if (it == n->child.end())
                return 0;
            n = n->child[w[i]];
            if (n == nullptr) {
                return 0;
            }
            if (n->isword) {
                path.push_back(n->word);
                if (dfs(w, i + 1, k + 1, &trie, path)) {  /// 裁支
                    r = 1;
                    path.pop_back();
                    return 1;
                }
                path.pop_back();
                // return r;
            }
        }
        return 0;
    }
    void printvector(vector<string>& str) {
        cout << "[";
        for (auto e : str) {
            cout << e << " ";
        }
        cout << "]" << endl;
    }
};
int main() {
    Solution so;
    vector<string> words;
    {
        words = {"cat",        "cats",           "catsdogcats", "dog",
                 "dogcatsdog", "hippopotamuses", "rat",         "ratcatdogcat"};
        cout << words.size() << endl;
        auto r = so.findAllConcatenatedWordsInADict(words);
        cout << r.size() << endl;
        printvector(r);
    }
    {
        words = {"cat", "dog", "catdog"};
        auto r = so.findAllConcatenatedWordsInADict(words);
        printvector(r);
    }
    {
        words = {"cat", "dog", "catdogs", "dogcat", "catdog", "s"};
        auto r = so.findAllConcatenatedWordsInADict(words);
        printvector(r);
    }

    {
        words = {"aa", "aajpfpyljt", "a"};
        auto r = so.findAllConcatenatedWordsInADict(words);
        printvector(r);
    }
    return 0;
}