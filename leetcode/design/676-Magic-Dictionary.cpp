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
  const static int N = 26;
  struct Trie {
    int end;
    Trie *child[N];
  };
  Trie *node;
  void add(string s) {
      if (s.empty()) return;
      Trie* n = node;
      for (auto c : s) {
          if (n->child[c - 'a'] == nullptr) n->child[c - 'a'] = new Trie();
          n = n->child[c - 'a'];
    }
    n->end = 1;
  }
  int search_word(string s) {
      if (s.empty()) return 0;
      Trie* n = node;
      for (auto c : s) {
          if (n->child[c - 'a'] == nullptr) return 0;
          n = n->child[c - 'a'];
    }
    return n->end;
  }

public:
 MagicDictionary() { node = new Trie(); }

 void buildDict(vector<string> dictionary) {
     for (auto& w : dictionary) {
         add(w);
     }
  }

  bool search(string s) { 
   
    for (int j = 0; j < s.size(); j++) {
        for (int i = 0; i < N;i++) {
            char ch  = 'a' + i;
            char sj = s[j];
            if (ch != s[j]) {
                s[j] = ch;
                // cout << s << endl;
                if (search_word(s)) return 1;
                s[j] = sj;
            } 
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
    MagicDictionary so;
    vector<string> dict;
    string s;
    int r;
    dict = {"hello", "leetcode"};
    so.buildDict(dict);
    {
      s = "hello";
      r = so.search(s);
      cout << "str:" << s << " :" << r << endl;
        }
        {
            s = "hhllo";
          r = so.search(s);
          cout << "str:" << s << " :" << r << endl;
        }
        {
             s = "hell";
          r = so.search(s);
          cout << "str:" << s << " :" << r << endl;
        }
    return 0;
}