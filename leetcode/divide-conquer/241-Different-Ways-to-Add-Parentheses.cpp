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
    vector<int> diffWaysToCompute(string exp) {
        if (exp.empty())
            return {};
        // cout << exp << endl;
        return dfs(exp, 0, exp.size() - 1);
    }

    vector<int> dfs(string& exp, int lo, int hi) {
        if (lo > hi)
            return {};

        vector<int> res;
        for (int i = lo; i <= hi; i++) {
            if (ismul(exp[i])) {
                vector<int> L = dfs(exp, lo, i - 1);
                vector<int> R = dfs(exp, i + 1, hi);
                dup(res, L, R, exp[i]);
            }
        }
        if (res.empty()) {
            string t(exp.begin() + lo, exp.begin() + hi + 1);
            int c = atoi(t.c_str());
            res.push_back(c);
        }

        return res;
    }
    void dup(vector<int>& res, vector<int>& L, vector<int>& R, char ch) {
        if (L.empty()) {
            for (auto e : R) {
                res.push_back(e);
            }
        }
        if (R.empty()) {
            for (auto e : L) {
                res.push_back(e);
            }
        }
        auto sp = ch;
        for (auto e : L) {
            for (auto r : R) {
                int c = 0;
                switch (sp) {
                    case '+':
                        c = e + r;
                        break;
                    case '-':
                        c = e - r;
                        break;
                    case '*':
                        c = e * r;
                        break;
                }
                res.push_back(c);
            }
        }
    }
    int ismul(char ch) { return ch == '+' || ch == '-' || ch == '*'; }
};
int main() {
    Solution so;
    string s;
    {
        s = "2-1-1";
        auto r = so.diffWaysToCompute(s);
        printvector(r);
    }

    {
        s = "2*3-4*5";
        auto r = so.diffWaysToCompute(s);
        printvector(r);
    }
    return 0;
}