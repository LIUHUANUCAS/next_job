#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>
// #include "../data_type.h"

using namespace std;
class Solution {
   public:
    int trap(vector<int>& height) {
        // return bf_trap(height);
        return memo_trap(height);
    }
    int memo_trap(vector<int>& A) {
        int n = A.size();
        int res = 0;
        vector<int> lvec(n, 0), rvec(n, 0);
        rvec[n - 1] = A[n - 1];
        lvec[0] = A[0];
        for (int i = n - 2; i >= 0; --i) {
            rvec[i] = max(A[i], rvec[i + 1]);
        }
        for (int i = 1; i < n; ++i) {
            lvec[i] = max(A[i], lvec[i - 1]);
        }
        for (int i = 1; i < n; ++i) {
            auto h = min(lvec[i], rvec[i]) - A[i];
            res += h;
        }
        return res;
    }
    // water_i = min(左边最高，右边最高) - height[i]
    int bf_trap(vector<int>& A) {
        int n = A.size();
        int res = 0;
        for (int i = 1; i < n; ++i) {
            int l_max = 0, r_max = 0;

            for (int j = i; j >= 0; --j) {
                l_max = max(l_max, A[j]);
            }

            for (int j = i; j < n; ++j) {
                r_max = max(r_max, A[j]);
            }
            auto h = min(l_max, r_max) - A[i];
            res += h;
        }
        return res;
    }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        auto r = so.trap(A);
        cout << r << endl;
    }
    {
        A = {4, 2, 0, 3, 2, 5};
        auto r = so.trap(A);
        cout << r << endl;
    }
    return 0;
}