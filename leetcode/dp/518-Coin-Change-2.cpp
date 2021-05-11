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
    int r = 0;
    int change(int amount, vector<int>& coins) {
        return dyp(coins, amount);
        vector<int> path;
        r = 0;
        return dfs(coins, amount, 0, path);
    }
    int dyp(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (auto c : coins) {
            for (int i = 1; i <= amount; ++i) {
                // for (auto c : coins) { this kind loop will add twice,for
                // example,create 7,when amount=2,coins=5 will add one way ,but
                // still added when amount=2,coins=5,that is to say, 2+5 and 5+2
                // are same way,another example ,3 = 1+1+1 = 2+1=1+2 duplicate
                if (i - c >= 0) {
                    dp[i] += dp[i - c];
                }
            }
        }
        return dp[amount];
    }

    // 0 表示无法找零
    int dfs(vector<int>& coins, int amount, int i, vector<int>& path) {
        if (amount == 0) {
            r++;
            printvector(path);
            return 1;
        }
        int n = coins.size();
        if (i >= n || amount < 0)
            return 0;
        path.push_back(coins[i]);
        int x = dfs(coins, amount - coins[i], i, path);
        path.pop_back();
        int y = dfs(coins, amount, i + 1, path);
        return x + y;
    }
};
int main() {
    Solution so;
    vector<int> coins;
    int amount, r;
    {
        coins = {1, 2, 5};
        amount = 5;
        r = so.change(amount, coins);
        cout << r << endl;
    }

    {
        coins = {3, 5, 7, 8, 9, 10, 11};
        amount = 500;
        r = so.change(amount, coins);
        cout << r << endl;
    }

    return 0;
}