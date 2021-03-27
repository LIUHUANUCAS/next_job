#include <cstdio>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
   public:
    int majorityElement(vector<int>& A) {
        int n = A.size();
        return dfs(A, 0, n - 1);
    }

    int dfs(vector<int>& A, int lo, int hi) {
        if (lo == hi)
            return A[lo];
        int mid = lo + (hi - lo) / 2;
        int L = dfs(A, lo, mid);
        int R = dfs(A, mid + 1, hi);
        if (L == R) {
            return L;
        }
        int lcount = count(A, lo, hi, L);
        int rcount = count(A, lo, hi, R);
        return lcount > rcount ? L : R;
    }
    int count(vector<int>& A, int lo, int hi, int v) {
        int c = 0;
        for (int i = lo; i <= hi; i++) {
            if (v == A[i])
                c++;
        }
        return c;
    }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {1, 2, 1};
        auto r = so.majorityElement(A);
        cout << r << endl;
    }
    {
        A = {2, 2, 1, 1, 1, 2, 2};
        auto r = so.majorityElement(A);
        cout << r << endl;
    }
    return 0;
}