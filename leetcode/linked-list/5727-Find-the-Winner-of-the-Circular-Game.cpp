#include <cstdio>
#include <iostream>
#include <map>
#include <random>
#include <stack>
#include <unordered_map>
#include <vector>
#include "../data_type.h"

using namespace std;
class Solution {
   public:
    int findTheWinner(int n, int k) {
        vector<int> dp(n, 1);
        int start = 0;
        int size = n;
        while (size != 1) {
            int c = 0;
            for (int i = start;; i++, i %= n) {
                if (dp[i]) {
                    c++;
                    if (c == k) {
                        dp[i] = 0;
                        start = (i + 1) % n;
                        break;
                    }
                }
            }
            size--;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i]) {
                res = i;
                break;
            }
        }
        return res + 1;
    }
};
int main() {
    Solution so;
    int n, k;
    {
        n = 5, k = 2;
        auto r = so.findTheWinner(n, k);
        cout << r << endl;
    }
    {
        n = 6, k = 5;
        auto r = so.findTheWinner(n, k);
        cout << r << endl;
    }
    {
        n = 500, k = 34;
        auto r = so.findTheWinner(n, k);
        cout << r << endl;
    }
    return 0;
}