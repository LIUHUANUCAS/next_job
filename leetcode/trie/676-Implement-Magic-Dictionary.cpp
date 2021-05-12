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
class MagicDictionary {
    int end;
    unordered_map<char, MagicDictionary*> child;
    void add(const string& w) {
        auto n = this;
        for (auto c : w) {
            if (n->child.find(c) == n->child.end())
                n->child[c] = new MagicDictionary();
            n = n->child[c];
        }
        n->end = 1;
    }
    int search_string(const string& w) {
        auto n = this;
        for (auto c : w) {
            if (n->child.find(c) == n->child.end())
                return 0;
            n = n->child[c];
        }
        return n->end;
    }

   public:
    /** Initialize your data structure here. */
    MagicDictionary() : end(0) {}  // end should be zero when init

    void buildDict(vector<string> dictionary) {
        for (auto& s : dictionary) {
            add(s);
        }
    }

    bool search(string w) {
        int N = 26;
        int n = w.size();
        for (int i = 0; i < n; i++) {
            auto c = w[i];
            for (int j = 0; j < N; j++) {
                auto ch = 'a' + j;
                w[i] = ch;
                // cout << "search:" << w << endl;
                if (ch != c && search_string(w)) {
                    return 1;
                }
                w[i] = c;
            }
        }
        return 0;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
int main() {
    MagicDictionary* obj;
    int r;
    string searchWord;
    vector<string> dictionary;
    {
        obj = new MagicDictionary();
        dictionary = {"hello", "leetcode"};
        searchWord = "hello";
        obj->buildDict(dictionary);
        r = obj->search(searchWord);
        cout << searchWord << ":" << r << endl;
    }
    {
        obj = new MagicDictionary();
        dictionary = {"hello", "leetcode"};
        searchWord = "hhllo";
        obj->buildDict(dictionary);
        r = obj->search(searchWord);
        cout << searchWord << ":" << r << endl;
    }
    {
        obj = new MagicDictionary();
        dictionary = {"hello", "leetcode"};
        searchWord = "hell";
        obj->buildDict(dictionary);
        r = obj->search(searchWord);
        cout << searchWord << ":" << r << endl;
    }
    {
        obj = new MagicDictionary();
        dictionary = {"hello", "leetcode"};
        searchWord = "leetcoded";
        obj->buildDict(dictionary);
        r = obj->search(searchWord);
        cout << searchWord << ":" << r << endl;
    }
    {
        obj = new MagicDictionary();
        dictionary = {"hello", "hallo", "leetcode"};
        vector<string> list = {"hello", "hhllo", "hell", "leetcoded"};
        obj->buildDict(dictionary);
        for (auto w : list) {
            r = obj->search(w);
            cout << w << ":" << r << endl;
        }
    }
    return 0;
}