#include <cstdio>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
   public:
    int sumBase(int n, int k) {
        int c = getk(n, k);
        return c;
    }
    int getk(int n, int k) {
        int c = 0;
        while (n) {
            c += n % k;
            n /= k;
        }
        return c;
    }
};
int main() {
    Solution so;
    int n, k;
    {
        n = 34;
        k = 6;
        auto r = so.sumBase(n, k);
        cout << r << endl;
    }

    {
        n = 10;
        k = 10;
        auto r = so.sumBase(n, k);
        cout << r << endl;
    }
    return 0;
}