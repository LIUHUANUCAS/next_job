#include <cstdio>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_map>
#include <vector>

#include "../data_type.h"

using namespace std;
/***
    i:01234567
    s:bahbgdca
    a:[1,7]
    b:[0,3]
    c:[6]
    d:[5]
    h:[2]
    g:[4]
    t=abc
    pre=0
    搜索：
    a,最靠前的idx=1
    b,最靠前的索引，且比pre 大的是3
    c,最靠前且比pre大的索引是6,最后找到
*/
class Solution {
   public:
    const int N = 26;
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> d(N, vector<int>());
        int n = s.size(), c = 0;
        for (int i = 0; i < n; i++) {
            auto j = s[i] - 'a';
            d[j].push_back(i);
        }
        for (auto& w : words) {
            if (w.size() <= s.size())
                c += match(w, d);
        }
        return c;
    }
    int match(string& w, vector<vector<int>>& d) {
        int pre = 0;
        for (auto ch : w) {
            int i = ch - 'a';
            auto it = lower_bound(d[i].begin(), d[i].end(), pre);
            if (d[i].empty() || it == d[i].end()) {
                return 0;
            }
            pre = *it + 1;
        }
        return 1;
    }
    int numMatchingSubseq2(string s, vector<string>& words) {
        int c = 0;
        for (auto& w : words) {
            c += dfs(w, 0, s, 0);
        }
        return c;
    }

    int dfs(string& s, int i, string& t, int j) {
        int m = s.size(), n = t.size();
        if (i == m)
            return 1;
        if (i > m || j >= n)
            return 0;
        if (s[i] == t[j]) {
            return dfs(s, i + 1, t, j + 1);
        }
        return dfs(s, i, t, j + 1);
    }
};
int main() {
    Solution so;
    string s;
    vector<string> words;
    {
        s = "abcde";
        words = {"a", "bb", "acd", "ace"};
        auto r = so.numMatchingSubseq(s, words);
        cout << r << endl;
    }
    return 0;
}