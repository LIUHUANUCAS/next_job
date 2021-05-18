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
    vector<string> generateParenthesis(int n) {
        res.clear();
        dfs(n, 0, 0, "");
        return res;
    }
    // left '('个数，right:')'个数
    void dfs(int n, int left, int right, string path) {
        if (right > left || left > n || right > n) {
            return;
        }
        if (left == right && left == n) {
            // cout << path << endl;
            res.push_back(path);
            return;
        }

        dfs(n, left + 1, right, path + "(");
        dfs(n, left, right + 1, path + ")");
    }
};
int main() {
    Solution so;
    vector<string> r;
    int n;
    {
        n = 3;
        r = so.generateParenthesis(n);
        printvector(r);
    }
    {
        n = 8;
        r = so.generateParenthesis(n);
        printvector(r);
    }
    return 0;
}