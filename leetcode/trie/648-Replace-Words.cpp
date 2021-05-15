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
    string w;
    unordered_map<char, Trie*> child;
    Trie() : end(0) {}
    void add(string s) {
        auto n = this;
        for (auto c : s) {
            if (n->child.find(c) == n->child.end()) {
                n->child[c] = new Trie();
            }
            n = n->child[c];
        }
        n->end = 1;
        n->w = s;
    }
    Trie* search(string w) {
        auto n = this;
        for (auto c : w) {
            if (n->end) {
                return n;
            }
            if (n->child.find(c) == n->child.end()) {
                return n;
            }
            n = n->child[c];
        }
        return n;
    }
};
class Solution {
   public:
    string replaceWords(vector<string>& d, string s) {
        Trie* root = new Trie();
        for (auto& s : d) {
            root->add(s);
        }
        // split(s);
        stringstream sst;
        int n = s.size(), j = 0;
        for (int i = 0; i < n; i = j + 1) {
            j = i;
            while (j < n && s[j] != ' ')
                j++;
            string str(s.begin() + i, s.begin() + j);
            // cout << str << endl;
            auto r = root->search(str);
            string st(str);
            if (r->end) {
                st = r->w;
            }
            // cout << str << ":" << st << endl;
            sst << st << " ";
        }
        string res(sst.str());
        if (!res.empty()) {
            res.pop_back();
        }
        return res;
    }
    vector<string> split(string& s) {
        int n = s.size();
        vector<string> res;
        for (int i = 0, j = 0; i < n; i = j + 1) {
            j = i;
            while (j < n && s[j] != ' ')
                j++;
            string str(s.begin() + i, s.begin() + j);
            res.push_back(str);
            // cout << str << endl;
        }
        return res;
    }
};
int main() {
    Solution so;
    vector<string> dictionary;
    string sentence, r;
    {
        dictionary = {"cat", "bat", "rat"};
        sentence = "the cattle was rattled by the battery";
        r = so.replaceWords(dictionary, sentence);
        cout << r << endl;
    }
    {
        dictionary = {"a", "b", "c"};
        sentence = "aadsfasf absbs bbab cadsfafs";
        r = so.replaceWords(dictionary, sentence);
        cout << r << endl;
    }
    {
        dictionary = {"a", "aa", "aaa", "aaaa"};
        sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa";
        r = so.replaceWords(dictionary, sentence);
        cout << r << endl;
    }
    {
        dictionary = {"catt", "cat", "bat", "rat"};
        sentence = "the cattle was rattled by the battery";
        r = so.replaceWords(dictionary, sentence);
        cout << r << endl;
    }
    {
        dictionary = {"ac", "ab"};
        sentence = "it is abnormal that this solution is accepted";
        r = so.replaceWords(dictionary, sentence);
        cout << r << endl;
    }
    return 0;
}