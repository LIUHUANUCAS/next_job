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
    vector<vector<int>> subsets(vector<int>& A) {
        vector<vector<int>> r;
        vector<int> one;
        r.push_back(one);
        backtracking(A, 0, one, r);
        return r;
    }
    void backtracking(vector<int>& A,
                      int j,
                      vector<int>& one,
                      vector<vector<int>>& r) {
        if (j >= A.size())
            return;
        int n = A.size();
        for (int i = j; i < n; i++) {
            one.push_back(A[i]);
            r.push_back(one);
            backtracking(A, i + 1, one, r);
            one.pop_back();
        }
    }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {1, 2, 3, 4};
        auto r = so.subsets(A);
        printvector(r);
    }
    return 0;
}