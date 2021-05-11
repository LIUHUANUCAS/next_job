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
    // int r = INT_MAX;
    // unordered_map<int, int> cache;
    int coinChange(vector<int>& coins, int amount) {
        vector<int> path;
        // return dfs(coins, amount, 0, 0, path);
        return dyp2(coins, amount);
    }
    int dyp2(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (auto c : coins) {
                if (i - c >= 0) {
                    dp[i] = min(dp[i], dp[i - c] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
    int dyp(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (auto c : coins) {
            if (c <= amount)
                dp[c] = 1;
        }
        for (int i = 1; i <= amount; i++) {
            for (auto c : coins) {
                if (i - c >= 0 && dp[i - c] >= 0) {
                    if (dp[i] < 0) {
                        dp[i] = dp[i - c] + 1;
                    } else {
                        dp[i] = min(dp[i], dp[i - c] + 1);
                    }
                }
            }
        }
        return dp[amount];
    }
    // -1 表示无法找零
    int dfs(vector<int>& coins,
            int amount,
            int i,
            int count,
            vector<int>& path) {
        if (amount == 0) {
            return count;
        }
        int n = coins.size();
        if (i >= n || amount < 0)
            return -1;
        path.push_back(coins[i]);
        int x = dfs(coins, amount - coins[i], i, count + 1, path);
        path.pop_back();
        int y = dfs(coins, amount, i + 1, count, path);
        if (x > 0 || y > 0) {  // succeed  coin change
            int r = x > 0 ? x : y;
            if (y > 0) {
                r = min(r, y);
            }
            return r;
        }
        return -1;
    }
};
int main() {
    Solution so;
    vector<int> coins;
    int amount, r;
    {
        coins = {1, 2, 5};
        amount = 11;
        r = so.coinChange(coins, amount);
        cout << r << endl;
    }
    {
        coins = {2};
        amount = 3;
        r = so.coinChange(coins, amount);
        cout << r << endl;
    }
    {
        coins = {1};
        amount = 0;
        r = so.coinChange(coins, amount);
        cout << r << endl;
    }
    {
        coins = {1};
        amount = 1;
        r = so.coinChange(coins, amount);
        cout << r << endl;
    }
    {
        coins = {1};
        amount = 2;
        r = so.coinChange(coins, amount);
        cout << r << endl;
    }

    {
        coins = {186, 419, 83, 408};
        amount = 6249;
        r = so.coinChange(coins, amount);
        cout << r << endl;
    }

    return 0;
}