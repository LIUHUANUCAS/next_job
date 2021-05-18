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
    vector<int> cache;
    int numTrees(int n) {
        cache = vector<int>(n + 1, -1);
        return dfs(n);
    }
    int dfs(int n) {
        if (n <= 1)
            return 1;
        int c = 0;
        if (cache[n] > 0)
            return cache[n];
        for (int i = 0; i < n; i++) {
            // root i dfs(i) is left ,dfs(n-i-1) is right
            c += dfs(i) * dfs(n - i - 1);
        }
        return cache[n] = c;
    }
};
int main() {
    Solution so;
    int n, r;
    {
        n = 3;
        r = so.numTrees(n);
        cout << r << endl;
    }
    {
        n = 5;
        r = so.numTrees(n);
        cout << r << endl;
    }
    {
        n = 19;
        r = so.numTrees(n);
        cout << r << endl;
    }
    return 0;
}