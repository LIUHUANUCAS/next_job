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
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return 0;
        return dfs(s1, 0, s2, 0, s3, 0);
    }
    int dfs(string& s1, int i, string& s2, int j, string& s3, int k) {
        if (i == s1.size() && j == s2.size() && k == s3.size())
            return 1;
        bool r = 0;
        if (i < s1.size() && s1[i] == s3[k]) {
            r |= dfs(s1, i + 1, s2, j, s3, k + 1);
        }
        if (j < s2.size() && s2[j] == s3[k]) {
            r |= dfs(s1, i, s2, j + 1, s3, k + 1);
        }
        return r;
    }
};
int main() {
    Solution so;
    string s1, s2, s3;
    {
        s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
        auto r = so.isInterleave(s1, s2, s3);
        cout << r << endl;
    }
    {
        s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc";
        auto r = so.isInterleave(s1, s2, s3);
        cout << r << endl;
    }
    return 0;
}