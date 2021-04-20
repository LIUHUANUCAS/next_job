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
    bool searchMatrix(vector<vector<int>>& A, int t) {
        return binary_search_matrix(A, t);
        // return row_search(A, t);
    }
    // log(m*n)
    bool binary_search_matrix(vector<vector<int>>& A, int t) {
        int m = A.size(), n = A[0].size();
        int lo = 0, hi = m * n - 1;
        while (lo <= hi) {  // [lo,hi] lo <= hi
            int mid = (lo + hi) / 2;
            int x = mid / n, y = mid % n;
            int z = A[x][y];
            if (t > z) {
                lo = mid + 1;
            } else if (t < z) {
                hi = mid - 1;
            } else {
                return 1;
            }
        }
        return 0;
    }
    // mlog(n)
    bool row_search(vector<vector<int>>& A, int target) {
        int m = A.size(), n = A[0].size();
        for (auto& r : A) {
            if (binary_search(r.begin(), r.end(), target)) {
                return 1;
            }
        }
        return 0;
    }
};
int main() {
    Solution so;

    return 0;
}