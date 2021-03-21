#include <cstdio>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_map>
#include <vector>
#include "../data_type.h"

using namespace std;
class Solution {
   public:
    string decodeString(string s) {
        stack<char> st;
        int n = s.size();
        string str;
        for (int i = 0; i < n; i++) {
            auto c = s[i];
            if (c == '[' || isdigit(c) || c != ']') {
                st.push(c);
            } else {
                // c == ']'
                getstring(st);
            }
        }
        str = "";
        while (!st.empty()) {
            str.push_back(st.top());
            st.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
    void getstring(stack<char>& st) {
        string str("");
        while (!st.empty()) {
            auto x = st.top();
            if (x != '[') {
                str.push_back(x);
                st.pop();
            } else {
                st.pop();
                break;
            }
        }
        string s;
        while (!st.empty()) {
            auto x = st.top();
            if (isdigit(x)) {
                s.push_back(x);
                st.pop();
            } else {
                break;
            }
        }
        reverse(s.begin(), s.end());

        int c = 1;
        if (s.size() > 0)
            c = atoi(s.c_str());

        for (int i = 0; i < c; i++) {
            for (auto it = str.rbegin(); it != str.rend(); ++it) {
                st.push(*it);
            }
            // cout << str;
        }
        // cout << endl;
    }
};
int main() {
    Solution so;
    stack<char> st;
    // string s("3[abc");
    // string s2("3[abc]");
    // for (auto e : s)
    //     st.push(e);

    // so.getstring(st);
    vector<string> test;
    test = {"3[a]2[bc]", "3[a2[c]]", "2[abc]3[cd]ef", "abc3[cd]xy1[za]"};

    for (auto str : test) {
        cout << str << ":" << so.decodeString(str) << endl;
    }
    return 0;
}