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
    int maxArea(vector<int>& A) {
        int n = A.size();
        int r = 0;
        for(int i = 1 ;i < n; i++ ) {
            int rmax = A[i] ;
            for(int j = i +1; j < n; j++) {
                rmax = max(A[j],rmax);
            }
            int lmax = A[i];
            for(int j = i-1; j >=0 ;--j) {
                lmax = max(A[j],lmax);
            }
            r += min(lmax,rmax) - A[i];
        }
        return r;
    }
};
int main() {
    Solution so;
    vector<int> A ;
    {
        A = {1,8,6,2,5,4,8,3,7};
        auto r = so.maxArea(A);
        cout << r << endl;
    }
    return 0;
}