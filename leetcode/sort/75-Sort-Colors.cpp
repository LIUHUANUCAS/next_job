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
    void sortColors(vector<int>& A) {
        int n = A.size();
        for (int j = 0, zero = 0; j < n; j++) {
            if (A[j] == 0) {
                swap(A[zero++], A[j]);
            }
        }
        for (int i = n - 1, sec = n - 1; i >= 0; i--) {
            if (A[i] == 2) {
                swap(A[i], A[sec--]);
            }
        }
    }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {2, 0, 2, 1, 1, 0};
        so.sortColors(A);
        printvector<int>(A);
    }
    {
        A = {2, 0, 1};
        so.sortColors(A);
        printvector<int>(A);
    }
    return 0;
}