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
    string simplifyPath(string path) {
        vector<string> st;
        if (path.empty())
            return path;
        int n = path.size();
        vector<string> sp = split(path);
        for (auto e : sp) {
            if (e == "..") {
                if (!st.empty()) {
                    st.pop_back();
                } else {
                    // do nothing
                }
            } else if (e == ".") {
                continue;
            } else {
                st.push_back(e);
            }
        }
        return construct(st);
    }

    vector<string> split(string& s) {
        int n = s.size();
        vector<string> res;
        int pre = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '/') {
                // if (i != 0) {
                string t(s.begin() + pre, s.begin() + i);
                if (!t.empty())
                    res.push_back(t);
                pre = i + 1;
                // } else {
                //     pre = i + 1;
                // }
            }
        }
        if (pre < n) {
            string t(s.begin() + pre, s.end());
            res.push_back(t);
        }
        return res;
    }
    string construct(vector<string>& res) {
        stringstream sst;
        for (auto it = res.begin(); it != res.end(); ++it) {
            sst << "/" << *it;
        }
        string s(sst.str());
        if (s.empty())
            return "/";
        return s;
    }
};
int main() {
    Solution so;
    string s;
    {
        s = "/home/";
        auto r = so.simplifyPath(s);
        cout << r << endl;
    }

    {
        s = "/../";
        auto r = so.simplifyPath(s);
        cout << r << endl;
    }

    {
        s = "/home//foo/";
        auto r = so.simplifyPath(s);
        cout << r << endl;
    }
    {
        s = "/a/./b/../../c/";
        auto r = so.simplifyPath(s);
        cout << r << endl;
    }
    {
        s = "/a/./b/../../c/";
        cout << s << endl;
        auto r = so.split(s);
        printvector<string>(r);
    }
    {
        s = "/../a/b/c/../d";
        cout << s << endl;
        auto r = so.simplifyPath(s);
        auto res = so.split(s);
        printvector<string>(res);
        cout << r << endl;
    }
    return 0;
}