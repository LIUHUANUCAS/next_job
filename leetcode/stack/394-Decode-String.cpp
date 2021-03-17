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
        stack<string> num;
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
    // string dfs(string& s, int i, int& left) {
    //     if (i == s.size()) {
    //         return "";
    //     }
    //     if (s[i] == '[')
    //         left++;
    //     auto str = dfs(s, i + 1, left);

    // }
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
            cout << str;
        }
        cout << endl;
    }
};
int main() {
    Solution so;
    stack<char> st;
    string s("3[abc");
    string s2("3[abc]");
    for (auto e : s)
        st.push(e);

    so.getstring(st);
    {
        s2 = "3[a]2[bc]";
        cout << so.decodeString(s2) << endl;
    }
    {
        s2 = "3[a2[c]]";
        cout << so.decodeString(s2) << endl;
    }
    {
        s2 = "2[abc]3[cd]ef";
        cout << so.decodeString(s2) << endl;
    }
    {
        s2 = "abc3[cd]xyz";
        cout << so.decodeString(s2) << endl;
    }
    return 0;
}