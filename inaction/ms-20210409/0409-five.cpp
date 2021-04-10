
/**
atoi()实现
1.空格，加号减号
2.数字结束后，之后字符省略。任意在字符
string -> int [INT_MIN,INT_MAX]
*/
#include <iostream>
#include <vector>
using namespace std;
struct Solution {
    int isdigit(char ch) { return ch >= '0' && ch <= '9'; }
    int stringtoint(string s) {
        int n = s.size();
        int i = 0;
        int res = 0;
        //去除空格
        while (i < n && s[i] == ' ')
            i++;
        // 输入非法，全是空格，第一个非空格，非数字，非符号
        if (i == n || ((s[i] != '-' && s[i] != '+') && !isdigit(s[i]))) {
            return res;
        }
        int signflag = 0;
        if (s[i] == '-') {  // 负数
            signflag = 1;
            i++;
        }

        if (s[i] == '+') {  // 负数
            signflag = 0;
            i++;
        }

        while (i < n && isdigit(s[i])) {  // 数字解析
            int num = s[i] - '0';
            if (signflag) {  // 负数
                int y = INT_MIN / 10;
                int x = INT_MIN % 10;  // 正数
                if (res < y) {         // res*10 小于y
                    return INT_MIN;
                } else if (res == y && num >= x) {  // res*10 - num <= INT_MIN
                    return INT_MIN;
                }
            } else {                   // 正数
                int y = INT_MAX / 10;  // [yx]
                int x = INT_MAX % 10;
                if (res > y) {  // res*10 超过INT_MAX
                    return INT_MAX;
                } else if (res == y && num >= x) {  // res*10 + num >= INT_MAX
                    return INT_MAX;
                }
            }
            res *= 10;
            if (signflag) {
                res -= s[i] - '0';
            } else {
                res += s[i] - '0';
            }
            i++;
        }
        return res;
    }
};
int main() {
    string s;
    Solution so;
    {
        s = "123";
        auto r = so.stringtoint(s);
        cout << r << endl;
    }

    {
        s = to_string(INT_MAX);
        auto r = so.stringtoint(s);
        cout << r << endl;
    }

    {
        s = to_string(INT_MIN);
        auto r = so.stringtoint(s);
        cout << r << endl;
    }

    {
        s = string("2147483748");
        auto r = so.stringtoint(s);
        cout << r << endl;
    }

    {
        s = string("-2147483659");
        auto r = so.stringtoint(s);
        cout << r << endl;
    }

    {
        s = string("123e");
        auto r = so.stringtoint(s);
        cout << r << endl;
    }
}
