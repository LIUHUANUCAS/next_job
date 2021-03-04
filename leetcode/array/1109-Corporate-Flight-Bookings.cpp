#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>
#include "../data_type.h"

using namespace std;
struct Difference {
    vector<int> d;
    Difference(vector<int>& A) {
        int n = A.size();
        d = vector<int>(n, 0);
        d[0] = A[0];
        for (int i = 1; i < n; ++i) {
            d[i] = A[i] - A[i - 1];
        }
    }
    void increment(int i, int j, int val) {
        d[i] += val;
        if (j + 1 < d.size()) {
            d[j + 1] -= val;
        }
    }
    vector<int> result() {
        vector<int> res(d.size(), 0);
        res[0] = d[0];
        for (int j = 1; j < d.size(); j++) {
            res[j] = res[j - 1] + d[j];
        }
        return res;
    }
};

class Solution {
   public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> A(n, 0);
        Difference d(A);
        for (auto& r : bookings) {
            int i = r[0] - 1;
            int j = r[1] - 1;
            d.increment(i, j, r[2]);
        }
        return d.result();
    }
    vector<int> corpFlightBookings2(vector<vector<int>>& bookings, int n) {
        vector<int> d(n, 0);
        for (auto& r : bookings) {
            int i = r[0] - 1;
            int j = r[1] - 1;
            d[i] += r[2];
            if (j + 1 < n) {
                d[j + 1] -= r[2];
            }
        }
        vector<int> res(n);
        res[0] = d[0];
        for (int i = 1; i < n; i++) {
            res[i] = d[i] + res[i - 1];
        }
        return res;
    }
};
int main() {
    Solution so;
    vector<vector<int>> A;
    int n;
    {
        A = {{1, 2, 10}, {2, 3, 20}, {2, 5, 25}};
        n = 5;
        auto r = so.corpFlightBookings(A, n);
        printvector<int>(r);
    }

    return 0;
}