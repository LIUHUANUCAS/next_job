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
    vector<string> res;
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> result;
        res.clear();
        string s("1");
        for (int i = 1; i < 10; i++) {
            s[0] = i + '0';
            dfs(n, k, i, s);
        }
        for (auto s : res) {
            if (!s.empty() && s[0] != '0') {
                int x = atoi(s.c_str());
                result.push_back(x);
            }
        }
        // sort(result.begin(), result.end());
        return result;
    }
    int dfs(int n, int k, int c, string& s) {
        int size = s.size();
        if (n == size) {
            // cout << s << endl;
            res.push_back(s);
            return 1;
        }

        int r = 0;
        int x = c + k, y = c - k;
        if (x == y && x >= 0 && x < 10) {
            s.push_back(x + '0');
            r += dfs(n, k, x, s);
            s.pop_back();
            return r;
        }
        if (y >= 0) {
            s.push_back(y + '0');
            r += dfs(n, k, y, s);
            s.pop_back();
        }
        if (x < 10) {
            s.push_back(x + '0');
            r += dfs(n, k, x, s);
            s.pop_back();
        }
        return r;
    }
};
int main() {
    Solution so;
    vector<int> r;
    int k, n;
    {
        n = 3, k = 7;
        r = so.numsSameConsecDiff(n, k);
        printvector(r);
    }

    {
        n = 2, k = 1;
        r = so.numsSameConsecDiff(n, k);
        printvector(r);
    }
    {
        n = 2, k = 0;
        r = so.numsSameConsecDiff(n, k);
        printvector(r);
    }
    {
        n = 2, k = 2;
        r = so.numsSameConsecDiff(n, k);
        printvector(r);
    }
    {
        n = 1, k = 0;
        r = so.numsSameConsecDiff(n, k);
        printvector(r);
    }
    return 0;
}