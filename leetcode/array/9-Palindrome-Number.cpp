#include <cstdio>
#include <iostream>
#include <map>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

#include "../data_type.h"

using namespace std;
class Solution {
   public:
    bool isPalindrome(int x) {
        if (x < 0)
            return 0;
        vector<int> A;
        while (x) {
            A.push_back(x % 10);
            x /= 10;
        }
        return palindrome(A);
    }
    int palindrome(vector<int>& A) {
        int lo = 0, hi = A.size() - 1;
        while (lo < hi) {
            if (A[lo++] != A[hi--])
                return 0;
        }
        return 1;
    }
};
int main() {
    Solution so;
    int n, r;
    {
        n = -121;
        r = so.isPalindrome(n);
        cout << r << endl;
    }
    {
        n = 121;
        r = so.isPalindrome(n);
        cout << r << endl;
    }
    return 0;
}