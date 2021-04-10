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
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        vector<string> onepath;
        dfs(s, 0, onepath);
        return res;
    }
    int is_palindrome(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return 0;
            i++, j--;
        }
        return 1;
    }
    void dfs(string& s, int start, vector<string>& onepath) {
        int n = s.size();
        if (start >= n) {
            res.push_back(onepath);
            return;
        }

        for (int i = start; i < n; i++) {
            if (is_palindrome(s, start, i)) {
                onepath.push_back(s.substr(start, i - start + 1));
                dfs(s, i + 1, onepath);
                onepath.pop_back();
            }
        }
    }
};
int main() {
    Solution so;
    string s;
    {
        s = "abb";
        auto r = so.partition(s);
        printvector(r);
    }
    return 0;
}