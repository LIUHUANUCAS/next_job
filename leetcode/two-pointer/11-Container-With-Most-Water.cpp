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
    int maxArea(vector<int>& A) {
        int n = A.size();
        int lo = 0, hi = n - 1;
        int r = 0;
        while (lo < hi) {
            r = max(r, min(A[lo], A[hi]) * (hi - lo));
            if (A[lo] < A[hi]) {
                lo++;
            } else {
                hi--;
            }
        }
        return r;
    }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        auto r = so.maxArea(A);
        cout << r << endl;
    }
    return 0;
}