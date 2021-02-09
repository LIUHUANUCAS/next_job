#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>
// #include "../data_type.h"

using namespace std;
class Solution {
   public:
    int majorityElement(vector<int>& A) {
        int n = A.size();
        int c = 1;
        int ele = A[0];
        for (int i = 1; i < n; ++i) {
            if (A[i] == ele) {
                c++;
            } else {
                if (--c == 0) {
                    ele = A[i];
                    c = 1;
                }
            }
        }
        return ele;
    }
};
int main() {
    Solution so;
    vector<int> A;
    A = {2, 2, 1, 1, 1, 2, 2};
    auto r = so.majorityElement(A);
    cout << "r:" << r << endl;
    return 0;
}