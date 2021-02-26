#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>
#include "../data_type.h"

using namespace std;
class Solution {
   public:
    int removeElement(vector<int>& A, int val) {
        return remove(A, val);
        int n = A.size();
        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] != val) {
                A[j++] = A[i];
            }
        }
        return j;
    }
    // less swap
    int remove(vector<int>& A, int val) {
        int n = A.size();
        for (int i = 0; i < n;) {
            if (A[i] == val) {
                A[i] = A[n - 1];
                n--;
            } else {
                i++;
            }
        }
        return n;
    }
};
int main() {
    Solution so;
    vector<int> A;
    int val;
    {
        A = {3, 2, 2, 3};
        val = 3;
        auto r = so.removeElement(A, val);
        cout << r << ":2" << endl;
    }
    {
        A = {0, 1, 2, 2, 3, 0, 4, 2};
        val = 2;
        auto r = so.removeElement(A, val);
        cout << r << ":5" << endl;
    }
    return 0;
}