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
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        return merge(A, B);
    }

    double merge(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        int size = getsize(m, n);
        vector<int> C(size, 0);
        int k = 0, i, j;
        for (i = 0, j = 0; i < m && j < n && k < size;) {
            C[k++] = A[i] < B[j] ? A[i++] : B[j++];
        }
        for (; i < m && k < size;) {
            C[k++] = A[i++];
        }
        for (; j < n && k < size;) {
            C[k++] = B[j++];
        }
        int t = m + n;
        if (t & 0x01) {
            return C.back();
        }
        return C[size - 1] / 2.0 + C[size - 2] / 2.0;
    }
    int getsize(int m, int n) {
        int t = m + n;
        if (t & 0x01) {
            return t / 2 + 1;
        }
        return t / 2 + 1;
    }
};
int main() {
    Solution so;
    vector<int> A, B;
    {
        A = {1, 3};
        B = {2};
        auto r = so.findMedianSortedArrays(A, B);
        cout << r << endl;
    }
    {
        A = {1, 2};
        B = {3, 4};
        auto r = so.findMedianSortedArrays(A, B);
        cout << r << endl;
    }
    return 0;
}