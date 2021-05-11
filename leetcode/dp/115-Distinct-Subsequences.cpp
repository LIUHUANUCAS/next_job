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
    unordered_map<string, int> cache;
    int numDistinct(string s, string t) {
        cache.clear();
        return dfs(s, 0, t, 0);
    }
    int dfs(string& s, int i, string& t, int j) {
        if (j == t.size()) {
            return 1;
        }
        if (i >= s.size() || j > t.size()) {
            return 0;
        }
        auto key = getkey(i, j);
        if (cache.find(key) != cache.end())
            return cache[key];
        int r = 0;
        if (s[i] == t[j]) {
            r += dfs(s, i + 1, t, j + 1);
        }
        r += dfs(s, i + 1, t, j);
        cache[key] = r;
        return r;
    }
    string getkey(int i, int j) {
        stringstream sst;
        sst << i << "_" << j;
        return sst.str();
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