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
    int numDistinct(string s, string t) { return dfs(s, 0, t, 0); }
    int dfs(string& s, int i, string& t, int j) {
        if (j == t.size()) {
            return 1;
        }
        if (i >= s.size() || j > t.size()) {
            return 0;
        }
        int r = 0;
        if (s[i] == t[j]) {
            r += dfs(s, i + 1, t, j + 1);
        }
        r += dfs(s, i + 1, t, j);
        return r;
    }
};
int main() {
    Solution so;
    string s, t;
    int r;
    {
        s = "rabbbit", t = "rabbit";
        r = so.numDistinct(s, t);
        cout << r << endl;
    }
    {
        s = "babgbag", t = "bag";
        r = so.numDistinct(s, t);
        cout << r << endl;
    }
    return 0;
}