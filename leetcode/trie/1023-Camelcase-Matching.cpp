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
    void add(string& s) {
        auto n = this;
        for (auto c : s) {
            if (n->child.find(c) == n->child.end()) {
                n->child[c] = new Trie();
            }
            n = n->child[c];
        }
        n->end = 1;
    }
    int search(string& s) {
        auto n = this;
        return dfs(s, 0, n);
    }
    int dfs(string& s, int i, Trie* n) {
        if (n == nullptr)
            return 0;
        if (i == s.size())
            return n->end;
        int size = s.size();
        for (int j = i; j < size; j++) {
        }
        return 0;
    }
};
class Solution {
   public:
    Trie* root;
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        root = new Trie();
        for (auto& w : queries) {
            root->add(w);
        }
        int n = queries.size();
        vector<bool> res(n, 0);
        for (int i = 0; i < n; i++) {
            // res[i] = root->search(queries[i]);
            res[i] = dfs(queries[i], 0, pattern, 0);
        }

        return res;
    }
    int dfs(string& s, int i, string& t, int j) {
        int m = s.size(), n = t.size();
        if (i == m && j == n)
            return 1;
        if (i == m)
            return 0;
        if (j == n) {
            // printf("j=ni,j:%d %c %d\n", i, s[i], j);
            return (s[i] >= 'a' && s[i] <= 'z') && dfs(s, i + 1, t, j);
        }
        // printf("i,j:%d %c %d %c\n", i, s[i], j, t[j]);
        if (s[i] == t[j]) {
            return dfs(s, i + 1, t, j + 1);
        }
        return s[i] >= 'a' && s[i] <= 'z' && dfs(s, i + 1, t, j);
    }
};
int main() {
    Solution so;
    vector<string> queries;
    string pattern;
    vector<bool> r;
    // {
    //     queries = {"FooBar", "FooBarTest", "FootBall", "FrameBuffer",
    //                "ForceFeedBack"};
    //     pattern = "FB";
    //     r = so.camelMatch(queries, pattern);
    //     printvector(r);
    // }
    // {
    //     queries = {"FooBar", "FooBarTest", "FootBall", "FrameBuffer",
    //                "ForceFeedBack"};
    //     pattern = "FoBa";
    //     r = so.camelMatch(queries, pattern);
    //     printvector(r);
    // }

    // {
    //     queries = {"FooBar", "FooBarTest", "FootBall", "FrameBuffer",
    //                "ForceFeedBack"};
    //     pattern = "FoBaT";
    //     r = so.camelMatch(queries, pattern);
    //     printvector(r);
    // }
    {
        // queries = {"aksvbjLiknuTzqon", "ksvjLimflkpnTzqn",
        // "mmkasvjLiknTxzqn",
        //            "ksvjLiurknTzzqbn", "ksvsjLctikgnTzqn",
        //            "knzsvzjLiknTszqn"};
        queries = {"ksvjLiurknTzzqbn", "ksvsjLctikgnTzqn", "knzsvzjLiknTszqn"};
        pattern = "ksvjLiknTzqn";
        r = so.camelMatch(queries, pattern);
        printvector(r);
    }
    return 0;
}