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
    int reinitializePermutation(int n) {
        vector<int> per(n, 0);
        for (int i = 0; i < n; i++) {
            per[i] = i;
        }

        vector<int> A(per);
        int i = 1;
        while (1) {
            for (int j = 0; j < n; j++) {
                if (j & 0x01) {
                    A[j] = per[n / 2 + (j - 1) / 2];
                } else {
                    A[j] = per[j / 2];
                }
            }
            if (equal(A)) {
                return i;
            }
            swap(A, per);
            i++;
        }
        return 0;
    }
    int equal(vector<int>& A) {
        int n = A.size();
        for (int i = 0; i < n; i++) {
            if (A[i] != i)
                return 0;
        }
        return 1;
    }
};
int main() {
    Solution so;
    int n;
    {
        n = 6;
        int r = so.reinitializePermutation(n);
        cout << r << endl;
    }
    {
        n = 1000;
        int r = so.reinitializePermutation(n);
        cout << r << endl;
    }
    return 0;
}