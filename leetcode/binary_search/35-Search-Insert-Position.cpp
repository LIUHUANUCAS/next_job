#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
   public:
    int searchInsert(vector<int>& A, int target) {
        return lower_bound(A, target);
    }
    int lower_bound(vector<int>& A, int x) {
        int lo = 0, hi = A.size();
        while (lo < hi) {
            auto mid = lo + (hi - lo) / 2;
            if (x > A[mid]) {
                lo = mid + 1;
            } else if (x < A[mid]) {
                hi = mid;
            } else if (x == A[mid]) {
                hi = mid;
            }
        }
        return lo;
    }
};
int main() {
    Solution so;
    vector<int> m = {1, 3, 5, 6};
    int target = 5;
    auto r = so.searchInsert(m, target);
    cout << r << endl;
    return 0;
}