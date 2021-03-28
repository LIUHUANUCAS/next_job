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
    string evaluate(string s, vector<vector<string>>& k) {
        unordered_map<string, string> m;
        for (auto e : k) {
            m[e[0]] = e[1];
        }
        string res;
        int n = s.size();
        int c = 0;
        for (int i = 0; i < n;) {
            if (s[i] == '(') {
                int j = i + 1;
                string str;
                while (j < n && s[j] != ')') {
                    str.push_back(s[j]);
                    j++;
                }
                if (m.find(str) != m.end()) {
                    res += m[str];
                } else {
                    res.push_back('?');
                }
                i = j + 1;
            } else {
                res.push_back(s[i]);
                i++;
            }
        }
        return res;
    }
};
int main() {
    Solution so;
    vector<vector<string>> k;
    string s;
    {
        k = {{"name", "bob"}, {"age", "two"}};
        s = "(name)is(age)yearsold";
        auto r = so.evaluate(s, k);
        cout << r << endl;
    }
    {
        s = "hi(name)";
        k = {{"a", "b"}};
        auto r = so.evaluate(s, k);
        cout << r << endl;
    }
    {
        s = "(a)(a)(a)aaa";
        k = {{"a", "yes"}};
        auto r = so.evaluate(s, k);
        cout << r << endl;
    }
    {
        s = "(a)(b)";
        k = {{"a", "b"}, {"b", "a"}};
        auto r = so.evaluate(s, k);
        cout << r << endl;
    }
    return 0;
}