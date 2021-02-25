#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
class NumArray {
   public:
    vector<int> sum;
    NumArray(vector<int>& A) {
        sum.push_back(0);
        for (int i = 0; i < A.size(); ++i) {
            sum.push_back(A[i] + sum.back());
        }
    }

    int sumRange(int i, int j) { return sum[j + 1] - sum[i]; }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
int main() {
    // NumArray na;
    return 0;
}