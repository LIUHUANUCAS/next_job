#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>
#include "../data_type.h"

using namespace std;
class Solution {
   public:
    int findMaxConsecutiveOnes(vector<int>& A) {
        int n = A.size();
        int c = 0;
        int mlen = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] == 0) {
                c = 0;
            } else {
                c++;
                mlen = max(mlen, c);
            }
        }
        return mlen;
    }
};
int main() {
    Solution so;
    vector<int> m;
    m = {1, 0, 1, 1, 0, 1};
    auto r = so.findMaxConsecutiveOnes(m);
    cout << r << endl;
    return 0;
}