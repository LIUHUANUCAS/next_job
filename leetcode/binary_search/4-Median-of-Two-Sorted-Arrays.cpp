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
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {}
    double dfs(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        int i, j;
    }
};
int main() {
    Solution so;
    vector<int> A, B;
    {
        A = {1, 2, 3};
        B = {4, 5, 6};
        auto r = so.findMedianSortedArrays(A, B);
        cout << r << endl;
    }
    return 0;
}