#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>
// #include "../data_type.h"

using namespace std;
class Solution {
   public:
    int findRepeatNumber(vector<int>& A) {
        int r = 0;
        int a = 0, b = 0;
        for (auto e : A) {
            r ^= e;
        }
        auto idx = lowest_one(r);
        for (auto e : A) {
            if (e & (1 << idx))
                a ^= e;
            else
                b ^= e;
        }
        return
    }
    int lowest_one(int n) {
        if (n & 0x01)
            return 1;
        int r = 1;
        while (!(n & 0x01)) {
            n >>= 1;
            r++;
        }
        return r;
    }
};
int main() {
    Solution so;
    vector<int> A;
    int x;
    while (cin >> x) {
        auto r = so.lowest_one(x);
        cout << x << ":" << r << endl;
    }
    return 0;
}