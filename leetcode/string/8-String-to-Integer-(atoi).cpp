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
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        int r = 0;
        while (i < n && s[i] == ' ')
            i++;
        if (i >= n || !valid_char(s[i]))
            return r;
        int pos_flag = 1;
        if (s[i] == '-') {
            pos_flag = 0;
            i++;
        } else if (s[i] == '+') {
            pos_flag = 1;
            i++;
        }
        // printf("pos:%d\n", pos_flag);
        while (i < n && isdigit(s[i])) {
            int num = s[i] - '0';
            // printf("%d,\n", num);
            if (pos_flag) {
                int y = INT_MAX / 10;
                int x = INT_MAX % 10;
                if (r > y) {
                    return INT_MAX;
                } else if (r == y && num >= x) {
                    return INT_MAX;
                }
            } else {
                int y = INT_MIN / 10;
                int x = INT_MIN % 10;  // -8
                int c = -num;
                if (r < y) {
                    return INT_MIN;
                } else if (r == y && c <= x) {
                    return INT_MIN;
                }
            }
            r *= 10;
            if (pos_flag) {
                r += num;
            } else {
                r -= num;
            }
            // cout << "r:" << r << endl;
            i++;
        }
        return r;
    }
    int valid_char(char ch) { return ch == '-' || ch == '+' || isdigit(ch); }
    int isdigit(char ch) { return ch >= '0' && ch <= '9'; }
};
int main() {
    Solution so;
    string s;
    // {
    //     s = "23";
    //     auto r = so.myAtoi(s);
    //     cout << r << endl;
    // }
    // {
    //     s = "-2147483647";
    //     auto r = so.myAtoi(s);
    //     cout << r << endl;
    // }
    // {
    //     s = "-1";
    //     auto r = so.myAtoi(s);
    //     cout << r << endl;
    // }
    {
        s = "+1";
        auto r = so.myAtoi(s);
        cout << r << endl;
    }
    return 0;
}