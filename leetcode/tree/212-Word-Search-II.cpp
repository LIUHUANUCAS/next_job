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
    // int isend;
    string word;
    unordered_map<char, TrieNode*> list;
    TrieNode() {}
};
class Trie {
    TrieNode* root;

   public:
    /** Initialize your data structure here. */
    Trie() { root = new TrieNode(); }

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto r = root;
        for (auto c : word) {
            if (r->list.find(c) == r->list.end()) {
                r->list[c] = new TrieNode();
            }
            r = r->list[c];
        }
        r->word = word;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto r = root;
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
        auto r = root;
        for (auto c : prefix) {
            if (r->list.find(c) == r->list.end()) {
                return false;
            }
            r = r->list[c];
        }
        return true;
    }
};
class Solution {
   public:
    Trie trie;
    // vector<string> res;
    set<string> set;
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        for (auto w : words) {
            trie.insert(w);
        }
        for (auto w : words) {
            if (exist(board, w)) {
                set.insert(w);
            }
        }
        return vector<string>(set.begin(), set.end());
    }
    bool exist(vector<vector<char>>& board, string& w) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, i, j, w, 0)) {
                    // set.insert(w);
                    return 1;
                }
            }
        }
        return 0;
    }
    int dfs(vector<vector<char>>& g, int i, int j, string& w, int idx) {
        int m = g.size();
        int n = g[0].size();

        if (i < 0 || i >= m || j < 0 || j >= n || g[i][j] == '#' ||
            idx >= w.size() || idx < 0 || w[idx] != g[i][j])
            return 0;
        if (idx + 1 == w.size())
            return 1;
        // if (!w.empty() && !trie.startsWith(w))
        //     return 0;
        auto x = g[i][j];
        g[i][j] = '#';
        // w.push_back(x);
        // if (trie.search(w)) {
        //     set.insert(w);
        // }
        auto y = dfs(g, i + 1, j, w, idx + 1);
        if (y == 0)
            y += dfs(g, i - 1, j, w, idx + 1);
        if (y == 0)
            y += dfs(g, i, j - 1, w, idx + 1);
        if (y == 0)
            y += dfs(g, i, j + 1, w, idx + 1);
        // w.pop_back();
        g[i][j] = x;
        return y;
    }
};
int main() {
    Solution so;
    vector<vector<char>> B;
    vector<string> w;

    B = {{'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
         {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
         {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
         {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
         {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
         {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
         {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
         {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
         {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
         {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
         {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
         {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'}};
    w = {"a",      "aa",      "aaa",      "aaaa",      "aaaaa",
         "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};
    auto r = so.findWords(B, w);
    printvector(r);
    return 0;
}