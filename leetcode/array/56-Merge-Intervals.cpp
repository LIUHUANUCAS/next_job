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
    vector<vector<int>> merge(vector<vector<int>>& A) {
        sort(A.begin(), A.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
             });

        vector<vector<int>> res;
        int n = A.size(), end = 0;
        for (int i = 0; i < n; i++) {
            if (res.empty()) {
                res.push_back(A[i]);
            } else {
                // [a,b] union [c,d]
                // a ==c ,end = max(b,c) [a,end]
                // c < b < d ,end = d [a,end]
                //  b <  c  < d ,end =  [a,d]
                int a = res.back()[0];
                int b = res.back()[1];
                int c = A[i][0], d = A[i][1];
                if (a == c) {
                    end = max(b, d);
                    res.back()[1] = end;
                } else if (c <= b && b <= d) {
                    end = d;
                    res.back()[1] = end;
                } else if (c > b) {
                    res.push_back(A[i]);
                }
            }
        }
        return res;
    }
};
int main() {
    Solution so;
    vector<vector<int>> A;
    {
        A = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
        auto r = so.merge(A);
        printvector(r);
    }

    {
        A = {{1, 4}, {4, 5}};
        auto r = so.merge(A);
        printvector(r);
    }
    {
        A = {{1, 4}, {1, 5}};
        auto r = so.merge(A);
        printvector(r);
    }
    return 0;
}