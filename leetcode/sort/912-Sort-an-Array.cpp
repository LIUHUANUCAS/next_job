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
    vector<int> sortArray(vector<int>& A) {
        // sort(A.begin(),A.end());
        qsort(A, 0, A.size() - 1);
        return A;
    }
    void qsort(vector<int>& A, int lo, int hi) {
        if (lo >= hi)
            return;
        auto p = partition(A, lo, hi);
        qsort(A, lo, p - 1);
        qsort(A, p + 1, hi);
    }
    int partition(vector<int>& A, int lo, int hi) {
        int p = A[lo];
        while (lo < hi) {
            while (lo < hi && A[hi] > p) {
                hi--;
            }
            if (lo < hi) {
                A[lo++] = A[hi];
            }
            while (lo < hi && A[lo] <= p) {
                lo++;
            }
            if (lo < hi) {
                A[hi] = A[lo];
                hi--;
            }
        }
        A[lo] = p;
        return lo;
    }
};
using namespace std;

int main() {
    Solution so;
    vector<int> A;
    {
        A = {1, 3, 1, 2, 2, 1, 0};
        so.sortArray(A);
        printvector<int>(A);
    }
    {
        A = {1, 1, 1, 2, 1, 1, 1};
        so.sortArray(A);
        printvector<int>(A);
    }
    return 0;
}