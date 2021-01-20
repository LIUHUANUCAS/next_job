#include <cstdio>
#include <iostream>
#include <random>
#include <unordered_map>
#include <vector>

using namespace std;
int ver;
// The API isBadVersion is defined for you.
bool isBadVersion(int version) {
    return ver == version;
    // return rand() % 100 < 10;
}

class Solution {
   public:
    int firstBadVersion(int n) {
        int lo = 0, hi = n;
        while (lo < hi) {
            auto mid = lo + (hi - lo) / 2;
            auto bad = isBadVersion(mid);
            if (!bad) {
                lo = mid + 1;  // mid is not bad ,so first bad in [mid+1,hi)
            } else {
                hi = mid;  // bad in [lo,mid) if mid is bad, finaly (mid,mid);
            }
        }
        return hi;
    }
};

struct Data {
    int ver;
    int n;
};
int main() {
    Solution so;
    int n;
    n = 100;
    vector<Data> d = {{10, 100}, {10, 3000}, {2147483647, 2147483647}};
    for (auto e : d) {
        ver = e.ver;
        auto r = so.firstBadVersion(e.n);
        cout << r << endl;
    }
    return 0;
}