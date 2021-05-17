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
    bool isMatch(string s, string p) {
        return dfs2(s, p);
        // return dfs(s, 0, p, 0);
    }
    int dfs2(string s, string p) {
        if (p.empty())
            return s.empty();
        int first = !s.empty() && (s[0] == p[0] || p[0] == '.');
        if (p[1] == '*') {
            return dfs2(s, p.substr(2)) || (first && dfs2(s.substr(1), p));
        }
        return first && dfs2(s.substr(1), p.substr(1));
    }
    int dfs(string& s, int i, string& p, int j) {
        int m = s.size(), n = p.size();
        if (i == m && j == n)
            return 1;
        if (i == m || j == n)
            return 0;

        int first = (s[i] == p[j] || p[j] == '.');
        if (j < n - 1) {
            if (p[j + 1] == '*') {
                return dfs(s, i + 1, p, j) || dfs(s, i + 1, p, j + 2);
            } else {
                return first && dfs(s, i + 1, p, j + 1);
            }
        }
        if (j < n - 1) {  // j+1 < n
            if (p[j + 1] != '*') {
                if (p[j] == '.') {
                    return dfs(s, i + 1, p, j + 1);  // 匹配一个字符
                }
                // 当前匹配且递归匹配后续子串
                return s[i] == p[j] && dfs(s, i + 1, p, j + 1);
            } else {                // p[j+1] == '*'
                if (p[j] == '.') {  // .*
                                    // [ab,.*c], 匹配一个.或者多个点
                    return dfs(s, i, p, j + 2) ||     // 匹配0个.
                           dfs(s, i + 1, p, j + 2) || /*匹配一个点*/
                           dfs(s, i + 1, p, j);       /*匹配多个点*/
                } else {
                    if (s[i] == p[j]) {
                        // 匹配0次 或者先匹配一次
                        return dfs(s, i + 1, p, j + 2) || dfs(s, i + 1, p, j);
                    } else {
                        return dfs(s, i, p, j + 2);  //
                    }
                }
            }
        }
        if (j == n - 1) {
            return (s[i] == p[j] || p[j] == '.') && dfs(s, i + 1, p, j + 1);
        }

        return 0;
    }
};
int main() {
    Solution so;
    string s, p;
    int r;
    {
        s = "aa", p = "a";
        r = so.isMatch(s, p);
        cout << s << ":" << p << "=" << r << endl;
    }
    {
        s = "aa", p = "a*";
        r = so.isMatch(s, p);
        cout << s << ":" << p << "=" << r << endl;
    }
    {
        s = "ab", p = ".*";
        r = so.isMatch(s, p);
        cout << s << ":" << p << "=" << r << endl;
    }
    {
        s = "aab", p = "c*a*b";
        r = so.isMatch(s, p);
        cout << s << ":" << p << "=" << r << endl;
    }
    {
        s = "mississippi", p = "mis*is*p*.";
        r = so.isMatch(s, p);
        cout << s << ":" << p << "=" << r << endl;
    }
    {
        s = "missis", p = "mis*is*";
        r = so.isMatch(s, p);
        cout << s << ":" << p << "=" << r << endl;
    }
    {
        s = "mississippi", p = "mis*issi*p*.";
        r = so.isMatch(s, p);
        cout << s << ":" << p << "=" << r << endl;
    }
    {
        s = "ab", p = ".*c";
        r = so.isMatch(s, p);
        cout << s << ":" << p << "=" << r << endl;
    }
    {
        s = "ab", p = ".*a*b";
        r = so.isMatch(s, p);
        cout << s << ":" << p << "=" << r << endl;
    }
    {
        s = "ab", p = ".*a.*b";
        r = so.isMatch(s, p);
        cout << s << ":" << p << "=" << r << endl;
    }

    {
        s = "abc", p = ".*a.*";
        r = so.isMatch(s, p);
        cout << s << ":" << p << "=" << r << endl;
    }
    {
        s = "ab", p = ".*****b";
        r = so.isMatch(s, p);
        cout << s << ":" << p << "=" << r << endl;
    }
    return 0;
}

// {
//     if (s[i] == p[j]) {
//         return dfs(s, i + 1, p, j + 1);
//     }
//     if (p[j] == '.') {
//         return dfs(s, i + 1, p, j + 1);
//     }
//     if (j == 0 && p[j] == '*') {  // 这种情况题目条件说不存在
//         return dfs(s, i, p, j + 1);
//     }
//     if (j > 0 && p[j] == '*') {
//         if (p[j - 1] == '.')  // .*匹配任何字符串
//             return 1;
//         if (p[j - 1] == s[i]) {
//             return dfs(s, i + 1, p, j) || dfs(s, i + 1, p, j + 1);
//             // p[j - 1] == s[i] ,相等，重复0次或者1次
//         } else {
//             return dfs(s, i, p, j + 1);
//             // p[j-1] != s[i] *重复0次，向后移动
//         }
//     }
// }