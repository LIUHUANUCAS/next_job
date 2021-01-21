#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>
#include "../data_type.h"

using namespace std;
class Solution {
   public:
    void moveZeroes(vector<int>& A) {
        int n = A.size();
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] != 0) {
                swap(A[j++], A[i]);
            }
        }
    }
};
int main() {
    Solution so;
    vector<int> m;
    m = {0, 1, 0, 3, 12};
    printvector(m);
    so.moveZeroes(m);
    printvector(m);
    return 0;
}