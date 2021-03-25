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
    int numDecodings(string s) {
        unordered_map<int, int> cache;
        int n = s.size();
        if (n == 0)
            return 0;
        return dfs(s, 0, cache);
    }
    int dfs(string& s, int i, unordered_map<int, int>& cache) {
        if (cache.find(i) != cache.end()) {
            return cache[i];
        }
        int n = s.size();
        if (i >= n)
            return 1;
        if (i == n - 1) {
            return s[i] >= '1' && s[i] <= '9';
        }
        if (s[i] == '0') {
            cache[i] = 0;
            return 0;
        }
        // i,i+1,i+2; ab
        int c = dfs(s, i + 1, cache);  // a>=1 && a <= 9 ,dfs(i+1);
        int val = (s[i] - '0') * 10 + s[i + 1] - '0';
        int d = 0;
        if (val >= 1 && val <= 26) {
            d = dfs(s, i + 2, cache);
        }
        cache[i] = c + d;
        return c + d;
    }
};
int main() {
    Solution so;
    string s;
    {
        s = "12";
        auto r = so.numDecodings(s);
        cout << r << endl;
    }
    {
        s = "226";
        auto r = so.numDecodings(s);
        cout << r << endl;
    }
    {
        s = "100";
        auto r = so.numDecodings(s);
        cout << r << endl;
    }

    {
        s = "2263";
        auto r = so.numDecodings(s);
        cout << r << endl;
    }
    {
        s = "06";
        auto r = so.numDecodings(s);
        cout << r << endl;
    }
    {
        s = "160";
        auto r = so.numDecodings(s);
        cout << r << endl;
    }
    {
        s = "123123121212312312121231231212123123121212312312121231231212";
        s = "1231231";
        auto r = so.numDecodings(s);
        cout << "result:" << r << endl;
    }
    return 0;
}