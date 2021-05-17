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
class Solution {
   public:
    string countOfAtoms(string s) {
        int n = s.size();
        stack<char> st;
        for (int i = 0; i < n;) {
            // if (s[i] == '(') {
            //     st.push('(');
            //     i++;
            // } else
            if (s[i] == ')') {
                int c = 0;
                int j = getnumber(s, i + 1, c);
                int next = j;
                string at;
                while (!st.empty() && st.top() != '(') {
                    at.push_back(st.top());
                    st.pop();
                }
                if (!at.empty()) {
                    st.pop();
                }
                reverse(at.begin(), at.end());  // one atom
                auto m = atom(at);
                mult(m, c);
                auto tmpstr = map2string(m);
                for (auto e : tmpstr) {
                    st.push(e);
                }
                i = next;
            } else {  // s[i] == '(' or  character
                st.push(s[i]);
                i++;
            }
        }
        return stack2string(st);
    }
    string stack2string(stack<char>& st) {
        string s;
        while (!st.empty()) {
            s.push_back(st.top());
            st.pop();
        }
        reverse(s.begin(), s.end());
        auto m = atom(s);
        return map2string(m);
    }
    int getnumber(string& s, int j, int& c) {
        int n = s.size();
        for (; j < n && isdigit(s[j]); j++) {  /// get number
            c *= 10;
            c += s[j] - '0';
        }
        if (c == 0) {  // if c==0 then should be 1
            c = 1;
        }
        return j;
    }
    unordered_map<string, int> atom(string s) {
        unordered_map<string, int> m;
        if (s.empty()) {
            return m;
        }
        int n = s.size(), j;
        for (int i = 0; i < n && upper(s[i]); i = j) {
            for (j = i + 1; j < n && !upper(s[j]) && !isdigit(s[j]); j++) {
            }
            string str(s.begin() + i, s.begin() + j);
            int c = 0;
            for (; j < n && isdigit(s[j]); j++) {  /// get number
                c *= 10;
                c += s[j] - '0';
            }
            c = (c > 1) ? c : 1;
            m[str] += c;  /// may be duplicate case ONO2->O:3 N:1
        }
        return m;
    }
    void mult(unordered_map<string, int>& m, int k) {
        for (auto& e : m) {
            e.second *= k;
        }
    }
    void printmap(unordered_map<string, int>& m) {
        for (auto e : m) {
            cout << e.first << ":" << e.second << " ";
        }
        cout << endl;
    }
    string map2string(unordered_map<string, int>& m) {
        if (m.empty())
            return "";
        stringstream sst;
        vector<string> res;
        for (auto e : m) {
            res.push_back(e.first);
        }
        sort(res.begin(), res.end());
        for (auto s : res) {
            sst << s << (m[s] > 1 ? to_string(m[s]) : "");
        }
        return sst.str();
    }
    int upper(char c) { return c >= 'A' && c <= 'Z'; }
};
int main() {
    Solution so;
    string s;
    {
        s = "Mg(H2O)N";
        s = so.countOfAtoms(s);
        cout << s << endl;
    }
    {
        s = "K4(ON(SO3)2)2";
        s = so.countOfAtoms(s);
        cout << s << endl;
    }
    {
        s = "Be32";
        s = so.countOfAtoms(s);
        cout << s << endl;
    }
    {
        s = "Mg(OH)2";
        s = so.countOfAtoms(s);
        cout << s << endl;
    }
    return 0;
}