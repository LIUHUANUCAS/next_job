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
    int getKth(int lo, int hi, int k) {
        int n = hi - lo + 1;
        vector<int> count(n, 0);
        vector<int> A(n, 0);
        for (int i = lo; i <= hi; i++) {
            count[i - lo] = dfs(i);
            A[i - lo] = i;
        }

        auto cmp = [&](const int a, const int b) {
            int x = count[a - lo];
            int y = count[b - lo];
            return x < y ? 1 : (x == y ? a < b : 0);
        };
        sort(A.begin(), A.end(), cmp);
        return A[k - 1];
    }
    unordered_map<int, int> cache;
    int dfs(int n) {
        if (n == 1) {
            return 0;
        }
        if (cache.find(n) != cache.end()) {
            return cache[n];
        }
        int x = n;
        if (x & 0x01) {
            x = 3 * x + 1;
        } else {
            x /= 2;
        }
        cache[n] = 1 + dfs(x);
        return cache[n];
    }
};
int main() {
    Solution so;
    int lo, hi, k;
    {
        lo = 12, hi = 15, k = 2;
        auto r = so.getKth(lo, hi, k);
        cout << r << endl;
    }
    {
        lo = 12, hi = 1000, k = 405;
        auto r = so.getKth(lo, hi, k);
        cout << r << endl;  // 952
    }
    return 0;
}