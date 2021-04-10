
/**
给定排好序的非负整数数组nums，
请在其中找出不大于c的最大值。
A[i] <= c, [2,3,5,x]
A[i] < c, [2,3,5,x]
*/
#include <iostream>
#include <vector>
using namespace std;

int find(vector<int>& A, int c) {
    int n = A.size();
    int lo = 0, hi = n;
    //[lo,hi)
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (c < A[mid]) {  // [lo, mid)
            hi = mid;
        } else if (c > A[mid]) {  // [mid+1,hi)
            lo = mid + 1;
        } else {
            return A[mid];
        }

        // if (c < A[mid]) {  // c < mid [lo, mid)
        //     hi = mid;
        // } else if (c > A[mid]) {  //c >= mid [mid+1,hi) [2,3,3,3,5]
        //     lo = mid + 1;
        // }

        // if (c <= A[mid]) {  // c <= mid [lo, mid)
        //     hi = mid;
        // } else if (c > A[mid]) {  //c > mid [mid,hi) [2,3,3,3,5]
        //     lo = mid;
        // }
    }

    // (lo = hi )
    // if (lo == n)
    //     return -1;
    if (lo == 0) {
        return -1;
    }
    return A[lo - 1];
}
int main() {
    vector<int> A;
    int c;
    {
        A = {2, 3, 5};
        c = 4;
        auto r = find(A, c);
        cout << r << endl;
    }

    {
        A = {2, 3, 5};
        c = 1;
        auto r = find(A, c);
        cout << r << endl;
    }
    {
        A = {2, 3, 5};
        c = 6;
        auto r = find(A, c);
        cout << r << endl;
    }
    {
        A = {2, 3, 5};
        c = 5;
        auto r = find(A, c);
        cout << r << endl;
    }
    {
        A = {2, 3, 5};
        c = 2;
        auto r = find(A, c);
        cout << r << endl;
    }
}
