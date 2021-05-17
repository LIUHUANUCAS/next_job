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
    vector<int> A;
    int res;
    int countNumbersWithUniqueDigits(int n) {
        res = 0;
        for (int i = 0; i < 10; i++) {
            A.push_back(i + 1);
        }
        //分别计算1位数，2位数，3位数等等里面不重复的数字
        for (int i = 0; i <= n; ++i)
            dfs(i, 0);
        return res;
    }
    // dfs  n:位数，cur_count当前位数
    void dfs(int n, int cur_count) {
        if (cur_count == n) {
            res++;
            return;
        }
        for (int i = 0; i <= 9; i++) {
            if (cur_count == 0 && i == 0) {
                continue;
            }
            if (A[i] > 0) {
                int t = A[i];
                A[i] = -1;
                dfs(n, cur_count + 1);
                A[i] = t;
            }
        }
    }
};
int main() {
    Solution so;
    int n, r;
    {
        n = 2;
        r = so.countNumbersWithUniqueDigits(n);
        cout << r << endl;
    }
    {
        n = 8;
        r = so.countNumbersWithUniqueDigits(n);
        cout << r << endl;
    }
    return 0;
}