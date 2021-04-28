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
    bool isSubsequence(string s, string t) {
        return dfs(s,0,t,0);
    }
    int dfs(string &s, int i, string &t, int j) {
        int m = s.size(), n = t.size();
        if (i == m) return 1;
        if (i > m || j >=  n) return 0;
        if (s[i] == t[j]) {
            return dfs(s, i + 1, t, j + 1);
        }
        return dfs(s,i,t,j+1);
    }
};
int main() {
    Solution so;
    string s,t;
    {
        s = "abc", t = "ahbgdc";
        auto r = so.isSubsequence(s,t);
        cout << r << endl;
    }
     {
        s = "axc", t = "ahbgdc";
        auto r = so.isSubsequence(s,t);
        cout << r << endl;
    }
    return 0;
}