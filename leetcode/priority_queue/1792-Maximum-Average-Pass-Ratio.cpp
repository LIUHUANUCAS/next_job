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
    double maxAverageRatio(vector<vector<int>>& A, int x) {
        int n = A.size();
        auto f = [&](const int i, const int j) {
            return compare(A[i][0], A[i][1]) < compare(A[j][0], A[j][1]);
        };
        priority_queue<int, vector<int>, decltype(f)> que(f);
        for (int i = 0; i < n; i++) {
            que.push(i);
        }
        for (int i = 1; i <= x; i++) {
            auto j = que.top();
            A[j][0] += 1;
            A[j][1] += 1;
            que.pop();
            que.push(j);
        }
        double s = 0;
        while (!que.empty()) {
            auto j = que.top();
            s += getratio(A[j][0], A[j][1]);
            que.pop();
        }
        return s / n;
    }
    double compare(int a, int b) {
        return getratio(a + 1, b + 1) - getratio(a, b);
    }
    double getratio(int a, int b) { return double(a) / b; }
};
int main() {
    Solution so;
    vector<vector<int>> A;
    int k;
    {
        A = {{1, 2}, {3, 5}, {2, 2}};
        k = 2;
        auto r = so.maxAverageRatio(A, k);
        cout << r << endl;
    }

    {
        A = {{2, 4}, {3, 9}, {4, 5}, {2, 10}};
        k = 4;
        auto r = so.maxAverageRatio(A, k);
        cout << r << endl;
    }
    return 0;
}