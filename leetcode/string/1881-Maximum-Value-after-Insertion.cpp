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
    string maxValue(string n, int x) {
        // n[i - 1] + x + n[i]
        int size = n.size(), j;
        string s(size + 1, '0');
        int i = getpos(n, x);
        for (j = 0; j < i; ++j) {
            s[j] = n[j];
        }
        s[j] = x + '0';
        for (; j < size; j++) {
            s[j + 1] = n[j];
        }
        return s;
    }
    int getpos(string n, int x) {
        // neg from left to right first greater than x
        // positive from left to right find first less than x
        int neg = n[0] == '-';
        int size = n.size(), i = neg;
        function<int(int, int)> f = [neg](int a, int b) {
            return neg ? a < b : a > b;
        };

        for (i = neg; i < size; ++i) {
            int y = n[i] - '0';
            if (f(x, y)) {
                return i;
            }
        }
        return i;
        // if (!neg) {
        //     for (i = 0; i < size; ++i) {
        //         int y = n[i] - '0';
        //         if (x > y) {
        //             break;
        //         }
        //     }
        //     return i;
        // }
        // for (i = 1; i < size; ++i) {
        //     int y = n[i] - '0';
        //     if (x < y)
        //         return i;
        // }
        // return i;
    }
};
int main() {
    Solution so;
    string n, s;
    int x;
    {
        n = "99", x = 9;
        s = so.maxValue(n, x);
        cout << s << endl;
    }
    {
        n = "32", x = 1;
        s = so.maxValue(n, x);
        cout << s << endl;
    }
    {
        n = "332", x = 4;
        s = so.maxValue(n, x);
        cout << s << endl;
    }

    {
        n = "-13", x = 2;
        s = so.maxValue(n, x);
        cout << s << endl;
    }
    {
        n = "-23", x = 1;
        s = so.maxValue(n, x);
        cout << s << endl;
    }

    {
        n = "-132", x = 3;
        s = so.maxValue(n, x);
        cout << s << endl;
    }
    {
        n = "-3451", x = 1;
        s = so.maxValue(n, x);
        cout << s << endl;
    }
    {
        n = "-787", x = 8;
        s = so.maxValue(n, x);
        cout << s << endl;
    }
    {
        n = "469975787943862651173569913153377";
        x = 3;
        s = so.maxValue(n, x);
        cout << s << endl;
    }

    return 0;
}