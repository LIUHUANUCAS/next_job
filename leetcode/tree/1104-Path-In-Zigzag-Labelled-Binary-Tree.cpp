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
    vector<int> pathInZigZagTree(int n) {
        auto d = deep(n);
        vector<int> res(d);
        for (; n >= 1; n /= 2, d--) {
            res[d - 1] = n;
            n = (1 << d) - 1 - n + (1 << (d - 1));
        }
        return res;
    }
    int deep(int n) {
        int level = 0;
        while ((1 << level) <= n) {
            level++;
        }
        return level;
    }
};
int main() {
    Solution so;
    vector<int> res;
    int n;
    {
        n = 14;
        res = so.pathInZigZagTree(n);
        printvector<int>(res);
    }
    {
        n = 26;
        res = so.pathInZigZagTree(n);
        printvector<int>(res);
    }
    return 0;
}