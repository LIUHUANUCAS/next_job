#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <random>
#include <stack>
#include <unordered_map>
#include <vector>

#include "../data_type.h"

using namespace std;
class Solution {
   public:
    map<char, int> m;
    vector<char> array = {'a', 'e', 'i', 'o', 'u'};
    int end = 4;
    int N = 5;
    int longestBeautifulSubstring(string A) {
        stack<pair<char, int>> st;
        for (int i = 0; i < array.size(); i++) {
            m[array[i]] = i;
        }
        int len = 0, n = A.size();
        int size = 0;
        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                if (A[i] == 'a') {
                    st.push({'a', 1});
                    size = 1;
                }
            } else {
                auto x = st.top();
                if (A[i] == x.first) {
                    st.pop();
                    x.second += 1;  // update count
                    st.push(x);
                    size += 1;
                } else if (m[A[i]] == m[x.first] + 1) {
                    st.push({A[i], 1});
                    size += 1;
                } else {
                    while (!st.empty())
                        st.pop();
                    size = 0;
                    if (A[i] == 'a') {
                        st.push({'a', 1});
                        size = 1;
                    }
                }
            }
            if (st.size() == N) {
                len = max(len, size);
            }
            // printf("size:%c %d %ld\n", A[i], size, st.size());
        }
        return len;
    }
    int longestBeautifulSubstring2(string word) {
        int len = 0;
        int n = word.size();
        int l = 0, r = 0, pre = -1;
        for (int i = 0; i < array.size(); i++) {
            m[array[i]] = i;
        }
        int count[5] = {0};
        int init = 0;
        for (r = 0; r < n; r++) {
            char ch = word[r];
            auto idx = m[ch];
            // printf("%d %d %d\n", idx, pre, init);
            if (idx == 0) {
                if (init == 0) {  // just init
                    init = 1;     // init with 1
                    pre++;        // pre should be 0
                    l = r;
                } else {
                    if (idx != pre) {
                        init = 0;
                        pre = -1;
                    }
                }
            } else {  // not start
                if (idx == pre) {
                    if (idx == end) {
                        len = max(len, r - l + 1);
                    }
                } else if (idx == pre + 1) {
                    if (idx == end) {
                        len = max(len, r - l + 1);
                    }
                    pre = idx;
                } else {
                    init = 0;
                    pre = -1;
                }
            }
        }
        return len;
    }
};
int main() {
    Solution so;
    string w;
    {
        w = "aeiaaioaaaaeiiiiouuuooaauuaeiu";
        auto r = so.longestBeautifulSubstring(w);
        cout << r << endl;
    }

    {
        w = "aeeeiiiioooauuuaeiou";
        auto r = so.longestBeautifulSubstring(w);
        cout << r << endl;
    }

    {
        w = "aeiou";
        auto r = so.longestBeautifulSubstring(w);
        cout << r << endl;
    }
    {
        w = "aeioaeiou";
        auto r = so.longestBeautifulSubstring(w);
        cout << r << endl;
    }
    return 0;
}