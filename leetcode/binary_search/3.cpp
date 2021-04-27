#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
   public:
    const int N = 1e9 + 7;
    int minAbsoluteSumDiff(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += abs(A[i] - B[i]);
        }
        int res = sum;
        vector<int> C(A);
        sort(C.begin(), C.end());

        for (int i = 0; i < n; i++) {
            int z = 0;
            int d = sum;
            auto lo = lower_bound(C.begin(), C.end(), B[i]);
            if (*lo == B[i]) {
                z = 0;
            } else {
                auto hi = upper_bound(C.begin(), C.end(), B[i]);
                int x = B[i];
                if (hi == C.begin()) {
                    x = C[0];
                } else if (hi == C.end()) {
                    // hi = hi - 1;
                    x = C.back();
                } else {
                    x = *hi;
                }
                z = min(abs(*lo - B[i]), abs(x - B[i]));
            }

            d -= abs(A[i] - B[i]);
            d += z;
            res = min(res, d);
        }
        return res % N;
    }
};
int main() {
    Solution so;
    vector<int> A, B;
    {
        A = {56, 51, 39, 1,  12, 14, 58, 82, 18, 41, 70, 64, 18, 7,  44, 90, 55,
             23, 11, 79, 59, 76, 67, 92, 60, 80, 57, 11, 66, 32, 76, 73, 35, 65,
             55, 37, 38, 26, 4,  7,  64, 84, 98, 61, 78, 1,  80, 33, 5,  66, 32,
             30, 52, 29, 41, 2,  21, 83, 30, 35, 21, 30, 13, 26, 36, 93, 81, 41,
             98, 23, 20, 19, 45, 52, 25, 51, 52, 24, 2,  45, 21, 97, 11, 92, 28,
             37, 58, 29, 5,  18, 98, 94, 86, 65, 88, 8,  75, 12, 9,  66};

        B = {64, 32, 98, 65, 67, 40, 71,  93, 74, 24, 49, 80, 98, 35, 86,
             52, 99, 65, 15, 92, 83, 84,  80, 71, 46, 11, 26, 70, 80, 2,
             81, 57, 97, 12, 68, 10, 49,  80, 24, 18, 45, 72, 33, 94, 60,
             5,  94, 99, 14, 41, 25, 83,  77, 67, 49, 70, 94, 83, 55, 17,
             61, 44, 50, 62, 3,  36, 67,  10, 2,  39, 53, 62, 44, 72, 66,
             7,  3,  6,  80, 38, 43, 100, 17, 25, 24, 78, 8,  4,  36, 86,
             9,  68, 99, 64, 65, 15, 42,  59, 79, 66};
        auto r = so.minAbsoluteSumDiff(A, B);
        cout << r << endl;
    }
    return 0;
}