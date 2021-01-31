#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>
#include "../data_type.h"

using namespace std;
class Solution {
   public:
    int maxPower(string s) {
        int len = 0;
        char pre = ' ';
        int c = 0;
        for (auto e : s) {
            if (e == pre) {
                c++;
            } else {
                c = 1;
                pre = e;
            }
            len = max(len, c);
        }
        return len;
    }
};
int main() {
    Solution so;
    string s;
    s = "abbcccddddeeeeedcba";
    auto r = so.maxPower(s);
    cout << r << endl;
    return 0;
}