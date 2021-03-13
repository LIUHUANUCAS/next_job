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
    int findKthLargest(vector<int>& A, int k) {
        int lo = 0;
        int n = A.size();
        return dfs(A, lo, n, n - k);
        // return dfs(A, lo, n - 1, n - k);
    }
    int dfs(vector<int>& A, int lo, int hi, int k) {
        auto p = partition(A, lo, hi);
        // auto p = partition2(A, lo, hi);
        if (p < k) {
            return dfs(A, p + 1, hi, k);
        } else if (p > k) {
            return dfs(A, lo, p, k);
            // return dfs(A, lo, p - 1, k);
        }
        return A[k];
    }
    int partition(vector<int>& A, int lo, int hi) {
        int p = A[lo];
        int j = lo - 1;
        for (int i = lo; i < hi; i++) {
            if (A[i] <= p) {
                swap(A[i], A[++j]);
            }
        }
        swap(A[lo], A[j]);
        return j;
    }

    int partition2(vector<int>& A, int lo, int hi) {
        int p = A[lo];
        while (lo < hi) {
            while (lo < hi && A[hi] > p) {
                hi--;
            }
            if (lo < hi) {
                A[lo] = A[hi];
                lo++;
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
int main() {
    Solution so;
    vector<int> A;
    int k;
    {
        A = {1, 3, 2};
        k = 2;
        auto r = so.findKthLargest(A, k);
        cout << r << endl;
    }
    return 0;
}