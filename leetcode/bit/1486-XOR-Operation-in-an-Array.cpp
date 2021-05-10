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
    int xorOperation(int n, int start) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int j = start + 2 * i;
            sum ^= j;
        }
        return sum;
    }
};
int main() {
    Solution so;
    int n, start, r;
    {
        n = 5, start = 0;
        r = so.xorOperation(n, start);
        cout << r << endl;
    }
    {
        n = 4, start = 3;
        r = so.xorOperation(n, start);
        cout << r << endl;
    }
    {
        n = 1, start = 7;
        r = so.xorOperation(n, start);
        cout << r << endl;
    }
    {
        n = 10, start = 5;
        r = so.xorOperation(n, start);
        cout << r << endl;
    }
    return 0;
}